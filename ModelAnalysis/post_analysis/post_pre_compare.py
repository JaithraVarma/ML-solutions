import os
import json
import pandas as pd
import onnx
import onnx_graphsurgeon as gs
from onnxsim import simplify
import csv
import ast
from collections import OrderedDict
import re
import argparse
from path_mapper_integrate import get_paths
# Extracts the shape of a tensor by its name from the ONNX model
def extract_tensor_shape(model, tensor_name):
    tensor_shape = []

    # Search for the tensor's shape in value_info (intermediate values)
    for itm in model.graph.value_info:
        if itm.name == tensor_name:
            if hasattr(itm.type.tensor_type, 'shape'):
                if hasattr(itm.type.tensor_type.shape, 'dim'):
                    tensor_shape = [dim.dim_value for dim in itm.type.tensor_type.shape.dim]
                    break

    # If not found, search in model inputs and outputs
    if not tensor_shape:
        for inp in model.graph.input:
            if inp.name == tensor_name:
                tensor_shape = [dim.dim_value for dim in inp.type.tensor_type.shape.dim]
        for op in model.graph.output:
            if op.name == tensor_name:
                tensor_shape = [dim.dim_value for dim in op.type.tensor_type.shape.dim]
    return tensor_shape

# Gets the input/output tensor shapes for a list of tensor names
def get_input_output_tensor_shape(model, tensor_names):
    tensor_shapes = []
    for tn in tensor_names:
        tensor_shape = extract_tensor_shape(model, tn)
        if tensor_shape:
            tensor_shapes.append(tensor_shape)
    return tensor_shapes

def get_tensor_size(tensor_shape):
    size = 1
    for dim in tensor_shape:
        if dim:
            size *= dim
    return size

def traverse_onnx_nodes(model, model_name):
    ops_info = []
    dtype_sz = 2  # Data type size in bytes (assuming 16-bit, change if necessary)

    #Use graph_surgeon to extract attributes of operators
    layer_name_attrs={}
    model_gs=gs.import_onnx(model)
    for node in model_gs.nodes:
        layer_name_attrs[node.name]=node.attrs
    
    # Iterate through each node (operator) in the model
    for node in model.graph.node:
        op_type = node.op_type
        op_name = node.name
        ifm_shape = []
        ofm_shape = []
        ifm_size = 0
        ofm_size = 0

        # Extract input shapes and calculate size
        for inp in node.input:
            shape = extract_tensor_shape(model, inp)
            if shape:
                ifm_shape.append('x'.join(map(str, shape)))  # Format shape as string
                size = get_tensor_size(shape)
                ifm_size += size * dtype_sz / 1024  # Convert size to KB

        # Extract output shapes and calculate size
        for out in node.output:
            shape = extract_tensor_shape(model, out)
            if shape:
                ofm_shape.append('x'.join(map(str, shape)))  # Format shape as string
                size = get_tensor_size(shape)
                ofm_size += size * dtype_sz / 1024  # Convert size to KB

        # Collect node information into a dictionary
        ops_info.append({
            "Model_Name": model_name,
            "Layer_Name": op_name,
            "Operator_Type": op_type,
            "Attributes":layer_name_attrs.get(op_name),
            "IFM_Shape": ','.join(ifm_shape) if ifm_shape else 'None',
            "IFM_Size(KB)": ifm_size,
            "OFM_Shape": ','.join(ofm_shape) if ofm_shape else 'None',
            "OFM_Size(KB)": ofm_size
        })

    return ops_info

def check_supported_ops(ops_info, unsupported_ops):
    for op in ops_info:
        op_name = op["Layer_Name"]
        op["Is_Supported"] = "False" if op_name in unsupported_ops else "True"
    return ops_info

def process_model(model_path, unsupported_ops_json, model_name):
    try:
        # Load the ONNX model and infer its shapes
        model = onnx.load(model_path)
        model = onnx.shape_inference.infer_shapes(model)

        # Extract operator information from the model
        ops_info = traverse_onnx_nodes(model, model_name)

        # Load the unsupported operators from JSON file
        with open(unsupported_ops_json, 'r') as f:
            unsupported_ops = json.load(f)

        # Check which operators are supported
        ops_info = check_supported_ops(ops_info, unsupported_ops)

        return ops_info

    except Exception as e:
        # Handle and report errors during model processing
        print(f"Error processing model {model_name} ({model_path}): {e}")
        return []
