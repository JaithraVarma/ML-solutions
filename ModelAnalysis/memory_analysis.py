import os
import sys
import csv
import glob
import json
import onnx
import argparse
import pandas as pd
import numpy as np
import onnx_graphsurgeon as gs

current_file_path = os.path.abspath(__file__)
current_directory = os.path.dirname(current_file_path)

file_path = os.path.join(current_directory,"operators.csv")
csv_data = pd.read_csv(file_path)

#Read Operator Support Csv
supported_operators_csv_path=os.path.join(current_directory,'operator_support.csv')
df=pd.read_csv(supported_operators_csv_path)
support_dict_int8=dict(zip(df['Operator'],df['Supported']))
support_dict_bf16=dict(zip(df['Operator'],df['Supported_Bf16']))

sheet_lists = {}
for sheet_name in csv_data['Type'].unique():
    sheet_data = csv_data[csv_data['Type'] == sheet_name]['Operator'].tolist()
    # Check if the sheet has any data
    if sheet_data:
        sheet_lists[sheet_name] = sheet_data
    else:
        sheet_lists[sheet_name] = []

count_all_operators = ['Flatten', 'Gemm', 'QuantizeLinear', 'DequantizeLinear']
count_all_operators+=sheet_lists['mllib']
count_all_operators += sheet_lists['confluence'] 

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

def check_model(model):
    opset_version = model.opset_import[0].version if len(model.opset_import) > 0 else None

    print(" OPSET VERSION ", opset_version)
    if opset_version < 10:
        print( " INCOMPATIBLE OPSET VERSION ", opset_version)
    
    if len(model.graph.value_info) == 0:
        print("  ONNX IS NOT SHAPE INFERRED ")

def get_size(ip_shapes):
    total_size=0
    for w in ip_shapes:
        ws= np.array([int(x) for x in w])
        size = 0
        if len(ws):
            size=1
        for element in ws:
            size *= element
        total_size+=size
    return total_size

def get_int_tensor_shape(tensor_shape):
    cleaned_tensor_shape=[]
    for dim in tensor_shape:
        if hasattr(dim, 'dim_value'):
            cleaned_tensor_shape.append(dim.dim_value)
    cleaned_tensor_shape=[int(x) for x in cleaned_tensor_shape]
    return cleaned_tensor_shape

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

def get_op_relu(ip_df, conv_output, parent_op):
    for index, row in ip_df.iterrows():
        if row["opType"]=="Relu":
            if len(set(row["inputs"]).intersection(conv_output)):
                return  row['outputs'], row['outputs_size'], row['outputs_shape'], parent_op+"_Relu", index
    return " "

def map_conv_relu(ip_df):
    drop_rows_indx=[]
    for index, row in ip_df.iterrows():
        if row["opType"] in ["Conv", "ConvD", "ConvG"] :
            if get_op_relu(ip_df, row['outputs'], row["opType"]) != " ":
                ip_df.loc[index,'outputs'], ip_df.loc[index,'outputs_size'], ip_df.at[index,'outputs_shape'], ip_df.loc[index,'opType'], drop_indx=get_op_relu(ip_df, row['outputs'], row["opType"])
                drop_rows_indx.append(drop_indx)
    ip_df = ip_df.drop(drop_rows_indx)
    return ip_df

def map_add_relu(ip_df):
    drop_rows_indx=[]
    for index, row in ip_df.iterrows():
        if row["opType"] in ["Add", 'Broadcast_Add'] :
            if get_op_relu(ip_df, row['outputs'], row["opType"]) != " ":
                ip_df.loc[index,'outputs'], ip_df.loc[index,'outputs_size'], ip_df.at[index,'outputs_shape'], ip_df.loc[index,'opType'], drop_indx=get_op_relu(ip_df, row['outputs'], row["opType"])
                drop_rows_indx.append(drop_indx)
    ip_df = ip_df.drop(drop_rows_indx)
    return ip_df
