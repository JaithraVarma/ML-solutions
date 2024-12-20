import ast
import os
import csv
import onnx
import pandas as pd
import onnx_graphsurgeon as gs
from collections import defaultdict
import op_support_check

current_file_path = os.path.abspath(__file__)
current_directory = os.path.dirname(current_file_path)

supported_operators_csv_path=os.path.join(current_directory,'operator_support.csv')
df=pd.read_csv(supported_operators_csv_path)
support_dict_int8=dict(zip(df['Operator'],df['Supported']))
support_dict_bf16=dict(zip(df['Operator'],df['Supported_Bf16']))

summary_files_prefix = ["summary_report"]
models_delimeter = ", "
attributes_delimeter = "\n"
attributes_count_delimeter = " : "
similar_models_delimeter = "\n"
similar_models_dict = {}
all_similar_models_dict = {}

# Define partitioner supported attributes
conv_supported_dict = {"bf16":{"kernel_shape":[1,3,5,7],
                       "strides":[1,2]},
                       "int8":{"kernel_shape":[1,3,5,7,11],
                       "strides":[1,2,3,4]}
                       }
dconv_supported_dict= {"bf16":{"kernel_shape":[1,3,5,7,9,11],
                       "strides":[1,2]},
                       "int8":{"kernel_shape":[3,5,7],
                       "strides":[1,2]}
                       }

convTranspose_supported_dict = {"bf16":{"kernel_shape":[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15],
                       "strides":[1,2]},
                       "int8":{"kernel_shape":[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15],
                       "strides":[1,2,3,4]}
                       }

averagepool_supported_dict = {"bf16":{"kernel_shape":[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20],
                       "strides":[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20]},
                       "int8":{"kernel_shape":[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20],
                       "strides":[1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20]}
                       }

concat_supported_dict = {"bf16": {"axis": 1},
                         "int8": {"axis": 1}}

maxpool_supported_dict={"bf16":{"kernel_shape":[2,3],
                       "strides":[1,2]},
                       "int8":{"kernel_shape":[2,3],
                       "strides":[1,2]}
                       }

def is_opr_supported(operator, attributes, dtype):
    map = {'Conv':conv_supported_dict,'ConvD':dconv_supported_dict,'MaxPool':maxpool_supported_dict,'ConvTranspose':convTranspose_supported_dict, 'AveragePool':averagepool_supported_dict, 'Concat':concat_supported_dict}
    for attr_name in attributes:
        attr_val = attributes[attr_name]
        if map[operator][dtype] == "all":
            return True
        if attr_name == 'axis' and attr_val != map[operator][dtype][attr_name]:
            return False
        elif attr_name in ['kernel_shape', 'stride']:
            for i in attr_val:
                if map[operator][dtype] and i not in map[operator][dtype][attr_name]:
                    return False
    return True

current_file_path = os.path.abspath(__file__)
current_directory = os.path.dirname(current_file_path)

file_path = os.path.join(current_directory,"operators.csv")
csv_data = pd.read_csv(file_path)

sheet_lists = {}
for sheet_name in csv_data['Type'].unique():
    sheet_data = csv_data[csv_data['Type'] == sheet_name]['Operator'].tolist()
    # Check if the sheet has any data
    if sheet_data:
        sheet_lists[sheet_name] = sheet_data
    else:
        sheet_lists[sheet_name] = []


# Defining types of operators
unary = sheet_lists.get('unary', [])
binary = sheet_lists.get('binary', [])
nnary = sheet_lists.get('nnary', [])
reduction = sheet_lists.get('reduction', [])
linear = sheet_lists.get('linear', [])
conv_t = sheet_lists.get('conv_t', [])
conv = sheet_lists.get('conv', [])
pseudo = sheet_lists.get('pseudo', [])
other = sheet_lists.get('other', [])

list_names = ['unary', 'binary', 'nnary', 'reduction', 'linear', 'conv_t', 'conv', 'pseudo', 'other']
supported_templates = reduction + conv  # + conv_t #unary + binary + reduction + conv + conv_t

