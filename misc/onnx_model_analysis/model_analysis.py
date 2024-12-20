import onnx
import pandas as pd
import argparse
from onnxsim import simplify
from qonnx.core.modelwrapper import ModelWrapper

# get conv type
def conv_type(node, input_shapes_list):
    # For depthwise conv kernal shape is (x, 1, x, x) else group conv
    # For pointwise conv kernal shape is (1, x, 1, 1)
    group = node.attribute[1].i
    if group != 1:
        if input_shapes_list[1][1] == 1:
            return 'Depthwise Conv'
        else:
            return 'Group Conv'
    else:
        if input_shapes_list[1][2] == 1 and input_shapes_list[1][3] == 1:
            return 'Pointwise Conv'
        else:
            return 'Normal Conv'

def main():
    parser = argparse.ArgumentParser(
        description="Utility script to generate "
        "information about operators that appear either in torchvision or "
        "given onnx models."
    )
    parser.add_argument(
        "--model", 
        type=str, required=True, 
        help="path the model to be analysed"
    )

    args = parser.parse_args()

    # Load the ONNX model
    model_path = args.model
    model = onnx.load(model_path)
    model, check = simplify(model)
    model = ModelWrapper(model)

    # Create a dictionary to store the nodes by operator type
    nodes_by_op_type = {}
    nodes_by_conv_type = {}
    # Iterate over all nodes in the graph
    for node in model.graph.node:
        # Skip the QuantizeLinear, DequantizeLinear, and Constant operators
        if node.op_type in ["QuantizeLinear", "DequantizeLinear", "Constant"]:
            continue
        # If the operator type is not in the dictionary, create a new list for it
        if node.op_type not in nodes_by_op_type:
            nodes_by_op_type[node.op_type] = []
        # Creating seperate dict which is going to be used for summary table
        if node.op_type != 'Conv':
            oprType = node.op_type
        else:
            ipl = [model.get_tensor_shape(x) for x in node.input]
            oprType = conv_type(node, ipl)
        if oprType not in nodes_by_conv_type:
            nodes_by_conv_type[oprType] = []
        # Append the node to the list for its operator type
        nodes_by_op_type[node.op_type].append(node)
        nodes_by_conv_type[oprType].append(node)


    # Create an Excel file with one sheet for each operator type
    with pd.ExcelWriter("model_attributes.xlsx") as writer:
        for op_type, nodes in nodes_by_op_type.items():
            # Create a pandas DataFrame with columns for each attribute of the nodes
            df = pd.DataFrame()
            for node in nodes:
                node_dict = {"node_name": node.name}
                try:
                    input_shapes_list = [model.get_tensor_shape(x) for x in node.input]
                    output_shapes_list = [model.get_tensor_shape(x) for x in node.output]
                    if op_type == 'Conv':
                        conv = conv_type(node, input_shapes_list)
                        node_dict['Conv Type'] = conv
                    node_dict['Input Shapes'] = input_shapes_list
                    node_dict['Output Shapes'] = output_shapes_list
                except:
                    node_dict['Input Shapes'] = 'NA'
                    node_dict['Output Shapes'] = 'NA'
                for attr in node.attribute:
                    if attr.name in ['ceil_mode', 'allowzero', 'keepdims', 'axis', 'exclude_outside', 'training_mode']:
                        attr_value = attr.i
                    elif attr.name in ['epsilon']:
                        attr_value = attr.f
                    else:
                        attr_value = attr.ints or attr.floats or attr.s or attr.i or attr.f or None
                    node_dict[attr.name] = attr_value
                temp = pd.DataFrame(data=[node_dict])
                df = pd.concat([df, temp], ignore_index=True)
            # Write the DataFrame to a sheet in the Excel file
            df.to_excel(writer, sheet_name=op_type, index=False)


        # Creating the summary sheet
        summary = pd.DataFrame()
        for op_type, nodes in nodes_by_conv_type.items():
            # Create a pandas DataFrame with columns for each attribute of the nodes
            op_info = {'Operator': op_type}
            attr_info = {}
            count = 0
            for node in nodes:
                count = count + 1
                for attr in node.attribute:
                    if attr.name in ['ceil_mode', 'allowzero', 'keepdims', 'axis', 'exclude_outside', 'training_mode']:
                        attr_value = attr.i
                    elif attr.name in ['epsilon']:
                        attr_value = attr.f
                    else:
                        attr_value = attr.ints or attr.floats or attr.s or attr.i or attr.f or 'NA'
                        
                    if attr.name not in attr_info:
                        attr_info[attr.name] = set()
                    if isinstance(attr_value, int) or isinstance(attr_value, float) or isinstance(attr_value, bytes) or isinstance(attr_value, str):
                        attr_info[attr.name].add(attr_value)
                    else:
                        attr_value_tuple = tuple(attr_value)
                        attr_info[attr.name].add(attr_value_tuple)
            for key, value in attr_info.items():
                # check if the value is a set
                if isinstance(value, set):
                    # convert the set to a sorted list and update the dictionary
                    attr_info[key] = sorted(list(value))
            op_info['Count'] = count
            if len(attr_info) == 0:
                op_info['Attributes'] = 'NA'
            else:
                op_info['Attributes'] = attr_info
            temp = pd.DataFrame(data=[op_info])
            summary = pd.concat([summary, temp], ignore_index=True)
        # Write the DataFrame to a sheet in the Excel file
        summary.to_excel(writer, sheet_name='Summary', index=False)


main()