#
def get_op_dequant(ip_df, quant_output):
    for index, row in ip_df.iterrows():
        if row["opType"]=="DequantizeLinear":
            if len(set(row["inputs"]).intersection(quant_output)):
                return  row['outputs'], row['outputs_size'], row['outputs_shape'], "Q_DQ", index
    return " "

def map_qdq(ip_df):
    drop_rows_indx=[]
    for index, row in ip_df.iterrows():
        if row["opType"]=="QuantizeLinear":
            if get_op_dequant(ip_df, row['outputs']) != " ":
                ip_df.loc[index,'outputs'], ip_df.at[index,'outputs_size'], ip_df.at[index,'outputs_shape'], ip_df.loc[index,'opType'], drop_indx=get_op_dequant(ip_df, row['outputs'])
                drop_rows_indx.append(drop_indx)
    ip_df = ip_df.drop(drop_rows_indx)
    return ip_df
#
def get_op_max(ip_df, quant_output):
    for index, row in ip_df.iterrows():
        if row["opType"]=="MaxPool":
            if len(set(row["inputs"]).intersection(quant_output)):
                return row['operator_name'], row['args'],  row['outputs'], row['outputs_size'], row['outputs_shape'], "MaxPool", index
    return " "

def map_qdq_maxpool(ip_df):
    drop_rows_indx=[]
    for index, row in ip_df.iterrows():
        if row["opType"]=="Q_DQ":
            if get_op_max(ip_df, row['outputs']) != " ":
                ip_df.loc[index,'operator_name'], ip_df.loc[index,'args'], ip_df.loc[index,'outputs'], ip_df.at[index,'outputs_size'], ip_df.at[index,'outputs_shape'], ip_df.loc[index,'opType'], drop_indx=get_op_max(ip_df, row['outputs'])
                drop_rows_indx.append(drop_indx)
    ip_df = ip_df.drop(drop_rows_indx)
    return ip_df
#
def get_op_maxpool(ip_df, conv_output, parent_op):
    for index, row in ip_df.iterrows():
        if row["opType"]=="MaxPool":
            if len(set(row["inputs"]).intersection(conv_output)):
                return  row['outputs'], row['outputs_size'], row['outputs_shape'], parent_op+"_MaxPool", index
    return " "

def map_conv_maxpool(ip_df):
    drop_rows_indx=[]
    for index, row in ip_df.iterrows():
        if row["opType"] in ["Conv", "Conv_Relu", "ConvD_Relu", "ConvG_Relu"]:
            if get_op_maxpool(ip_df, row['outputs'], row["opType"]) != " ":
                ip_df.loc[index,'outputs'], ip_df.at[index,'outputs_size'], ip_df.at[index,'outputs_shape'], ip_df.loc[index,'opType'], drop_indx=get_op_maxpool(ip_df, row['outputs'], row["opType"])
                drop_rows_indx.append(drop_indx)
    ip_df = ip_df.drop(drop_rows_indx)
    return ip_df

def get_weights_shape(model, cnode, opType):
    tensor_shape=[]
    
    if opType in ["Conv", "ConvD", "ConvG", "Gemm"]:
        dq_op = cnode.inputs[1].name
        q_op = None
        q_weight = None
        for node in model.graph.node:
            if node.output[0] == dq_op:
                dq = node
                q_op = node.input[0]
                break
        for node in model.graph.node:
            if node.output[0] == q_op:
                q = node
                q_weight = q.input[0]
                break

        if q_op and not q_weight:           # incase of onnx quantized models where we don't have quant layer, weights are in deuqnat layer
            q_weight = q_op
        elif not q_op and not q_weight:     # incase of fp32 models, where weights are in conv node itself
            q_weight = dq_op
        
        for itm  in model.graph.initializer:
            if itm.name==q_weight:
                tensor_shape=itm.dims
                break

    cleaned_tensor_shape=[int(x) for x in tensor_shape]

    return cleaned_tensor_shape

def has_qdq_optrs(node):
    bool_qdq = False
    
    for i in node.inputs:
        if "QuantizeLinear" in i.name or "DequantizeLinear" in i.name:
            bool_qdq = True
            break  # Exit the loop once a QDQ node is found
    return bool_qdq