count_all_operators = ['Flatten', 'Gemm', 'QuantizeLinear', 'DequantizeLinear']

def create_operator_type_dict(list_names):
    operator_type_dict = {}
    for list_name in list_names:
        for operator in eval(list_name):
            operator_type_dict[operator] = list_name
    return operator_type_dict
operator_type_dict = create_operator_type_dict(list_names)


# update:  use exl sheel mllib
mllib = sheet_lists['mllib'] 
count_all_operators+=mllib
count_all_operators += sheet_lists['confluence'] 

def string_to_tuple(s):
    a,b = s.split(attributes_count_delimeter)
    return (a[1:-1],int(b))

def attribute_string_to_dict(attributes_string):
    list_of_strings = attributes_string.split(attributes_delimeter)
    list_of_tuples = list(map(lambda a:string_to_tuple(a), list_of_strings))
    return dict(list_of_tuples)

def get_attributes_dict(attributes_data):
    attr_dict = {}
    for attr in attributes_data:
        if attr.name in ['auto_pad', 'storage_order']:
            continue
        if attr.type == 7:
            attr_dict[attr.name] = attr.ints
        elif attr.type == 3:
            attr_dict[attr.name] = attr.s
        elif attr.type == 2:
            attr_dict[attr.name] = attr.i
        elif attr.type == 1:
            attr_dict[attr.name] = attr.f
        else:
            attr_dict[attr.name] = {}
    return attr_dict

def format_operators(input_dict):
    output_dict = {}
    for operator, dtypes in input_dict.items():
        formatted_counts = {}
        for dtype, attributes in dtypes.items():
            counts = {}
            for attribute in attributes:
                if isinstance(attribute, dict):
                    # Convert dictionary to string for counting
                    attr_str = str(attribute)
                    counts[attr_str] = counts.get(attr_str, 0) + 1
                else:
                    counts[attribute] = counts.get(attribute, 0) + 1
            
            formatted_counts[dtype] = "\n".join([f"{k}:{v}" for k, v in counts.items()])
        
        output_dict[operator] = formatted_counts
    return output_dict



def count_similar_models(similar_models):
    if isinstance(similar_models, str) and similar_models.strip():
        return len(similar_models.split(similar_models_delimeter)) + 1
    else:
        return 1
        
def unique_models(excel_files_dir, summary_filename="summary_report.xlsx", sheet_name="unique_models"):
    global similar_models_dict, all_similar_models_dict
    summary_dict = defaultdict(list)
    for filename in os.listdir(excel_files_dir):
        if filename.endswith('.xlsx') and (not any(filename.startswith(summary_file_prefix) for summary_file_prefix in summary_files_prefix)):
            df = pd.read_excel(os.path.join(excel_files_dir, filename), sheet_name='attr_info')
            model_name = filename.replace('.xlsx', '')
            operators = "$".join(df["operator"].tolist())
            summary_dict[operators].append(model_name)
    similar_models_dict = {v[0]: similar_models_delimeter.join(v[1:]) for v in summary_dict.values()}
    all_similar_models_dict = {v[i]: similar_models_delimeter.join(v[:i] + v[i+1:]) for v in summary_dict.values() for i in range(len(v))}
    summary_df = pd.DataFrame(list(similar_models_dict.items()), columns=["model", "similar_models"])

    # Apply the function to create the "Count" column
    summary_df["Count"] = summary_df["similar_models"].apply(count_similar_models)
    summary_df["Remarks"] = ""
    
    with pd.ExcelWriter(summary_filename, engine='openpyxl') as writer:
        summary_df.to_excel(writer, sheet_name=sheet_name, index=False)
    print(f"Check {sheet_name} sheet in model_analysis.xlsx for summary report")
    
