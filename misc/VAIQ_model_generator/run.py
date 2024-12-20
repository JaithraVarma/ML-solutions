###
# Copyright (C) 2022 Xilinx, Inc
#
# Licensed under the Apache License, Version 2.0 (the "License"). You may
# not use this file except in compliance with the License. A copy of the
# License is located at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS, WITHOUT
# WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the
# License for the specific language governing permissions and limitations
# under the License.
###
import os
import onnx
import glob
import torch
import shutil
import random
import getpass
import argparse
from utils import *
from pathlib import Path
from datetime import datetime
import torchvision.datasets as datasets
import torchvision.transforms as transforms
from pytorch_nndct.apis import torch_quantizer


device = torch.device("cuda" if torch.cuda.is_available() else "cpu")

parser = argparse.ArgumentParser()
parser.add_argument(
    '--config_file',
    default="quant_config.json",
    help='quantization configuration file')
    
parser.add_argument(
    '--no_tail',
    default=False,
    help='wether to deletes layers from end')

parser.add_argument(
    '--lyr_trim',
    default=2,
    help='deletes num of layers from end')

args, _ = parser.parse_known_args()

# Common Configurations for Setup
SCRIPT_PATH = os.getcwd()
config_file = args.config_file
CONFIG_PATH = os.path.join(SCRIPT_PATH, config_file)
TXT_FILE = open('models.txt', 'r')
MODELS = TXT_FILE.read()
MODELS = MODELS.split('\n')
MODELS = [i for i in MODELS if i]
print(f"Running VAIQ on {MODELS}")

calib_data_len = 1000
test_data_len = 1000 

IMAGE_DATA_DIR = "Imagenet"
if not os.path.exists(IMAGE_DATA_DIR):
    raise Exception('Required Imagenet dataset not found in the working directory!!')

# Applying Transforms
normalize = transforms.Normalize(
    mean=[0.485, 0.456, 0.406], std=[0.229, 0.224, 0.225])

# Preparing Dataset
#val_path = args.data_dir

val_path = os.getcwd() + '/Imagenet/val'
dataset = datasets.ImageFolder(val_path,
    transform=transforms.Compose([
        transforms.Resize(256),
        transforms.CenterCrop(224),
        transforms.ToTensor(),
        normalize,
    ]))

calib_dataset = torch.utils.data.Subset(
        dataset, random.sample(range(0, len(dataset)), calib_data_len)
    )
test_dataset = torch.utils.data.Subset(
        dataset, random.sample(range(0, len(dataset)), test_data_len)
    )
# Loading calibration data
calib_loader = torch.utils.data.DataLoader(
    calib_dataset,
    batch_size=32,
    shuffle=False,
    num_workers=1,
    pin_memory=True)

# Loading test data
test_loader = torch.utils.data.DataLoader(
    test_dataset,
    batch_size=32,
    shuffle=False,
    num_workers=1,
    pin_memory=True)

x = torch.randn([32, 3, 224, 224])

# API for running models
def load_model(m):
    model = load_pytorch_model(m)
    if model==-1:
        print('Model name does not exist in the list. please update the utils.py file and try again')
        return -1
    else:
        if args.no_tail == False:
            return model
        else: 
            layer_trim = -1 * args.lyr_trim
            model = torch.nn.Sequential(*(list(model.children())[:layer_trim]))
        return model

def rename_pt(path, m):
    os.chdir(path)
    source_name = glob.glob('*_int.pt')[0]
    source_path = path + '/' + str(source_name)
    target_path = path + '/' + m + '_vaiq.pt'
    shutil.move(source_path, target_path)
    os.chdir('../../')
    return target_path

def make_info_file(file):
    # adding info to _gen.info file 
    timestamp = datetime.now().strftime('%Y-%m-%d %H:%M:%S')
    # Get the Linux user ID name as the username
    username = getpass.getuser()
    dataset = IMAGE_DATA_DIR
    dataset_size = len(next(os.walk(val_path))[1])
    file.write("TimeStamp >> {}\n".format(timestamp))
    file.write("Creator --> {}\n".format(username))
    file.write("Dataset --> {}\n".format(dataset))
    file.write("Dataset Size --> {}\n\n".format(dataset_size))
    return 0