def has_zero(list_of_lists):
    for sublist in list_of_lists:
        if 0 in sublist:
            return True
    return False

def generate_oprtrs_ip_op_df(model, out_dir, MODEL_NAME, optimization_flag, dtype, graph):
    scale_map = {"fp32": 4, "bf16": 2, "int8": 1}
    scale = scale_map[dtype]

    column_names = ['model_name', 'itr_no', 'operator_name', 'opType', 'args', 'is_supported', 'inputs', 'num_inputs', 'inputs_shape', 'ifm rank', 'inputs_size_MB', 'outputs', 'outputs_shape', 'outputs_size_MB', 'weights_shape', 'weights_size_MB', 'Wts_superItr', 'ifm_ofm_size_MB', 'IFM_OFM_Spill', 'weights_and_ifm_ofm_mem_issue', 'QDQ_Node_Check', 'Remark']
    operator_ip_op_df = pd.DataFrame(columns=column_names)
    itr_no = 1
    
    for node in graph.nodes:
        operator = {}
        operator['model_name'] = MODEL_NAME
        operator['itr_no'] = itr_no
        itr_no += 1

        if hasattr(node, 'name') and not any(substring in node.name for substring in ["Constant", "Clip_", "strided_slice"]):
            operator['operator_name'] = node.name
            operator_attributes = node.attrs
            
            attributes = ', '.join([f"('{key}', {value})" for key, value in operator_attributes.items() if key not in ['auto_pad', 'storage_order']])
            operator['args'] = attributes
            operator["opType"] = node.op
            group = operator_attributes.get("group", None)
            if not group:
                group = 1

            input_tensor_names = [i.name for i in node.inputs]
            output_tensor_names = [o.name for o in node.outputs]
            if node.op in ['Conv', 'Gemm', 'BatchNormalization', 'LayerNormalization', 'Reshape', 'Equal', 'Gather', 'Squeeze', 'Unsqueeze', 'ReduceSum']:
                input_tensor_names = input_tensor_names[:1]
            operator["inputs_shape"] = tensor_shapes = get_input_output_tensor_shape(model, input_tensor_names)
            operator["outputs_shape"] = get_input_output_tensor_shape(model, output_tensor_names)

            if node.op == 'Cast' and not operator["inputs_shape"]:
                continue
            elif not operator["inputs_shape"] or not operator["outputs_shape"]:
                operator['Remark'] = 'Not Shape Inferred'
            elif has_zero(operator["inputs_shape"]) or has_zero(operator["outputs_shape"]):
                operator['Remark'] = 'Not Shape Inferred'
            else:
                operator['Remark'] = ''

            operator['inputs'] = input_tensor_names
            operator['num_inputs'] = len(input_tensor_names)
            operator['outputs'] = output_tensor_names

            # Add 'ifm rank' column
            operator['ifm rank'] = [len(shape) for shape in operator['inputs_shape']]

            if node.op == "Conv":
                if not tensor_shapes or len(tensor_shapes[0]) < 2:
                    operator["opType"] = 'Conv'
                elif group > 1 and group != tensor_shapes[0][1]:
                    operator["opType"] = 'ConvG'
                elif group > 1 and group == tensor_shapes[0][1]:
                    operator["opType"] = 'ConvD'

            elif node.op in ['Add', 'Mul', 'Div', 'Sub']:
                num_inputs = len(tensor_shapes)
                # merged the inputs lists into a single list: [[1, 80, 72, 72], [1, 80, 1, 1]] -> [1, 80, 72, 72, 1, 80, 1, 1]
                merged_lst = [item for sublist in tensor_shapes for item in sublist]
                if num_inputs > 1 and 0 not in merged_lst:   # if one of the dims = 0 then, the model is not shape inferred
                        for i in range(num_inputs-1):
                            if tensor_shapes[i] != tensor_shapes[i+1]:
                                operator["opType"] = f"Broadcast_{node.op}"
                                break

            if operator["opType"] in ['Conv', 'AveragePool', 'ConvTranspose']:
                kernel_shape = operator_attributes.get("kernel_shape", None)
                strides = operator_attributes.get("strides", None)
                attr = {'kernel_shape': kernel_shape, 'strides': strides}
                operator['is_supported'] = is_opr_supported(node.op, attr, dtype)
            elif operator["opType"] == 'Concat':
                axis = kernel_shape = operator_attributes.get("axis", None)
                attr = {'axis': axis}
                operator['is_supported'] = is_opr_supported(node.op, attr, dtype)
            elif dtype=="int8" and operator["opType"] in support_dict_int8.keys():
                operator['is_supported']=support_dict_int8[operator['opType']]
            elif dtype=='bf16' and operator["opType"] in support_dict_bf16.keys():
                operator['is_supported']=support_dict_bf16[operator['opType']]
            else:
                operator['is_supported'] = 'False'
            
            operator["weights_shape"] = ""
            operator["weights_size"] = 0

            operator["inputs_size"] = 0
            operator["outputs_size"] = 0
            operator["ifm+ofm_size"] = 0

            operator["weights_and_ifm_ofm_mem_issue"] = 0
            operator['weights_shape'] = get_weights_shape(model, node, operator['opType'])
            operator['weights_size'] = get_size([operator['weights_shape']])
            operator['inputs_size'] = get_size(operator['inputs_shape'])
            operator['outputs_size'] = get_size(operator['outputs_shape'])
            if dtype == 'fp32':
                operator['QDQ_Node_Check'] = 'NA'
            else:
                operator['QDQ_Node_Check'] = 'True' if has_qdq_optrs(node) else 'False'
            operator_ip_op_df = pd.concat([operator_ip_op_df, pd.DataFrame([operator])], ignore_index=True)

    operator_ip_op_df = map_conv_relu(operator_ip_op_df)
    operator_ip_op_df = map_qdq(operator_ip_op_df)
    operator_ip_op_df = map_qdq_maxpool(operator_ip_op_df)
    if not optimization_flag or optimization_flag == 'O2':
        operator_ip_op_df = map_add_relu(operator_ip_op_df)
        operator_ip_op_df = map_conv_maxpool(operator_ip_op_df)
    operator_ip_op_df = operator_ip_op_df[~operator_ip_op_df['opType'].str.contains('Q_DQ|Constant|QuantizeLinear|DequantizeLinear')]
    #operator_ip_op_df = operator_ip_op_df[~operator_ip_op_df['outputs'].isin(operator_ip_op_df['combined_outputs'])]
    operator_ip_op_df["ifm_ofm_size"] = (operator_ip_op_df["inputs_size"] + operator_ip_op_df["outputs_size"])
    operator_ip_op_df["ifm_ofm_size_MB"] = round(operator_ip_op_df["ifm_ofm_size"] * scale / (1024 * 1024), 5)
    operator_ip_op_df["IFM_OFM_Spill"] = operator_ip_op_df["ifm_ofm_size_MB"].apply(lambda x: "True" if x > 1.5 else "False")
    operator_ip_op_df["inputs_size_MB"] = round(operator_ip_op_df["inputs_size"] * scale / (1024 * 1024),5)
    operator_ip_op_df["outputs_size_MB"] = round(operator_ip_op_df["outputs_size"] * scale / (1024 * 1024), 5)
    operator_ip_op_df["weights_size_MB"] = round(operator_ip_op_df["weights_size"] * scale / (1024 * 1024), 5)

    operator_ip_op_df['Wts_superItr'] = operator_ip_op_df['weights_size_MB'].apply(lambda x: "True" if x > 1 else "False")

    condition = (operator_ip_op_df["weights_size_MB"] > 1.0) & (operator_ip_op_df["ifm_ofm_size_MB"] > 1.5)
    operator_ip_op_df.loc[condition, 'weights_and_ifm_ofm_mem_issue'] = 1
    operator_ip_op_df.loc[~condition, 'weights_and_ifm_ofm_mem_issue'] = 0
    #operator_ip_op_df["num_inputs"] = operator_ip_op_df["inputs_shape"].apply(len)
    columns_to_drop = ['inputs_size', 'outputs_size']

    operator_ip_op_df = operator_ip_op_df.drop(columns=columns_to_drop)
    operator_ip_op_df.at[0, "model_name"] = MODEL_NAME

    num_blank_rows = 2
    operator_ip_op_df.rename(columns={'inputs_size_MB': "in (MB)"}, inplace=True)
    operator_ip_op_df.rename(columns={'outputs_size_MB': "out (MB)"}, inplace=True)
    operator_ip_op_df.rename(columns={'weights_and_ifm_ofm_mem_issue': "Wts>1MB & FM>1.5"}, inplace=True)
    operator_ip_op_df.rename(columns={'weights_size_MB': "weights (MB)"}, inplace=True)
    operator_ip_op_df.rename(columns={'ifm_ofm_size_MB': "ifm+ofm (MB)"}, inplace=True)
    columns_to_drop_1 = ['weights_size', 'ifm+ofm_size','ifm_ofm_size']

    operator_ip_op_df = operator_ip_op_df.drop(columns=columns_to_drop_1)
    if dtype in ['fp32', 'bf16']:
        operator_ip_op_df = operator_ip_op_df.drop(columns='QDQ_Node_Check')

    operator_ip_op_df.to_excel(os.path.join(out_dir, MODEL_NAME + '.xlsx'), index=False, float_format='%g')
    return operator_ip_op_df