def combine_attribute_string(series):
    attribute_counts = {}
    for attributes in series:
        for attribute in attributes.split('\n'):
            if ':' in attribute:
                # Find the last occurrence of ':' character
                last_colon_index = attribute.rfind(':')
                key = attribute[:last_colon_index].strip()
                value = attribute[last_colon_index + 1:].strip()
                value = int(value.strip())
                # Update the attribute count in the dictionary
                attribute_counts[key] = attribute_counts.get(key, 0) + value
    formatted_attributes = [f"{key}:{value}" for key, value in attribute_counts.items()]
    return "\n".join(formatted_attributes)

def extract_group(s):
    if 'group' not in s:
        return None
    my_dict = ast.literal_eval(s)
    return int(my_dict['group'])

def extract_dilation(s):
    if 'dilations' not in s:
        return None
    my_dict = ast.literal_eval(s)
    return my_dict['dilations']


def is_operator_attribute_supported(operator, attribute, dtype):
    attribute = ast.literal_eval(attribute)
    if dtype == 'fp32':
        return True
    if dtype=='int8' and operator in support_dict_int8.keys():
        return support_dict_int8[operator]
    elif dtype=='bf16' and operator in support_dict_bf16.keys():
        return support_dict_bf16[operator]
    elif operator in ['Conv', 'AveragePool', 'ConvTranspose', 'Concat'] and is_opr_supported(operator, attribute, dtype):
        return True
    return False

def get_percentage_supported_ops(df, dtype):
    total_supported_ops = 0
    for o,s in zip(df['operator'], df['attributes']):
        lst = s.split('\n')
        for s in lst:
            last_colon_index = s.rfind(':')
            d = s[:last_colon_index].strip()
            count = s[last_colon_index + 1:].strip()
            total_supported_ops += int(is_operator_attribute_supported(o,d,dtype)*int(count))
    total_ops = df['occurrence'].sum()
    percentage_supported_ops = (100 * total_supported_ops) / total_ops
    # Format the percentage to two decimal places
    formatted_percentage = "{:.2f}".format(percentage_supported_ops)
    return float(formatted_percentage)  # Convert the formatted percentage back to a float


def count_attributes(row):
    attributes = row["attributes"].split("\n")
    return [string_to_tuple(attribute)[1] for attribute in attributes]

def split_attributes(row):
    attributes = row["attributes"].split("\n")
    return [string_to_tuple(attribute)[0] for attribute in attributes]

# Define custom aggregation function
def custom_agg(x):
    aie_operators = ','.join(x[x['is_supported']]['operator'])
    cpu_operators = ','.join(x[~x['is_supported']]['operator'])
    return pd.Series([aie_operators, cpu_operators], index=['aie_operators', 'cpu_operators'])


def model_gen_summary(excel_files_dir, summary_filename, sheet_name="model_gen_info"):
    # Initialize an empty list to store dataframes
    dfs = []
    for filename in os.listdir(excel_files_dir):
        if filename.endswith('.xlsx'):
            df = pd.read_excel(os.path.join(excel_files_dir, filename), sheet_name='model_info')
            df['model'] = filename.replace('.xlsx', '')
            dfs.append(df)
    # Concatenate all dataframes into a single dataframe
    result_df = pd.concat(dfs, ignore_index=True)
    result_df = result_df[['model', 'node', 'opType', 'inputs', 'num_inputs', 'input_oprs', 'input_shape', 'outputs', 'num_outputs', "Remarks"]]
    result_df = result_df.drop(columns=['input_shape'])
    with pd.ExcelWriter(summary_filename, engine='openpyxl', mode='a') as writer:
        result_df.to_excel(writer, sheet_name=sheet_name, index=False)
    return

def get_model_names(model_names_dir,model_names):
    model_names_list=[]
    model_names_dir_list=[]
    if ".onnx"  in model_names:
        model_names = model_names.replace(" ", "")
        model_names_list = model_names.split(',')
        model_names_list = [model.replace(".onnx", "") for model in model_names_list]
    elif ".txt" in model_names:
        with open(model_names, 'r') as file:
               model_names_list = [line.strip() for line in file]
    
    if os.path.exists(model_names_dir):
        model_names_dir_list=os.listdir(model_names_dir)
        if len(model_names_list):
          model_names_list = set(model_names_list) & set(model_names_dir_list)
        else:
          model_names_list=model_names_dir_list
    return model_names_list

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
        if tensor_name in [i.name for i in model.graph.input]:
            tensor_shape = [dim.dim_value for dim in model.graph.input[0].type.tensor_type.shape.dim]
        elif tensor_name in [i.name for i in model.graph.output]:
            tensor_shape = [dim.dim_value for dim in model.graph.output[0].type.tensor_type.shape.dim]

    return tensor_shape

