import onnx
import onnx_graphsurgeon as gs
import onnx.helper as helper
import onnx.numpy_helper as numpy_helper
import csv

def row_exists(csv_file_path, new_row):
    with open(csv_file_path, mode='r', newline='') as file:
        reader = csv.reader(file)
        for row in reader:
            if row == new_row:
                return True
    return False


def broadcast_op_scalar_check(node, graph):
    if len(node.inputs) < 2:
        return False
    second_input = node.inputs[1]

    for tensor in graph.tensors().values():
        if tensor.name == second_input.name and isinstance(tensor, gs.Constant):
            
            if tensor.values is not None and len(tensor.values.shape) == 0:
                return True  # It is a scalar constant

    return False  # It is a non-scalar constant


def check_kernel_symmetry(node):
    kernel_shape = None
    for attr in node.attrs:
        if attr == 'kernel_shape':
            kernel_shape = node.attrs['kernel_shape']

    if kernel_shape:
        if len(set(kernel_shape)) == 1:
            return True
        else:
            return False

    return None


def conv_2d_check(node):
    if node.op != 'Conv':
        return False

    operator_attributes = node.attrs
    kernel_shape = operator_attributes.get('kernel_shape', None)

    if kernel_shape is not None:
        if len(kernel_shape) == 2:
            return True
        elif len(kernel_shape) == 1:
            return False

    return None

def concat_axis_check(node):
    axis = None
    for attr in node.attrs:
        if attr == 'axis':
            axis = node.attrs['axis']

    if axis:
        if axis == 1:
            return True
        else:
            return False

    return None

def pad_reflect_check(node):
    mode = None
    for attr in node.attrs:
        if attr == 'mode':
            mode = node.attrs['mode']
            # print(mode)
    if mode:
        if mode == 'reflect':
            return True
        else:
            return False
        
    return None

def slice_inc_check(node, csv_file_path, model_name):
    if node.op != 'Slice':
        return False
    
    input_tensor = node.inputs[0]

    if input_tensor.shape is not None:
        try:
            C = input_tensor.shape[1]
        
            if C % 8 == 0:
                return True
        except Exception as e:
            new_row = ['operator_analysis', model_name, str(e)]

            if not row_exists(csv_file_path, new_row):
                with open(csv_file_path, mode='a', newline='') as file:
                    writer = csv.writer(file)
                    writer.writerow(new_row)

    return False