def extract_model_operations(FP32_ONNX_PATH, out_dir, MODEL_NAME, optimization_flag, dtype):
    model = onnx.shape_inference.infer_shapes(onnx.load(FP32_ONNX_PATH))
    graph = gs.import_onnx(onnx.load(FP32_ONNX_PATH))
    check_model(model)
    generate_oprtrs_ip_op_df(model, out_dir, MODEL_NAME, optimization_flag, dtype, graph)
    print("--ip-data-generated---")

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

def analyze_memory(input_dir, out_dir, optimization_flag, dtype, model_names, model_names_dir, reuse):
    csv_file_path = os.path.join(out_dir, 'error.csv')
    folder_path = input_dir 
    out_dir=os.path.join(out_dir,"mem_analysis")
    os.makedirs(out_dir, exist_ok=True)

    file_paths=glob.glob(os.path.join(folder_path, '**/*.onnx'), recursive=True)
    model_names_list = get_model_names(model_names_dir, model_names)
    if dtype not in ["bf16", "int8", 'fp32']:
        print("  dtype not supported ")
        sys.exit(0)

    for file_path in file_paths:
        try:
            
            if len(model_names_list):
                if os.path.basename(file_path).replace(".onnx","") not in model_names_list:
                    continue

            if reuse == "True":
                if os.path.basename(file_path).replace(".onnx",".xlsx") not in os.listdir(out_dir):
                    print("\nGenerating Memory Analysis for:  ")
                    print(file_path)
                    extract_model_operations(file_path, out_dir,os.path.basename(file_path).replace(".onnx",""), optimization_flag, dtype)
                else:
                    continue
            else:
                print("\nGenerating Memory Analysis for:  ")
                print(file_path)
                extract_model_operations(file_path, out_dir,os.path.basename(file_path).replace(".onnx",""), optimization_flag, dtype)


        except Exception as e:
             print(e)
             file_name = file_path[file_path.rfind('/') + 1:]
             with open(csv_file_path, mode='a') as file:
                writer = csv.writer(file)
                writer.writerow(['Memory_analysis', file_name.replace('.onnx', ''), e])

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--config", help="Path to the config json file", required=True)
    args = parser.parse_args()

    with open(args.config, 'r') as json_file:
        config = json.load(json_file)

    analyze_memory(config['input_dir'], config['out_dir'], config['optimization_flag'], config['dtype'], config['model_names'], config['model_names_dir'],  config['reuse'])