def get_input_output_tensor_shape(model, tensor_names):
    tensor_shapes = []
    for tn in tensor_names:
        tensor_shape = extract_tensor_shape(model, tn)
        if tensor_shape:
            tensor_shapes.append(tensor_shape)
    return tensor_shapes

def get_parent_opr(graph, inputs):
    parent_ops = []
    for node in graph.nodes:
        outputs = [i.name for i in node.outputs]
        if len(outputs) == 0:
            continue
        for op in outputs:
            if op in inputs:        # the outptut of parent node is the input of child node
                parent_ops.append(node.op)
    if not parent_ops:
        parent_ops = ['Initializers']
    return parent_ops

def get_tensor_shapes(tensors):
    tensor_shapes = []
    for tensor in tensors:
        tensor_shape = extr_tensor_shape(tensor)
        if tensor_shape:
            tensor_shapes.append(tensor_shape)
    return tensor_shapes

def extr_tensor_shape(tensor):
    if hasattr(tensor, 'shape') and tensor.shape is not None:
        return list(tensor.shape)
    return []  # Return an empty list if shape is not available


def io_extraction(csv_file, model, dtype, csv_file_path, model_name):
    modelinfo = {}
    graph = gs.import_onnx(model)
    for node in graph.nodes:
        if node.op in ['Constant', 'Identity', 'QuantizeLinear', 'DequantizeLinear']:
            continue
        
        modelinfo[node.name] = {}
        modelinfo[node.name]['opType'] = node.op
        input_tensor_names = [i.name for i in node.inputs]
        if node.op in ['Conv', 'Gemm', 'BatchNormalization', 'LayerNormalization', 'Reshape', 'Equal', 'Gather', 'Squeeze', 'Unsqueeze', 'ReduceSum']:
            input_tensor_names = input_tensor_names[:1]
        modelinfo[node.name]['inputs'] = input_tensor_names
        modelinfo[node.name]['num_inputs'] = len(input_tensor_names)
        modelinfo[node.name]['input_oprs'] = get_parent_opr(graph, input_tensor_names)
        modelinfo[node.name]['input_shape'] = ''
        output_tensor_names = [i.name for i in node.outputs]
        modelinfo[node.name]['outputs'] = output_tensor_names
        modelinfo[node.name]['num_outputs'] = len(input_tensor_names)
        modelinfo[node.name]['Remarks'] = ""

        # Initialize variables
        conv_dim_check = None
        broadcast_scalar_check = None
        symmetry_check = None
        symmetry = ''
        axis_check_concat = None
        opType = f"{node.op}"

        if node.op == "Concat":
            axis_check_concat = op_support_check.concat_axis_check(node)
            if axis_check_concat is True:
                modelinfo[node.name]['opType'] = f'{node.op}_axis1'
        
        if node.op == 'Slice':
            inc_check = op_support_check.slice_inc_check(node, csv_file_path, model_name)
            if inc_check is True:
                modelinfo[node.name]['opType'] = f'{node.op}_incdiv8'
        
        if node.op == "Pad":
            pad_check_reflect = op_support_check.pad_reflect_check(node)
            if pad_check_reflect is True:
                modelinfo[node.name]['opType'] = f'{node.op}_reflect'
        
        if node.op in ["MaxPool", "AveragePool"]:
            symmetry_check = op_support_check.check_kernel_symmetry(node)
            if symmetry_check:
                symmetry = 'symmetric'
            else:
                symmetry = 'asymmetric'
            modelinfo[node.name]['opType'] = f'{node.op}_{symmetry}'

        if node.op == "ConvTranspose":
            symmetry_check = op_support_check.check_kernel_symmetry(node)
            if symmetry_check:
                symmetry = 'symmetric'
            else:
                symmetry = 'asymmetric'
            modelinfo[node.name]['opType'] = f'{node.op}_{symmetry}'
        

        elif node.op == 'Conv':
            operator_attributes = node.attrs
            group = operator_attributes.get("group", None)
            if not group:
                group = 1

            inputs = get_input_output_tensor_shape(model, input_tensor_names)
            conv_dim_check = op_support_check.conv_2d_check(node)
            symmetry_check = op_support_check.check_kernel_symmetry(node)
            
            if symmetry_check:
                symmetry = 'symmetric'
            else:
                symmetry = 'asymmetric'

            if not inputs or len(inputs[0]) < 2:
                if conv_dim_check:
                    opType = 'Conv2d'
                else:
                    opType = 'Conv1d'
            elif group > 1 and group != inputs[0][1]:
                if conv_dim_check:
                    opType = 'ConvG2d'
                else:
                    opType = 'ConvG1d'
            elif group > 1 and group == inputs[0][1]:
                if conv_dim_check:
                    opType = 'ConvD2d'
                else:
                    opType = 'ConvD1d'
            else:
                if conv_dim_check:
                    opType = 'Conv2d'
                else:
                    opType = 'Conv1d'
            
            opType = f'{opType}_{symmetry}'
            modelinfo[node.name]['opType'] = opType
            modelinfo[node.name]['input_shape'] = inputs

        # Broadcast operators
        elif node.op in ['Mul', 'Add', 'Div', 'Sub', 'Equal', 'Pow']:
            inputs = node.inputs
            num_inputs = len(inputs)
            merged_lst = [dim for input_shapes in get_tensor_shapes(inputs) for dim in input_shapes]
            
            if 0 in merged_lst:
                continue
            
            if num_inputs > 1:
                if any(extr_tensor_shape(inputs[i]) != extr_tensor_shape(inputs[i + 1]) for i in range(num_inputs - 1)):
                    # broadcast_scalar_check = op_support_check.broadcast_op_scalar_check(node, graph)
                    opType = f"Broadcast_{node.op}"
                    
            modelinfo[node.name]['opType'] = opType
            modelinfo[node.name]['input_shape'] = inputs

    data_list = []
    for node, attributes in modelinfo.items():
        data_list.append({'node': node, **attributes})
    df = pd.DataFrame(data_list)
    df.to_excel(csv_file, sheet_name='model_info', index=False)
    return