# Main function
def main():
    for m in MODELS:
        if not os.path.exists(m):
            os.makedirs(m)
        os.chdir(m)

        #generate a _gen.info file for all models
        info_filename = str(m)+'_gen.info'
        info_file = open(info_filename, 'w')
        # adding info to _gen.info file 
        try: make_info_file(info_file) 
        except Exception as e: print("Failed to make _gen.info file")
        
        shutil.copy(CONFIG_PATH, os.getcwd())
        output_dir = Path("quantized_" + m + "/int" + str(8))
        if not output_dir.exists():
            os.makedirs(str(output_dir))

        # Load the model
        model = load_model(m)
        if model==-1:
            pass
        else:
            info_file.write('Model being tested: {}\n'.format(str(m)))
            torch.onnx.export(model,               # model being run
                    x,                         # model input (or a tuple for multiple inputs)
                    str(m) + ".onnx",          # where to save the model (can be a file or file-like object)
                    export_params=True,
                    opset_version=11,          # the ONNX version to export the model to
                    do_constant_folding=True,  # whether to execute constant folding for optimization
                    input_names = ['input'],   # the model's input names
                    output_names = ['output']# the model's output names
                    )
            path = str(m) + ".onnx"
            onnx.save(onnx.shape_inference.infer_shapes(onnx.load(path)), path)
            no_tail = args.no_tail
            if not no_tail:
                top_1, top_5 = evaluate(model, no_tail, test_loader)
                info_file.write(f"Original model accuracy results are: top-1 = {top_1} and top_5 = {top_5}\n")
                print("Prediction done!")  
                quantizer = torch_quantizer("calib", model, (x), quant_config_file=config_file, device=torch.device("cpu"))
                print("Created PQT model!")
                top_1, top_5 = evaluate(quantizer.quant_model, no_tail, calib_loader)
                print("Calibration done!")
                quantizer.export_quant_config() # Creates files necessary for loading the model in test mode
                print("Calibration files saved!")
                quantizer = torch_quantizer('test', model, (x), quant_config_file=config_file, device=torch.device("cpu"))      
                top_1, top_5 = evaluate(quantizer.quant_model, no_tail, test_loader)
                info_file.write(f"Quantized model accuracy results are: top-1 = {top_1} and top_5 = {top_5}\n\n")
                print("Prediction done!")
                quantizer.export_traced_torch_script(str(output_dir))
                quantizer.export_onnx_model(os.getcwd())
                print(f"INFO: Quantized TorchScript exported to {output_dir}")
            else:
                quantizer = torch_quantizer("calib", model, (x), quant_config_file=config_file, device=torch.device("cpu"))
                print("Created PQT model!")
                evaluate(quantizer.quant_model, no_tail, calib_loader)
                print("Calibration done!")
                quantizer.export_quant_config() # Creates files necessary for loading the model in test mode
                print("Calibration files saved!")
                quantizer = torch_quantizer('test', model, (x), quant_config_file=config_file, device=torch.device("cpu"))        
                evaluate(quantizer.quant_model, no_tail, test_loader)
                print("Prediction done!")
                quantizer.export_onnx_model(os.getcwd())
            source_name = glob.glob(r'*_int.onnx')
            source_path = os.getcwd() + '/' + str(source_name[0])
            if not no_tail:
                target_path = os.getcwd() + '/' + m + '_vaiq.onnx'
            else:
                target_path = os.getcwd() + '/' + m + '_notail_vaiq.onnx'
            shutil.move(source_path, target_path)
            onnx.checker.check_model(target_path)
            onnx.shape_inference.infer_shapes_path(target_path)
            print("Successfully generated ONNX at: ", target_path)

            # to rename the pt file
            try:
                pt_path = str(os.getcwd())+ '/' + str(output_dir)
                new_target_path = rename_pt(pt_path, m)
                print("Successfully generated pt model at: ", new_target_path)
            except Exception as e:
                print(e)
                pass

        os.chdir(SCRIPT_PATH)

if __name__ == "__main__":
    main()
