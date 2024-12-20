import datetime
import os
import time
import warnings

import presets
import torch
import torch.utils.data
import torchvision
import utils
from coco_utils import get_coco
from torch import nn, Tensor
#from torch.optim.lr_scheduler import PolynomialLR
from torchvision.transforms import functional as F, InterpolationMode

from torchvision.models.segmentation import deeplabv3_resnet50

from pytorch_nndct.apis import torch_quantizer, Inspector
def get_dataset(dir_path, name, image_set, transform):
    def sbd(*args, **kwargs):
        return torchvision.datasets.SBDataset(*args, mode="segmentation", **kwargs)

    paths = {
        "voc": (dir_path, torchvision.datasets.VOCSegmentation, 21),
        "voc_aug": (dir_path, sbd, 21),
        "coco": (dir_path, get_coco, 21),
    }
    p, ds_fn, num_classes = paths[name]

    ds = ds_fn(p, image_set=image_set, transforms=transform)
    return ds, num_classes


def get_transform(train, args):
    if train:
        return presets.SegmentationPresetTrain(base_size=520, crop_size=480)
    elif args.weights and args.test_only:
        weights = torchvision.models.get_weight(args.weights)
        trans = weights.transforms()
        
        def preprocessing(img, target):
            img = trans(img)
            size = F.get_dimensions(img)[1:]
            target = F.resize(target, size, interpolation=InterpolationMode.NEAREST)
            return img, F.pil_to_tensor(target)
                
        return preprocessing
    else:
        return presets.SegmentationPresetEval(base_size=520)


def criterion(inputs, target):
    losses = {}
    for name, x in inputs.items():
        losses[name] = nn.functional.cross_entropy(x, target, ignore_index=255)

    if len(losses) == 1:
        return losses["out"]

    return losses["out"] + 0.5 * losses["aux"]


def evaluate(model, data_loader, device, num_classes):
    model.eval()
    confmat = utils.ConfusionMatrix(num_classes)
    metric_logger = utils.MetricLogger(delimiter="  ")
    header = "Test:"
    num_processed_samples = 0
    with torch.inference_mode():
        for image, target in metric_logger.log_every(data_loader, 100, header):
            image, target = image.to(device), target.to(device)
            output = model(image)
            #print("output from evaluate",output) 
            #print("output type is ",type(output))
            output = output["out"]
            
            confmat.update(target.flatten(), output.argmax(1).flatten())
            # FIXME need to take into account that the datasets
            # could have been padded in distributed setup
            num_processed_samples += image.shape[0]

        confmat.reduce_from_all_processes()

    num_processed_samples = utils.reduce_across_processes(num_processed_samples)
    if (
        hasattr(data_loader.dataset, "__len__")
        and len(data_loader.dataset) != num_processed_samples
        and torch.distributed.get_rank() == 0
    ):
        # See FIXME above
        warnings.warn(
            f"It looks like the dataset has {len(data_loader.dataset)} samples, but {num_processed_samples} "
            "samples were used for the validation, which might bias the results. "
            "Try adjusting the batch size and / or the world size. "
            "Setting the world size to 1 is always a safe bet."
        )

    return confmat


def train_one_epoch(model, criterion, optimizer, data_loader, lr_scheduler, device, epoch, print_freq, scaler=None):
    model.train()
    metric_logger = utils.MetricLogger(delimiter="  ")
    metric_logger.add_meter("lr", utils.SmoothedValue(window_size=1, fmt="{value}"))
    header = f"Epoch: [{epoch}]"
    for image, target in metric_logger.log_every(data_loader, print_freq, header):
        image, target = image.to(device), target.to(device)
        with torch.cuda.amp.autocast(enabled=scaler is not None):
            output = model(image)
            loss = criterion(output, target)

        optimizer.zero_grad()
        if scaler is not None:
            scaler.scale(loss).backward()
            scaler.step(optimizer)
            scaler.update()
        else:
            loss.backward()
            optimizer.step()

        lr_scheduler.step()

        metric_logger.update(loss=loss.item(), lr=optimizer.param_groups[0]["lr"])