def determine_op_support(row, dtype):
    operator = row['operator']
    cleaned_operator = operator.replace("_symmetric", "").replace("_asymmetric", "").replace("_axis1", "").replace("Broadcast_","").replace("Conv2d","Conv").replace("ConvD2d", "Conv").replace("ConvG2d", "Conv").replace("_scalar", "")
    input_dtype = row['input_dtype']

    is_supported = input_dtype == "float32"

    if is_supported:
        if dtype == 'int8':
            try:
                is_supported = support_dict_int8[cleaned_operator]
            except:
                is_supported = False

        elif dtype == 'bf16':
            try:
                is_supported = support_dict_bf16[cleaned_operator]
            except:
                is_supported = False
        
        if is_supported:

            if "Slice" in operator:
                if "incdiv8" in operator:
                    is_supported = True
                else:
                    is_supported = False
            
            elif "Pad" in operator:
                if "reflect" in operator:
                    is_supported = True
                else:
                    is_supported = False
            
            elif "Concat" in operator:
                if "axis1" in operator:
                    is_supported = True
                else:
                    is_supported = False

            elif "Conv" in operator:
                if "Conv2d" in operator or "ConvD2d" in operator:
                    is_supported = True
                    if "symmetric" in operator:
                        is_supported = True
                    elif "asymmetric" in operator:
                        is_supported = False
                else:
                    is_supported = False
            
            elif "Broadcast" in operator:
                # is_supported = "scalar" in operator
                is_supported = True
            
            if "symmetric" in operator:
                is_supported = True
            elif "asymmetric" in operator:
                is_supported = False
    
    return is_supported