def parse_viz_file(file):
    op_dict={}
    for block in file['flexml_graph_metadata']['blocks']:
        if block['location']:
            op_dict[block['location'][0]]={}
            op_dict[block['location'][0]]['name']=[]
            op_dict[block['location'][0]]['operator_type']=[]
            for j in block['operators']:
                op_dict[block['location'][0]]['name'].append(j['name'])
                op_dict[block['location'][0]]['operator_type'].append(j['operator_type'])
            for property1 in block['properties']:
                if 'Cpu_Because_Message' in property1['name']:
                    op_dict[block['location'][0]]['Cpu_Because_Message']=property1['value']
    for operator in file['flexml_graph_metadata']['operators']:
        if operator['location']:
            if operator['location'][0] not in op_dict.keys():
                op_dict[operator['location'][0]]={}
            if 'name' not in op_dict[operator['location'][0]].keys() and 'operator_type' not in op_dict[operator['location'][0]].keys():
                op_dict[operator['location'][0]]['name']=[]
                op_dict[operator['location'][0]]['operator_type']=[]
                op_dict[operator['location'][0]]['name'].append(operator['name'])
                op_dict[operator['location'][0]]['operator_type'].append(operator['operator_type'])
            else:
                op_dict[operator['location'][0]]['name'].append(operator['name'])
                op_dict[operator['location'][0]]['operator_type'].append(operator['operator_type'])
    return op_dict

def create_df(complete_suite_dict,filename='./model_mapping.csv'):
    model_name=[]
    layername=[]
    operator_type=[]
    cpu_because_message=[]
    for model in complete_suite_dict.keys():
        if len(complete_suite_dict[model])==0:
            model_name.append(model)
            layername.append("")
            operator_type.append("")
            cpu_because_message.append("")
        else:
            for i in complete_suite_dict[model].keys():
                model_name.append(model)
                layername.append(i)
                op_new_list=[]
                if len(complete_suite_dict[model][i]['operator_type'])>1:
                    for op_type in complete_suite_dict[model][i]['operator_type']:
                        if 'tosa' in op_type:
                            continue
                        else:
                            op_new_list.append(op_type)
                    operator_type.append(op_new_list)
                else:
                    operator_type.append(complete_suite_dict[model][i]['operator_type'])
                if 'Cpu_Because_Message' in complete_suite_dict[model][i]:
                    cpu_because_message.append(complete_suite_dict[model][i]['Cpu_Because_Message'])
                else:
                    cpu_because_message.append("")
    df_viz=pd.DataFrame(columns=["Model_Name",'Layer_Name','OP_Type','Cpu_Because_Message'])
    df_viz['Model_Name']=model_name
    df_viz['Layer_Name']=layername
    df_viz['OP_Type']=operator_type
    df_viz['Cpu_Because_Message']=cpu_because_message
    df_viz.to_csv(filename,index=False)
    return df_viz



def load_support_dictionaries():
    current_file_path = os.path.abspath(__file__)
    current_directory = os.path.dirname(current_file_path)

    supported_operators_csv_path = os.path.join(current_directory, 'operator_support.csv')
    df = pd.read_csv(supported_operators_csv_path)

    support_dict_int8 = dict(zip(df['Operator'], df['Supported']))
    support_dict_bf16 = dict(zip(df['Operator'], df['Supported_Bf16']))
    
    return support_dict_int8, support_dict_bf16

support_dict_int8, support_dict_bf16 = load_support_dictionaries()

# Check for kernel symmetry in Conv layers
def check_kernel_symmetry(node):
    kernel_shape = node.get('Attributes', {}).get('kernel_shape', None)
    if kernel_shape and isinstance(kernel_shape, list):
        return len(set(kernel_shape)) == 1
    return None

# Various operator checks
def conv_2d_check(node):
    if node['Operator_Type'] != 'Conv':
        return False
    kernel_shape = node.get('Attributes', {}).get('kernel_shape', None)
    if kernel_shape is not None:
        return len(kernel_shape) == 2
    return None
# Custom parser for IFM_Shape
def parse_ifm_shape(ifm_shape_str):
    try:
        # Replace commas and other delimiters with 'x' for consistency
        normalized_str = re.sub(r'[xX,]', 'x', ifm_shape_str)
        
        # Split the string on 'x' and map each part to an integer
        if 'x' in normalized_str:
            return list(map(int, normalized_str.split('x')))
        
        # Attempt to parse using ast.literal_eval for other formats
        return ast.literal_eval(ifm_shape_str)
    except Exception as e:
        print(f"Error parsing IFM_Shape: {e}")
        return None