def dict_to_tuple(out_dict):
    #if "masks" in out_dict.keys():
    #    return out_dict["boxes"], out_dict["scores"], out_dict["labels"], out_dict["masks"]
    #return out_dict["boxes"], out_dict["scores"], out_dict["labels"]
    return out_dict["out"], out_dict["aux"]

def tuple_to_list_dict(out_tuple, image_size):
    group = len(out_tuple) // image_size
    '''
    results = []
    for i in range(0, len(out_tuple), group):
        out_dict = {}
        out_dict["out"] = out_tuple[i]
        out_dict["aux"] = out_tuple[i + 1]
        results.append(out_dict)
    print("Tuple_to_list_dict",results)
    '''

    out_dict = {}
    out_dict["out"] = out_tuple[0]
    out_dict["aux"] = out_tuple[1]
    results = out_dict
    return results

class DetectWrapper(torch.nn.Module):
    """
    DetectWrapper is used to recover tuple output to dict output for postporcess
    """
    def __init__(self, model):
        super().__init__()
        self.model = model

    def forward(self, inp):
        outs = self.model(inp)
        #print("DetectWrapper",outs)
        #print("DetectWrapper type",type(outs))
        results = tuple_to_list_dict(outs, len(inp))
        #print("results from DetectWrapper",results)
        return results

class TraceWrapper(torch.nn.Module):
    """
    TraceWrapper is used to adapat dict output to tuple output 
    """
    def __init__(self, model):
        super().__init__()
        self.model = model

    def forward(self, inp):
        outs = self.model(inp)
        #print("TraceWrapper ",outs)
        #print("TraceWrapper type",type(outs))
        results = []
        #for out in outs:
        results.extend(dict_to_tuple(outs))
        #print("Result",results)
        return results

