import onnx
import os
import sys
import numpy as np
import onnx_graphsurgeon as gs
from torch import nn
import torch
from itertools import accumulate

class Conv(nn.Module):
    def __init__(self,input_channels = 3, output_channels = 32, padding = (0, 0), dilations = (1, 1), stride = (2, 2), kernel = (3, 3)):
        super().__init__()
        self.conv = nn.Conv2d(in_channels = input_channels, out_channels = output_channels, kernel_size = kernel, stride=stride, padding = padding, dilation = dilations)
        self.relu = nn.ReLU()
    def forward(self, x):
        x = self.conv(x)
        x = self.relu(x)
        return x

file_name = sys.argv[1]
original_model = onnx.load(file_name)
graph = gs.import_onnx(original_model)

#opList = ["Conv","Relu","MaxPool","Concat"]
opList = ["Conv"]

op_cnt = 0
model_dir = sys.argv[2]

if not os.path.exists(model_dir):
    os.makedirs(model_dir)

for node in graph.nodes:
    if node.op in opList:
        #print(node)    
        print("Op: ",node.op)
        print("\tName: ",node.name)
        print("\tInput Shape:",node.inputs[0].shape)
        if len(node.inputs) > 1:
            print("\tKernel/Filter Shape: ",node.inputs[1].shape)
        if len(node.inputs) > 2:
            print("\tBias: ",node.inputs[2].shape)
        print("\tOutput Shape:",node.outputs[0].shape)

        attributeList = []
        # list of length in which we have to split 
        length_to_split = [2, 2] 
        if node.attrs:
            ordDict = node.attrs
            for key, value in ordDict.items():
                print("\t",key,": ",value)
                attributeList.append(value)

        #print(attributeList)
        pad_input = attributeList[3]
        pad_output = [pad_input[x - y: x] for x, y in zip(accumulate(length_to_split), length_to_split)]         
        pad_output = (tuple(sub) for sub in pad_output)
        attributeList[3] = pad_output
        attributeList[1] = [attributeList[1]]
        attributeList = tuple(tuple(sub) for sub in attributeList)

        op_cnt+=1

        #define the input
        in_tensor = torch.randn(node.inputs[0].shape)

        #create conv class object        
        conv2d = Conv(input_channels=node.inputs[0].shape[1], output_channels = node.outputs[0].shape[1], padding = attributeList[3][0], dilations = attributeList[0], stride = attributeList[4], kernel = attributeList[2])
        #call conv class to create custom model
        conv_output = conv2d(in_tensor)

        node_dir =  str(model_dir + "/" + node.name)
        os.makedirs(node_dir)
        #print(node_dir)
        onnx_file = node.name + "_" + "x".join(str(i) for i in node.inputs[0].shape) + "_" + "x".join(str(i) for i in node.outputs[0].shape) +  "_" + "x".join(str(i) for i in attributeList[2]) + "_" + str(attributeList[3][0][0]) + "_" + "x".join(str(i) for i in attributeList[4]) + ".onnx" 
        outfile_path = str(node_dir + "/" + onnx_file)
        #print(outfile_path)
        torch.onnx.export(conv2d,in_tensor,outfile_path,export_params=True,opset_version=14,do_constant_folding=True,input_names=['input'],output_names=['output'])

        onnx.save(onnx.shape_inference.infer_shapes(onnx.load(outfile_path)),outfile_path)

        print("Generated Conv ONNX with above input/ouput & attributes.\n")

print("No. of Ops Processed: ",op_cnt)