def model_operator_summary(excel_files_dir, summary_filename, dtype, sheet_name="unique_model_operator", sheet_name_percentage="model_percentage_supported_ops"):
    summary_df = pd.DataFrame(columns=['model', 'operator', 'occurrence', 'attributes', 'input_dtype', 'percentage_supported_ops', "Remarks"])
    
    for filename in os.listdir(excel_files_dir):
        if filename.endswith('.xlsx') and (not any(filename.startswith(summary_file_prefix) for summary_file_prefix in summary_files_prefix)):
            df = pd.read_excel(os.path.join(excel_files_dir, filename), sheet_name='attr_info')
            df['model'] = filename.replace('.xlsx','')
            percentage_supported_ops = get_percentage_supported_ops(df, dtype)
            df['percentage_supported_ops'] = percentage_supported_ops
            summary_df = pd.concat([summary_df, df])

    summary_df = summary_df.assign(attributes=summary_df['attributes'].str.split('\n')).explode('attributes')
    summary_df['attribute_count'] = summary_df['attributes'].str.extract(r':(\d+)').astype(int)
    summary_df['attributes'] = summary_df['attributes'].str.rsplit(':', n=1).str[0]
    summary_df = summary_df.sort_values(by=['model', 'occurrence'], ascending=[True, False])

    summary_df['is_supported'] = summary_df.apply(determine_op_support, axis=1, args=(dtype,))
    
    summary_df['Remarks'] = ''
    summary_df = summary_df[['model', 'operator', 'attributes', 'input_dtype','is_supported', 'attribute_count', 'occurrence', 'percentage_supported_ops', 'Remarks']]
    
    percentage_summary_df = summary_df.drop(columns=['attributes', 'attribute_count', 'occurrence', 'Remarks'])
    percentage_summary_df = percentage_summary_df.drop_duplicates()
    percentage_summary_df = percentage_summary_df.groupby(['model', 'percentage_supported_ops', 'is_supported'])['operator'].agg(', '.join).reset_index()
    percentage_summary_df = percentage_summary_df.groupby(['model', 'percentage_supported_ops']).apply(custom_agg).reset_index()
    percentage_summary_df['Remarks'] = ""

    summary_df = summary_df.drop(columns=['percentage_supported_ops'])
    # summary_df['operator'] = summary_df['operator'].str.replace('_axis1', '', regex=False)
    # percentage_summary_df['operator'] = percentage_summary_df['operator'].str.replace('_axis1', '', regex=False)
    with pd.ExcelWriter(summary_filename, engine='openpyxl', mode='a') as writer:
        summary_df.to_excel(writer, sheet_name=sheet_name, index=False)
        percentage_summary_df.to_excel(writer, sheet_name=sheet_name_percentage, index=False)
    
    print(f"Check {sheet_name} sheet and {sheet_name_percentage} sheet in {summary_filename} for summary report")


def unique_operator_attribute_summary(excel_files_dir, summary_filename, dtype, sheet_name="unique_operator_attributes"):
    summary_df = pd.DataFrame(columns=['operator', 'attributes', 'input_dtype', 'is_supported', 'occurrence', 'models', 'model_count'])
    
    for filename in os.listdir(excel_files_dir):
        if filename.endswith('.xlsx') and (not any(filename.startswith(summary_file_prefix) for summary_file_prefix in summary_files_prefix)):
            df = pd.read_excel(os.path.join(excel_files_dir, filename), sheet_name='attr_info')
            df['models'] = filename.replace('.xlsx', '')
            df['model_count'] = 1
            summary_df = pd.concat([summary_df, df])
    
    summary_df.drop(columns=['occurrence'], inplace=True)
    summary_df = summary_df.assign(attributes=summary_df['attributes'].str.split('\n')).explode('attributes')
    summary_df['attribute_count'] = summary_df['attributes'].str.extract(r':(\d+)').astype(int)
    summary_df['attributes'] = summary_df['attributes'].str.rsplit(':', n=1).str[0]
    summary_df['is_supported'] = summary_df.apply(determine_op_support, axis=1, args=(dtype,))
    
    final_summary = summary_df.groupby(['operator', 'attributes', 'input_dtype', 'is_supported']).agg({
        'models': models_delimeter.join,
        'model_count': 'sum',
        'attribute_count': 'sum'
    }).reset_index()

    final_summary = final_summary.sort_values(by='operator', ascending=True)
    final_summary['Remarks'] = ''
    # final_summary['operator'] = final_summary['operator'].str.replace('_axis1', '', regex=False)
    with pd.ExcelWriter(summary_filename, engine='openpyxl', mode='a') as writer:
        final_summary.to_excel(writer, sheet_name=sheet_name, index=False)
    
    print(f"Check {sheet_name} sheet in {summary_filename} for summary report")