def main(args):
    if args.output_dir:
        utils.mkdir(args.output_dir)

    utils.init_distributed_mode(args)
    print(args)

    #device = torch.device(args.device)
    device = torch.device("cuda" if torch.cuda.is_available() else "cpu")

    if args.use_deterministic_algorithms:
        torch.backends.cudnn.benchmark = False
        torch.use_deterministic_algorithms(True)
    else:
        torch.backends.cudnn.benchmark = True

    dataset, num_classes = get_dataset(args.data_path, args.dataset, "train", get_transform(True, args))
    dataset_test, _ = get_dataset(args.data_path, args.dataset, "val", get_transform(False, args))

    if args.distributed:
        train_sampler = torch.utils.data.distributed.DistributedSampler(dataset)
        test_sampler = torch.utils.data.distributed.DistributedSampler(dataset_test, shuffle=False)
    else:
        train_sampler = torch.utils.data.RandomSampler(dataset)
        test_sampler = torch.utils.data.SequentialSampler(dataset_test)

    data_loader = torch.utils.data.DataLoader(
        dataset,
        batch_size=args.batch_size,
        sampler=train_sampler,
        num_workers=args.workers,
        collate_fn=utils.collate_fn,
        drop_last=True,
    )

    data_loader_test = torch.utils.data.DataLoader(
        dataset_test, batch_size=1, sampler=test_sampler, num_workers=args.workers, collate_fn=utils.collate_fn
    )

    print("Len of data_loader_test",len(data_loader_test))
    if args.train:
        model = torchvision.models.get_model(
            args.model,
            weights=args.weights,
            weights_backbone=args.weights_backbone,
            num_classes=num_classes,
         aux_loss=args.aux_loss,
        )
        model.to(device)
        if args.distributed:
            model = torch.nn.SyncBatchNorm.convert_sync_batchnorm(model)

        model_without_ddp = model
        if args.distributed:
            model = torch.nn.parallel.DistributedDataParallel(model, device_ids=[args.gpu])
            model_without_ddp = model.module

        params_to_optimize = [
            {"params": [p for p in model_without_ddp.backbone.parameters() if p.requires_grad]},
            {"params": [p for p in model_without_ddp.classifier.parameters() if p.requires_grad]},
        ]
        if args.aux_loss:
            params = [p for p in model_without_ddp.aux_classifier.parameters() if p.requires_grad]
            params_to_optimize.append({"params": params, "lr": args.lr * 10})
        optimizer = torch.optim.SGD(params_to_optimize, lr=args.lr, momentum=args.momentum, weight_decay=args.weight_decay)

        scaler = torch.cuda.amp.GradScaler() if args.amp else None

        iters_per_epoch = len(data_loader)
        main_lr_scheduler = PolynomialLR(
            optimizer, total_iters=iters_per_epoch * (args.epochs - args.lr_warmup_epochs), power=0.9
        )

        if args.lr_warmup_epochs > 0:
            warmup_iters = iters_per_epoch * args.lr_warmup_epochs
            args.lr_warmup_method = args.lr_warmup_method.lower()
            if args.lr_warmup_method == "linear":
                warmup_lr_scheduler = torch.optim.lr_scheduler.LinearLR(
                    optimizer, start_factor=args.lr_warmup_decay, total_iters=warmup_iters
                )
            elif args.lr_warmup_method == "constant":
                warmup_lr_scheduler = torch.optim.lr_scheduler.ConstantLR(
                    optimizer, factor=args.lr_warmup_decay, total_iters=warmup_iters
                )
            else:
                raise RuntimeError(
                    f"Invalid warmup lr method '{args.lr_warmup_method}'. Only linear and constant are supported."
                )
            lr_scheduler = torch.optim.lr_scheduler.SequentialLR(
                optimizer, schedulers=[warmup_lr_scheduler, main_lr_scheduler], milestones=[warmup_iters]
            )
        else:
            lr_scheduler = main_lr_scheduler

        if args.resume:
            checkpoint = torch.load(args.resume, map_location="cpu")
            model_without_ddp.load_state_dict(checkpoint["model"], strict=not args.test_only)
            if not args.test_only:
                optimizer.load_state_dict(checkpoint["optimizer"])
                lr_scheduler.load_state_dict(checkpoint["lr_scheduler"])
                args.start_epoch = checkpoint["epoch"] + 1
                if args.amp:
                    scaler.load_state_dict(checkpoint["scaler"])

    

    model = deeplabv3_resnet50(weights='DEFAULT', progress=True, num_classes=num_classes, aux_loss=None)

    wrap_model = DetectWrapper(TraceWrapper(model))
    wrap_model.eval()
    wrap_model.to(device)

    # Quantize
    if args.quant_mode in ["float"] and args.inspect:
        dummy_input = torch.randn([args.batch_size,3,520,520]).to(device)
        target = "DPUCAHX8L_ISA0_SP"
        inspector = Inspector(target)
        inspector.inspect(wrap_model.model, (dummy_input),device=device, output_dir=f"{args.model}_inspect")
        import sys
        sys.exit(0)

    if args.quant_mode in ["calib","test"]:
        dummy_input = torch.randn([args.batch_size,3,520,520]).to(device)
        quantizer = torch_quantizer(args.quant_mode, wrap_model.model, input_args=(dummy_input),output_dir=args.quant_dir,device=device)
        wrap_model.model = quantizer.quant_model.to(device)
    model = wrap_model
        

    # calib + test_only for quant
    # test + deploy for deploy
    # test + test_only for eval on quant
    if args.test_only:
        # We disable the cudnn benchmarking because it can noticeably affect the accuracy
        torch.backends.cudnn.benchmark = False
        torch.backends.cudnn.deterministic = True

        if args.quant_mode == "test" and args.deploy:
            batch_iter = iter(data_loader_test)
            images = next(batch_iter)[0]
            model(images)
            quantizer.export_torch_script(args.quant_dir)
            quantizer.export_onnx_model(output_dir=args.quant_dir)
            return

        confmat = evaluate(model, data_loader_test, device=device, num_classes=num_classes)
        if args.quant_mode == "test":
            print("METRIC_LOG:QUANT_MODE")

        print(confmat)

        if args.quant_mode == "calib":
            quantizer.export_quant_config()
        return

        return
    if args.train:
        start_time = time.time()
        for epoch in range(args.start_epoch, args.epochs):
            if args.distributed:
                train_sampler.set_epoch(epoch)
            train_one_epoch(model, criterion, optimizer, data_loader, lr_scheduler, device, epoch, args.print_freq, scaler)
            confmat = evaluate(model, data_loader_test, device=device, num_classes=num_classes)
            print(confmat)
            checkpoint = {
                "model": model_without_ddp.state_dict(),
                "optimizer": optimizer.state_dict(),
                "lr_scheduler": lr_scheduler.state_dict(),
                "epoch": epoch,
                "args": args,
            }
            if args.amp:
                checkpoint["scaler"] = scaler.state_dict()
            utils.save_on_master(checkpoint, os.path.join(args.output_dir, f"model_{epoch}.pth"))
            utils.save_on_master(checkpoint, os.path.join(args.output_dir, "checkpoint.pth"))

        total_time = time.time() - start_time
        total_time_str = str(datetime.timedelta(seconds=int(total_time)))
        print(f"Training time {total_time_str}")


