import torch
from tqdm import tqdm 
import torchvision.models as models

def load_pytorch_model(model_name):
    switcher = {
        "AlexNet": lambda: models.alexnet(pretrained=True),
        "ResNet": lambda: models.resnet50(pretrained=True),
        "ResNet18": lambda: models.resnet18(pretrained=True),
        "ResNeXt": lambda: models.resnext50_32x4d(pretrained=True),
        "GoogLeNet": lambda: models.googlenet(pretrained=True),
        "DeepLabV3": lambda: models.segmentation.deeplabv3_mobilenet_v3_large(pretrained=True),
        "FCN": lambda: models.segmentation.fcn_resnet50(pretrained=True),
        "LRASPP": lambda: models.segmentation.lraspp_mobilenet_v3_large(pretrained=True),
        "EfficientNet_b0": lambda: models.efficientnet_b0(pretrained=True),
        "EfficientNet_b1": lambda: models.efficientnet_b1(pretrained=True),
        "EfficientNet_b2": lambda: models.efficientnet_b2(pretrained=True),
        "EfficientNet_b3": lambda: models.efficientnet_b3(pretrained=True),
        "EfficientNet_b4": lambda: models.efficientnet_b4(pretrained=True),
        "EfficientNet_b5": lambda: models.efficientnet_b5(pretrained=True),
        "EfficientNet_b6": lambda: models.efficientnet_b6(pretrained=True),
        "EfficientNet_b7": lambda: models.efficientnet_b7(pretrained=True),
        "EfficientNet_v2_l": lambda: models.efficientnet_v2_l(pretrained=True),
        "EfficientNet_v2_m": lambda: models.efficientnet_v2_m(pretrained=True),
        "EfficientNet_v2_s": lambda: models.efficientnet_v2_s(pretrained=True),
        "MNASNet": lambda: models.mnasnet0_5(pretrained=True),
        "MobileNetV2": lambda: models.mobilenet_v2(pretrained=True),
        "MobileNetV3": lambda: models.mobilenet_v3_small(pretrained=True),
        "ShuffleNetV2": lambda: models.shufflenet_v2_x0_5(pretrained=True),
        "ShuffleNet_v2_x0_5": lambda: models.shufflenet_v2_x0_5(pretrained=True),
        "ShuffleNet_v2_x1_0": lambda: models.shufflenet_v2_x1_0(pretrained=True),
        "ShuffleNet_v2_x1_5": lambda: models.shufflenet_v2_x1_5(pretrained=True),
        "ShuffleNet_v2_x2_0": lambda: models.shufflenet_v2_x2_0(pretrained=True),
        "SqueezeNet": lambda: models.squeezenet1_0(pretrained=True),
        "WideResNet": lambda: models.wide_resnet50_2(pretrained=True),
        "VGG11": lambda: models.vgg11(pretrained=True),
        "VGG13": lambda: models.vgg13(pretrained=True),
        "VGG16": lambda: models.vgg16(pretrained=True),
        "VGG19": lambda: models.vgg19(pretrained=True),
        "VGG11_bn": lambda: models.vgg11_bn(pretrained=True),
        "VGG13_bn": lambda: models.vgg13_bn(pretrained=True),
        "VGG16_bn": lambda: models.vgg16_bn(pretrained=True),
        "VGG19_bn": lambda: models.vgg19_bn(pretrained=True),
        "ConvNeXt": lambda: models.convnext_base(pretrained=True),
        "DenseNet121": lambda: models.densenet121(pretrained=True),
        "DenseNet161": lambda: models.densenet161(pretrained=True),
        "DenseNet169": lambda: models.densenet169(pretrained=True),
        "DenseNet201": lambda: models.densenet201(pretrained=True),
        "FasterRCNN": lambda: models.detection.fasterrcnn_resnet50_fpn(pretrained=True),
        "FCOS": lambda: models.detection.fcos_resnet50_fpn(pretrained=True),
        "KeypointRCNN": lambda: models.detection.keypointrcnn_resnet50_fpn(pretrained=True),
        "MaskRCNN": lambda: models.detection.maskrcnn_resnet50_fpn(pretrained=True),
        "RetinaNet": lambda: models.detection.retinanet_resnet50_fpn(pretrained=True),
        "SSD300": lambda: models.detection.ssd300_vgg16(pretrained=True),
        "SSDLite320": lambda: models.detection.ssdlite320_mobilenet_v3_large(pretrained=True),
        "DeepLabV3": lambda: models.segmentation.deeplabv3_resnet50(pretrained=True),
        "FCN": lambda: models.segmentation.fcn_resnet50(pretrained=True),
        "LRASPP": lambda: models.segmentation.lraspp_mobilenet_v3_large(pretrained=True),
        "VideoResNet": lambda: models.video.r3d_18(pretrained=True),
        "MVit": lambda: models.video.mvit_v1_b(pretrained=True),
        "RAFT": lambda: models.optical_flow.raft_small(pretrained=True),
        "RegNet": lambda: models.regnet_x_400mf(pretrained=True),
    }
    if model_name in switcher.keys():
        _load_model = switcher.get(model_name, None)
        _model = _load_model()
        return _model
    else:
        return -1


class AverageMeter(object):
    """Computes and stores the average and current value"""
    def __init__(self, name, fmt=':f'):
        self.name = name
        self.fmt = fmt
        self.reset()
    def reset(self):
        self.val = 0
        self.avg = 0
        self.sum = 0
        self.count = 0
    def update(self, val, n=1):
        self.sum += val * n
        self.val = val
        self.count += n
        self.avg = self.sum / self.count
    def __str__(self):
        fmtstr = '{name} {val' + self.fmt + '} ({avg' + self.fmt + '})'
        return fmtstr.format(**self.__dict__)


def accuracy(output, target, topk=(1,)):
    """Computes the accuracy over the k top predictions
    for the specified values of k"""
    with torch.no_grad():
        maxk = max(topk)
        batch_size = target.size(0)
        _, pred = output.topk(maxk, 1, True, True)
        pred = pred.t()
        correct = pred.eq(target.view(1, -1).expand_as(pred))
        res = []
        for k in topk:
            correct_k = correct[:k].flatten().float().sum(0, keepdim=True)
            res.append(correct_k.mul_(100.0 / batch_size))
        return res

def evaluate(model, no_tail, loader):
    model.eval()
    top1 = AverageMeter('Acc@1', ':6.2f')
    top5 = AverageMeter('Acc@5', ':6.2f')
    total = 0
    print("Evaluating model...")
    with torch.no_grad():
        for iteraction, (images, labels) in enumerate(tqdm(loader)):
            outputs = model(images)
            total += images.size(0)
            if no_tail:
                return
            acc1, acc5 = accuracy(outputs, labels, topk=(1, 5))
            top1.update(acc1[0], images.size(0))
            top5.update(acc5[0], images.size(0))
    return top1.avg, top5.avg