def unique_operators(excel_files_dir, summary_filename, dtype, sheet_name="unique_operators"):
    summary_df = pd.DataFrame(columns=['operator','input_dtype', 'attributes', 'models', 'model_count', 'occurrence'])
    for filename in os.listdir(excel_files_dir):
        if filename.endswith('.xlsx') and (not any(filename.startswith(summary_file_prefix) for summary_file_prefix in summary_files_prefix)):# and os.path.splitext(filename)[0] in similar_models_dict:
            df = pd.read_excel(os.path.join(excel_files_dir, filename), sheet_name='attr_info')
            df['models'] = filename.replace('.xlsx', '')
            df['model_count'] = 1
            summary_df = pd.concat([summary_df, df])
    final_summary = summary_df.groupby(['operator','input_dtype']).agg({
        'attributes': combine_attribute_string,
        'models': models_delimeter.join,
        'model_count': 'sum',
        'occurrence': 'sum'
    }).reset_index()
    
    final_summary["operator_type"] = final_summary["operator"].map(operator_type_dict)
    summary_df = final_summary.copy()
    summary_df = summary_df.drop(columns=['model_count', 'occurrence', 'operator_type', 'models'])
    summary_df= summary_df.assign(attributes=summary_df['attributes'].str.split('\n')).explode('attributes')
    summary_df['attributes'] = summary_df['attributes'].str.rsplit(':', n=1).str[0]    
    summary_df['is_supported'] = summary_df.apply(determine_op_support, axis=1, args=(dtype,))

    summary_df= summary_df.groupby(['operator','input_dtype']).agg({'attributes': lambda x: '\n'.join(x), 'is_supported' : lambda x: set(x)}).reset_index()
    summary_df = summary_df.drop(columns=['attributes'])
    merged_df = pd.merge(final_summary, summary_df, on=['operator','input_dtype'], how='outer')
    merged_df = merged_df.sort_values(by='model_count', ascending=False)
    merged_df = merged_df.rename(columns={'occurrence': 'total_occurrence'})
    merged_df = merged_df[['operator','input_dtype', 'attributes', 'is_supported', 'models', 'model_count', 'total_occurrence']]
    merged_df['Remarks'] = ""
    merged_df = merged_df.sort_values(by='operator', ascending=True)
    # merged_df['operator'] = merged_df['operator'].str.replace('_axis1', '', regex=False)
    with pd.ExcelWriter(summary_filename, engine='openpyxl', mode='a') as writer:
        merged_df.to_excel(writer, sheet_name=sheet_name, index=False)
    print(f"Check {sheet_name} sheet in model_analysis.xlsx for summary report")

def get_operator_dtypes(gs_model):
    node_dtype = {}
    for node in gs_model.nodes:
        if node.op == 'Constant':
            continue
        dtype_list = []
        for i in node.inputs:
            dtype_list.append(i.dtype)
            break
        node_dtype[node.name] = dtype_list[0] if dtype_list else 'unknown'
    return node_dtype

