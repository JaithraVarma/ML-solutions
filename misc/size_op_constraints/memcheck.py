import sys
import onnx
import argparse
import dataclasses
import onnx.helper
import numpy as np
import pandas as pd
from pathlib import Path
from onnx import ModelProto
from typing import Dict, List
from dataclasses import dataclass

from qonnx.core.modelwrapper import ModelWrapper


def load_onnx_model(model_path: Path, update_model: bool = False) -> ModelProto:
    """Loads an onnx model given a path and returns the model.
    Args:
        model_path: onnx model path
        update_model: whether to update the model with the shape inference results.
    Returns:
        onnx model as a protobuf object.
    """
    onnx_model = onnx.load(model_path)
    # annotate the operator shapes
    onnx_model = onnx.shape_inference.infer_shapes(onnx_model)

    if update_model:
        # save onnx model again, with updated shapes
        onnx.save(onnx_model, model_path)

    return onnx_model

# Calculating the product of shapes
def calc(x, sum, loc, file) -> int:
    count = len(x)
    if count == 0:
        file.write("Couldn't retrieve shape at {}\n".format(loc))
        return 0    
    elif count == 1:
        sum += x[0]
    #elif x[0] == 0:
    else:
        temp = 1
        for y in range(count-1):
            #padding for width to be multiple of 16
            if y==2 and x[y+1]%16 != 0:
                pad = x[y+1] + (16 - x[y+1]%16)  #taking y+1 to skip the 0
                temp = temp * pad
            else:
                temp = temp*x[y+1]
        sum += temp

    return sum

# For checking 1.5Mb Constraints
def checkSize(limit, ins, ops, name, loc, file):
    sum = 0
    if name == "Conv" or "Gemm" or "Add" or "BatchNormalization":
        x = ins[0]
        sum = calc(x, sum, loc, file)
    else:
        for x in ins:
            sum = calc(x, sum, loc, file)
    for x in ops:
        sum = calc(x, sum, loc, file)
    #assert sum < 1.5e+6, "Exceeds Size limit at *{}* node number {}".format(name, cnt)
    if sum > limit: 
        file.write("Exceeds Size limit at node {} with size: {} bytes \n".format(loc, sum))
    
    return sum


@dataclass
class Operator:
    """Represents an ONNX operator
    Args:
        count: frequency of the operator
        type: operator type: e.g. Add, Conv...
    """

    op_count: int
    type: str    

def extract_model_info(onnx_model: ModelWrapper, size, prev_op, file, memSizeChk, symPadChk):
    """Create a dataframe containing operator information
    This may include attributes and input/output shapes.
    Args:
        onnx_model: model we are investigating
        size: The size constraint Ex:1500000kb (1.5mb)
        memSizeChk: wether we want to do a size constraint check
        symPadChk: wether we want to do a symmetric padding check
    Returns:
        dataframe containing the list of operators in the model.
    """
    ops: Dict[str, Operator] = {}
    max_size = 0
    node_dict = {}
    ass_pad = []
    grp_conv = {}
    depthwise_conv = {}
    pointwise_conv = {}

    for node in onnx_model.graph.node:

        op = ops.get(
            node.op_type,
            Operator(
                0, node.op_type
            ),
        )
        op.op_count = op.op_count + 1

        input_shapes_list = [
            onnx_model.get_tensor_shape(x)
            for x in node.input
        ]
        output_shapes_list = [
            onnx_model.get_tensor_shape(x)
            for x in node.output
        ]

        # Skip empty nodes
        if not input_shapes_list:
            continue
        if not output_shapes_list:
            continue
        
        # Skip QuantizeLinear and DequantizeLinear
        if node.op_type == "QuantizeLinear" or node.op_type == "DequantizeLinear":
            continue
        
        # creating a dict for node names
        node_name = node.name
        if node.op_type not in node_dict:
            node_dict[node.op_type] = list()
            node_dict[node.op_type].append(node_name)
        else:
            node_dict[node.op_type].append(node_name)

        # Detecting asymmetric padding (asymmetric kernal shape)
        if symPadChk == "True":
            if node.op_type == 'Conv':
                lst = node.attribute[2].ints
                result = all(element == lst[0] for element in lst)
                if (not result):
                    ass_pad.append(node_name)

        # If GROUP CONV or Depthwise CONV then attribute group != 1
        # For depthwise conv kernal shape is (x, 1, x, x) else group conv
        # For pointwise conv kernal shape is (x, x, 1, 1)
        if node.op_type == "Conv":
            group = node.attribute[1].i
            if group != 1:
                if input_shapes_list[1][1] == 1:
                    depthwise_conv[node_name] = group
                else:
                    grp_conv[node_name] = group
            else:
                if input_shapes_list[1][2] == 1 and input_shapes_list[1][3] == 1:
                    pointwise_conv[node_name] = group



        # Checking the 1.5Mb Size Constraints
        # Since conv and relu operator are fused
        if memSizeChk == "True":
            if prev_op == 'Conv' and node.op_type == 'Relu':
                pass
            else:
                size_tst = checkSize(size, input_shapes_list, output_shapes_list, node.op_type, node_name, file)
                if size_tst > max_size:
                    max_size = size_tst
                    max_loc = node_name

        # storing the name of the node to be used during analysis of next node (for chaining)
        prev_op = node.op_type
        ops[node.op_type] = op

    if memSizeChk == 'True':
        file.write("The maximum (input+output) size is at {}: {} bytes\n".format(max_loc, max_size))

    return pd.DataFrame(list(ops.values())), node_dict, ass_pad, grp_conv, depthwise_conv, pointwise_conv    