# Update conv_check function to use parse_ifm_shape
def conv_check(node):
    group = node.get('Attributes', {}).get('group', None)
    if not group:
        group = 1
    conv_dim_check = conv_2d_check(node)
    symmetry_check = check_kernel_symmetry(node)
    inputs = parse_ifm_shape(node['IFM_Shape'])  # Use the custom parser
    if not inputs or len(inputs) < 2:
        return conv_dim_check and symmetry_check
    elif group > 1 and group != inputs[1]:  # Adjusted index to match dimensions
        return conv_dim_check and not symmetry_check
    elif group > 1 and group == inputs[1]:
        return conv_dim_check and symmetry_check
    else:
        return conv_dim_check and symmetry_check

def concat_axis_check(node):
    axis = node.get('Attributes', {}).get('axis', None)
    return axis == 1 if axis is not None else None

def pad_reflect_check(node):
    mode = node.get('Attributes', {}).get('mode', None)
    return mode == 'reflect' if mode is not None else None

# Parse OrderedDict from attribute string
def parse_ordered_dict(attributes_str):
    attributes_str = attributes_str.strip().replace("OrderedDict(", "").rstrip(")")
    if not attributes_str:
        return OrderedDict()
    attributes_str = attributes_str.replace("'", '"')
    try:
        attributes_dict = ast.literal_eval(attributes_str)
        return attributes_dict
    except Exception as e:
        print(f"Error parsing attributes: {e}")
        return OrderedDict()

# Check support based on support dictionaries and custom rules
def check_operator_support(row, dtype):
    operator = row['Operator_Type']
    cleaned_operator = operator.replace("_symmetric", "").replace("_asymmetric", "").replace("_axis1", "").replace("Broadcast_", "").replace("Conv2d", "Conv").replace("ConvD2d", "Conv").replace("ConvG2d", "Conv").replace("_scalar", "")
    is_supported = True

    if is_supported:
        if dtype == 'int8':
            is_supported = support_dict_int8.get(cleaned_operator, False)
        elif dtype == 'bf16':
            is_supported = support_dict_bf16.get(cleaned_operator, False)

        if is_supported:
            if "Pad" in operator:
                is_supported = pad_reflect_check(row)
            elif "Concat" in operator:
                is_supported = concat_axis_check(row)
            elif "Conv" in operator:
                is_supported = conv_check(row)
    
    return is_supported

def process_result_dataframe(result, dtype):
    result['Pre_Is_Supported'] = result.apply(lambda x: check_operator_support(x, dtype), axis=1)
    return result


def pre_post_analyzer(config, data):
    dtype = config["dtype"]

    # Read the Excel file
    df = data
    # df = pd.read_excel("/wrk/xcohdnobkup6/srmanthe/ml_solutions/ModelAnalysis/postanalysis/result.xlsx")
    # Post-analysis processing
    post_analysis_list = []
    for i, row in df.iterrows():
        if str(row['vaiml_optimized_onnx_path']) != 'nan' and str(row['aie_unsupported_ops_path']) != 'nan':
            post_analysis_list.extend(process_model(row['vaiml_optimized_onnx_path'], row['aie_unsupported_ops_path'], row['Test Name']))
        else:
            post_analysis_list.extend([])

    # Create DataFrame from post-analysis results
    df_post = pd.DataFrame(post_analysis_list)

    # Parse visualization JSON files
    complete_suite_dict = {}
    for i, row in df.iterrows():
        if str(row['fused_viz_json_path']) != 'nan' and os.path.exists(str(row["fused_viz_json_path"])):
            with open(row['fused_viz_json_path'], 'r') as f:
                file = json.load(f)
            op_dict = parse_viz_file(file)
            complete_suite_dict[row['Test Name']] = op_dict
        else:
            complete_suite_dict[row['Test Name']] = {}

    # Create DataFrame from visualization data
    df_viz = create_df(complete_suite_dict)
    result = pd.merge(df_post, df_viz, on=['Model_Name', 'Layer_Name'], how='left')
    final_result = process_result_dataframe(result, dtype)
    print(final_result)

    return final_result