def get_args_parser(add_help=True):
    import argparse

    parser = argparse.ArgumentParser(description="PyTorch Segmentation Training", add_help=add_help)

    parser.add_argument("--data-path", default="/datasets01/COCO/022719/", type=str, help="dataset path")
    parser.add_argument("--dataset", default="coco", type=str, help="dataset name")
    parser.add_argument("--model", default="fcn_resnet101", type=str, help="model name")
    parser.add_argument("--aux-loss", action="store_true", help="auxiliary loss")
    parser.add_argument("--device", default="cuda", type=str, help="device (Use cuda or cpu Default: cuda)")
    parser.add_argument(
        "-b", "--batch-size", default=8, type=int, help="images per gpu, the total batch size is $NGPU x batch_size"
    )
    parser.add_argument("--epochs", default=30, type=int, metavar="N", help="number of total epochs to run")

    parser.add_argument(
        "-j", "--workers", default=16, type=int, metavar="N", help="number of data loading workers (default: 16)"
    )
    parser.add_argument("--lr", default=0.01, type=float, help="initial learning rate")
    parser.add_argument("--momentum", default=0.9, type=float, metavar="M", help="momentum")
    parser.add_argument(
        "--wd",
        "--weight-decay",
        default=1e-4,
        type=float,
        metavar="W",
        help="weight decay (default: 1e-4)",
        dest="weight_decay",
    )
    parser.add_argument("--lr-warmup-epochs", default=0, type=int, help="the number of epochs to warmup (default: 0)")
    parser.add_argument("--lr-warmup-method", default="linear", type=str, help="the warmup method (default: linear)")
    parser.add_argument("--lr-warmup-decay", default=0.01, type=float, help="the decay for lr")
    parser.add_argument("--print-freq", default=10, type=int, help="print frequency")
    parser.add_argument("--output-dir", default=".", type=str, help="path to save outputs")
    parser.add_argument("--quant_dir", default="quant_result", type=str)
    parser.add_argument("--deploy", action="store_true", help="export torch script")
    parser.add_argument("--inspect", action="store_true", help="inspector")
    parser.add_argument("--quant_mode", default="float", type=str,  help="the mode in quantization: float/calib/test")
    parser.add_argument("--resume", default="", type=str, help="path of checkpoint")
    parser.add_argument("--start-epoch", default=0, type=int, metavar="N", help="start epoch")
    parser.add_argument(
        "--test-only",
        dest="test_only",
        help="Only test the model",
        action="store_true",
    )
    parser.add_argument(
        "--use-deterministic-algorithms", action="store_true", help="Forces the use of deterministic algorithms only."
    )
    # distributed training parameters
    parser.add_argument("--world-size", default=1, type=int, help="number of distributed processes")
    parser.add_argument("--dist-url", default="env://", type=str, help="url used to set up distributed training")

    parser.add_argument("--weights", default=None, type=str, help="the weights enum name to load")
    parser.add_argument("--weights-backbone", default=None, type=str, help="the backbone weights enum name to load")

    # Mixed precision training parameters
    parser.add_argument("--amp", action="store_true", help="Use torch.cuda.amp for mixed precision training")

    parser.add_argument("--train", default=False, type=bool, help="Train the Network")

    return parser


if __name__ == "__main__":
    args = get_args_parser().parse_args()
    main(args)