def main(args: List[str]) -> int:
    parser = argparse.ArgumentParser(
        description="Utility script to generate "
        "information about operators that appear either in torchvision or "
        "given onnx models."
    )
    parser.add_argument(
        "--model", 
        type=str, required=True, 
        help="name of the model to be analysed"
    )
    parser.add_argument(
        "--size",
        type=int, default=1.5e+6,
        help="What is the size constraint ex: 1.5Mb",
    )
    parser.add_argument(
        "--output",
        type=str, default="analysis.txt",
        help="Name of the output file",
    )
    parser.add_argument(
        "--mem_check",
        type=str, default="True",
        help="Size constraints check",
    )
    parser.add_argument(
        "--nop_check",
        type=str, default="True",
        help="New operator check",
    )
    parser.add_argument(
        "--smp_check",
        type=str, default="True",
        help="Symmetric padding check",
    )

    args = parser.parse_args(args)

    model_name = args.model
    onnx_model = "onnx_models/{}.onnx".format(model_name)

    op_table = pd.DataFrame(columns=[x.name for x in dataclasses.fields(Operator)])

    opfile = args.output
    file = open(opfile, 'w+')
    file.write(f"Processing Model: {model_name}\n")
    model = load_onnx_model(onnx_model)

    size = args.size
    memSizeChk = args.mem_check
    symPadChk = args.smp_check

    # prev_op to keep track of previous operator
    prev_op = None
    df, node_dict, ass_pad, grp_conv, depth_conv, point_conv = extract_model_info(ModelWrapper(model), size, prev_op, file, memSizeChk, symPadChk)
    file.write("Memory Constraints check Done!!\n")

    op_table = pd.concat([op_table, df])

    # print nodes with asymmetric padding and different conv
    if len(ass_pad) != 0:
        file.write("Asymmetric padding at:\n {}\n".format(ass_pad))
    if len(grp_conv) != 0:
        file.write("Group Conv (Position : Grp Size) ->\n {}\n".format(grp_conv))
    if len(depth_conv) != 0:
        file.write("Depthwise Conv (Position : Grp Size) ->\n {}\n".format(depth_conv))
    if len(point_conv) != 0:
        file.write("Pointwise Conv (Position : Grp Size) ->\n {}\n".format(point_conv))

    # Checking for operators not supported by FlexML
    newOpChk = args.nop_check
    if newOpChk == "True":
        # supported operator list
        list1 = ['Conv', 'Relu', 'MaxPool', 'LRN', 'Dropout', 'Softmax', 'BatchNormalization']
        # operators present in our model
        ####list2 = op_table["type"]
        list2 = list()
        for i in node_dict:
            list2.append(i)
        # list of supported operators
        sup_op = list(set(list1).intersection(list2))
        # yields the elements in `list2` that are NOT in `sup_op`
        new_op = np.setdiff1d(list2,sup_op)

        file.write('Supported operators in {} -> \n'.format(model_name))
        for p in sup_op: file.write(str(p) + ":\n " + str(node_dict[p]) + "\n")

        if len(new_op) == 0:
            file.write('There are no unsupported operators in {} \n'.format(model_name))
        else:    
            file.write('Unsupported operators in {} -> \n'.format(model_name))
            for p in new_op: file.write(str(p) + ":\n " + str(node_dict[p]) + "\n")

    print('Refer to file ' +str(opfile) + ' for detailed analysis.')
    file.write("\n\n")
    file.close()

    return 0


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))