import onnx
import json
import argparse
import numpy as np
from pathlib import Path
from onnx import shape_inference
from flexml.flexml_extras.mlir.ir import (
    Context,
    Module,
    OperationList,
)
from flexml.flexml_extras.mlir.dialects.xten_nn import SubgraphOp

def conv_macs(input_shape, output_shape, kernel_shape, groups, op_type):
    kernel_shape= np.array([int(x) for x in kernel_shape])
    input_shape= np.array([int(x) for x in input_shape])
    output_shape= np.array([int(x) for x in output_shape])

    kernel_ops = np.prod(kernel_shape)  # Kw x Kh
    bias_ops = 1 # to consider the baises in the total params as well: total_params * np.prod(output_shape[2:])

    group = int(groups)
    
    # Conditions for both operator
    if op_type == 'Conv':
        mac_count = np.prod(output_shape) * (input_shape[1] // group * kernel_ops + bias_ops)
    else:
        mac_count = np.prod(output_shape) * (output_shape[1] // group * kernel_ops + bias_ops)
    
    return mac_count

def gemm_matmul_mac(input_shape, output_shape, op_type):
    value = np.prod(input_shape) * output_shape[-1]
    bias = np.prod(output_shape)
    mac_count = value if op_type == 'MatMul' else value + bias
    return mac_count

def bn_mac(input_shape, output_shape):
    in_channels = input_shape[1]
    out_channels = output_shape[1]
    mac_count = in_channels + out_channels
    return mac_count

def extract_tensor_shape(model, tensor_name):
    tensor_shape = []
    # Try to find tensor name in value info
    for itm in model.graph.value_info:
        if itm.name == tensor_name:
            if hasattr(itm.type.tensor_type, 'shape'):
                if hasattr(itm.type.tensor_type.shape, 'dim'):
                    tensor_shape = [dim.dim_value for dim in itm.type.tensor_type.shape.dim]
                    break
    # If not found in value info, try to find in input/output
    if not tensor_shape:
        for inp in model.graph.input:
            if inp.name == tensor_name:
                tensor_shape = [dim.dim_value for dim in inp.type.tensor_type.shape.dim]
        for op in model.graph.output:
            if op.name == tensor_name:
                tensor_shape = [dim.dim_value for dim in op.type.tensor_type.shape.dim]
    return tensor_shape

def get_input_output_tensor_shape(model, tensor_names):
    tensor_shapes = []
    for tn in tensor_names:
        tensor_shape = extract_tensor_shape(model, tn)
        if tensor_shape:
            tensor_shapes.append(tensor_shape)
    return tensor_shapes

def get_layers(module: Module) -> OperationList:
    return module.body.operations[0].regions[0].blocks[0].operations

def parse_layers(ir_path: Path):
    out = []
    with Context() as ctx:
        module = Module.parse(ir_path.read_text(), context=ctx)
        # And all the top level operations are InCoreChains
        for incorechain in get_layers(module):
            if isinstance(incorechain, SubgraphOp):
                out.append(
                    incorechain.attributes["LayerName"].value
                    )
    return out

def get_model_mac_count(model, opr_lst, enable_printing=True) -> int:
    total_mac = 0
    for node in model.graph.node:
        if opr_lst and node.name not in opr_lst:
            continue
        if node.op_type in ['Conv', 'ConvTranspose', 'Gemm', 'BatchNormalization', 'MatMul']:
            input_names = node.input
            onnx_input = get_input_output_tensor_shape(model, input_names)
            output_names = node.output
            onnx_output = get_input_output_tensor_shape(model, output_names)
            print(f'\n{node.name}')
            
            if not onnx_input or not onnx_output:
                raise Exception('Error: model not Shape Inferred')
            else:
                onnx_input=onnx_input[0]
                onnx_output=onnx_output[0]

            if node.op_type in ['Conv', 'ConvTranspose']:
                kernel_shape = [attr.ints for attr in node.attribute if attr.name == "kernel_shape"][0]
                try:
                    group = [attr.i for attr in node.attribute if attr.name == "group"][0]
                except:
                    group = 1
                layer_mac = conv_macs(onnx_input, onnx_output, kernel_shape, group, node.op_type)
                if enable_printing:
                   print(f'{node.op_type}:' , layer_mac)

            elif node.op_type in ['Gemm', 'MatMul']:
                layer_mac = gemm_matmul_mac(onnx_input, onnx_output, node.op_type)
                if enable_printing:
                    print(f'{node.op_type}:' , layer_mac)

            elif node.op_type == 'BatchNormalization':
                layer_mac = bn_mac(onnx_input, onnx_output)
                if enable_printing:
                    print('BatchNormalization:' , layer_mac)
                    
            if layer_mac == 0:
                raise Exception('Error: model not Shape Inferred')

            total_mac += layer_mac

    if enable_printing:
        print('\nTotal GMAC: ', total_mac / 1000000000)
    return total_mac


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--onnx', required=True, type=str, help='path to onnx file')
    parser.add_argument(
        '--json', default='NA', type=str, help='path to tensor_dims.json file'
    )
    parser.add_argument(
        '--mlir', default='NA', type=str, help='path to tosa.mlir or dse.mlir file'
    )
    args = parser.parse_args()

    onnx_path = args.onnx
    json_path = args.json
    mlir_path = args.mlir

    if json_path == 'NA' and mlir_path == 'NA':
        opr_lst = False
    elif json_path != 'NA' and mlir_path == 'NA':
        with open(json_path, 'r') as f:
            data = json.load(f)
        opr_lst = list(data.keys())
    else:
        opr_lst = parse_layers(Path(mlir_path))

    model = onnx.load(onnx_path)
    try:
        model = shape_inference.infer_shapes(model, data_prop=True)
    except: 
        pass
    get_model_mac_count(model, opr_lst)


if __name__ == '__main__':
    main()