def operator_extraction(csvFile, model):
    operator_counts = defaultdict(lambda: defaultdict(int))
    operator_attributes = defaultdict(lambda: defaultdict(list))

    modelinfo = pd.read_excel(csvFile, sheet_name='model_info')
    info_dict = {}
    for index, row in modelinfo.iterrows():
        node = row['node']
        node_dict = {
            'opType': row['opType'],
            'inputs': row['inputs']
        }
        info_dict[node] = node_dict

    gs_model = gs.import_onnx(model)
    node_dtype = get_operator_dtypes(gs_model)  # Get dtype for each node

    for node in model.graph.node:
        if node.name and node.name in info_dict:
            data = info_dict[node.name]['opType']
        else:
            data = node.op_type
        if data and data != "Constant":
            attributes_data = node.attribute
            if attributes_data:
                attributes = get_attributes_dict(attributes_data)
            else:
                attributes = {}
            dtype = node_dtype.get(node.name, 'unknown')  # Fetch dtype from the dictionary

            operator_counts[data][dtype] += 1
            operator_attributes[data][dtype].append(attributes)
    
    operator_attributes = format_operators(operator_attributes)
    # Prepare the DataFrame
    rows = []
    for operator, dtypes in operator_counts.items():
        for dtype, count in dtypes.items():
            attributes = operator_attributes[operator][dtype]
            rows.append({
                "operator": operator,
                "occurrence": count,
                "input_dtype": dtype,
                "attributes": f"{attributes}"
            })

    df = pd.DataFrame(rows)
    df = df.sort_values(by="occurrence", ascending=False)
    df.reset_index(drop=True, inplace=True)
    
    # Ensure the sheet is written to the file
    with pd.ExcelWriter(csvFile, engine='openpyxl', mode='a' if os.path.exists(csvFile) else 'w') as writer:
        df.to_excel(writer, sheet_name='attr_info', index=False)

def analyze_operators(models_dir, output_dir, dtype, model_names, model_names_dir,reuse):
  
    csv_file_path = os.path.join(output_dir, 'error.csv')
    
    files = os.listdir(models_dir)
    model_names_list = get_model_names(model_names_dir, model_names)

    output_dir = os.path.join(output_dir, "operator_analysis")
    os.makedirs(output_dir, exist_ok=True)
    for model_name in files:
        model_name = model_name.replace(".onnx", "")
        if len(model_names_list):
            if model_name not in model_names_list:
                continue

        onnx_file = os.path.join(models_dir, model_name + ".onnx")
        csv_file = os.path.join(output_dir, model_name + ".xlsx")
        
        if reuse == "True":
            try:
                if not os.path.isfile(csv_file):
                    print(f"Extracting operator info for {model_name} model")
                    model = onnx.shape_inference.infer_shapes(onnx.load(onnx_file))
                    io_extraction(csv_file, model, dtype, csv_file_path, model_name)
                    operator_extraction(csv_file, model)
                    print(f"Operator information and its occurrence are captured in {csv_file}\n")
            except Exception as e:
                print(e)
                with open(csv_file_path, mode='a', newline='') as file:
                            writer = csv.writer(file)
                            writer.writerow(['operator_analysis', model_name, str(e)])
        else:
            try:
                print(f"Extracting operator info for {model_name} model")
                model = onnx.load(onnx_file)
                io_extraction(csv_file, model, dtype, csv_file_path, model_name)
                operator_extraction(csv_file, model)
                print(f"Operator information and its occurrence are captured in {csv_file}\n")
            except Exception as e:
                print(e)
                with open(csv_file_path, mode='a', newline='') as file:
                            writer = csv.writer(file)
                            writer.writerow(['operator_analysis', model_name, str(e)])


    summary_filename = f"operator_analysis.xlsx"
    unique_models(output_dir, summary_filename=summary_filename)
    unique_operators(output_dir, summary_filename=summary_filename, dtype=dtype)
    unique_operator_attribute_summary(output_dir, summary_filename=summary_filename, dtype=dtype)
    model_operator_summary(output_dir, summary_filename=summary_filename, dtype=dtype)
    model_gen_summary(output_dir, summary_filename=summary_filename)
