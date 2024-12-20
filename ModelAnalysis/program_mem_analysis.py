import os
import csv
import yaml
import onnx
import argparse
import pandas as pd
import numpy as np
import onnx_graphsurgeon as gs

def get_mapping():
    mapping = {'Sqrt': 'Sqrt.yaml',
        'MaxPool': 'MaxPool2d.yaml',
        'Conv': 'Conv2d.yaml',
        'ConvG': 'GroupConv2D.yaml',
        'ConvD': 'DepthwiseConv2d.yaml',
        'BatchNormalization': 'BatchNorm2D.yaml',
        'AveragePool': 'AvgPool2d.yaml',
        'Pad': 'Pad2d.yaml',
        'Mul': 'Mul.yaml',
        'Add': 'Add.yaml',
        'Erf': 'Erf.yaml',
        'ReduceSum': 'ReduceSum.yaml',
        'Sigmoid': 'Sigmoid.yaml',
        'ReduceMean': 'ReduceMean.yaml',
        'Sin': 'Sin.yaml',
        'Squeeze': 'Squeeze.yaml',
        'Transpose': 'Transpose.yaml',
        'Unsqueeze': 'Unsqueeze.yaml',
        'Identity': 'Identity.yaml',
        'Flatten': 'Flatten.yaml',
        'Pow': 'Pow.yaml',
        'Range': 'Range.yaml',
        'GlobalAveragePool': 'GlobalAvgPool2d.yaml',
        'Clip': 'Clip.yaml',
        'Gemm': 'Gemm.yaml',
        'Slice': 'Slice.yaml',
        'Sub': 'Sub.yaml',
        'Div': 'Div.yaml',
        # 'LeakyRelu': 'LeakyRelu.yaml',
        'Tile': 'Tile.yaml',
        'HardSigmoid': 'HardSigmoid.yaml',
        }
    return mapping

def get_operator_details_dict(yaml_folder_path):
    final_dict = {}
    dir_path = yaml_folder_path
    for file in os.listdir(dir_path):
        if not file.endswith('.yaml'):
            continue

        opr = str(file).replace('.yaml', '')
        yaml_file_path = os.path.join(dir_path, file)
        with open(yaml_file_path, 'r') as file:
            yaml_dict = yaml.safe_load(file)
    
        try:
            result_dict = {}
            for constant in yaml_dict['constants']:
            
                if constant['name'] not in ['program_memory', 'stack_size', 'heap_size']:
                    continue
                if 'indexing' not in constant:
                    aie_ml_value = constant['contents']
                elif len(constant['indexing']) == 1:
                    aie_ml_value = list(constant['contents'].values())
                    aie_ml_value = aie_ml_value[0]
                elif len(constant['indexing']) == 2:
                    aie_ml_value = list(constant['contents'].values())
                    aie_ml_value = list(aie_ml_value[0].values())
                    aie_ml_value = aie_ml_value[0]
                elif len(constant['indexing']) == 3:
                    aie_ml_value = list(constant['contents'].values())
                    aie_ml_value = list(aie_ml_value[0].values())
                    aie_ml_value = list(aie_ml_value[0].values())
                    aie_ml_value = aie_ml_value[0]
                else:
                    aie_ml_value = 'NA'
    
                result_dict[constant['name']] = aie_ml_value
    
            for i in ['program_memory', 'stack_size', 'heap_size']:
                if i not in result_dict:
                    result_dict[i] = None
    
            final_dict[opr] = list(result_dict.values())
        except:

            final_dict[opr] = 'yaml file in different format'
    return final_dict
    
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
        if "input" in tensor_name:
            tensor_shape = [dim.dim_value for dim in model.graph.input[0].type.tensor_type.shape.dim]
        #elif "output" in tensor_name:
        #    tensor_shape = [dim.dim_value for dim in model.graph.output[0].type.tensor_type.shape.dim]
        elif 'weight' in tensor_name or 'bias' in tensor_name:
            tensor_shape = [0,0]

    return tensor_shape

def get_input_output_tensor_shape(model, tensor_names):
    tensor_shapes = []
    for tn in tensor_names:
        tensor_shape = extract_tensor_shape(model, tn)
        if tensor_shape:
            tensor_shapes.append(tensor_shape)
    return tensor_shapes

def io_extraction(csv_file, model):
    modelinfo = {}
    graph = gs.import_onnx(model)
    for node in graph.nodes:
        if node.op == 'Conv':
            operator_attributes = node.attrs
            group = operator_attributes.get("group", None)
            if not group:
                group = 1

                
            kernel_shape = operator_attributes.get("kernel_shape", None)
            input_tensor_names = [i.name for i in node.inputs]
            inputs = get_input_output_tensor_shape(model, input_tensor_names)
            if not inputs or len(inputs[0]) < 2:
                opType = 'Conv'
            elif group > 1 and group != inputs[0][1]:
                opType = 'ConvG'
            elif group > 1 and group == inputs[0][1]:
                opType = 'ConvD'
            else:
                opType = 'Conv'

            modelinfo[node.name] = {}
            modelinfo[node.name]['opType'] = opType
            modelinfo[node.name]['input'] = inputs
            modelinfo[node.name]['group'] = group
            modelinfo[node.name]['kernel_shape'] = kernel_shape

    data_list = []
    for node, attributes in modelinfo.items():
        data_list.append({'node': node, **attributes})
    # Create DataFrame
    df = pd.DataFrame(data_list)
    df.to_excel(csv_file, index=False)
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

def mem_analyser(input_dir, operators_yaml_dir, out_dir,model_names,model_names_dir, reuse):
    
    csv_file_path = os.path.join(out_dir, 'error.csv')
    onnx_folder_path = input_dir
    yaml_folder_path = operators_yaml_dir
    output_dir = os.path.join(out_dir, "program_mem_analysis")
    os.makedirs(output_dir, exist_ok=True)

    mapping = get_mapping()
    operator_details_dict = get_operator_details_dict(yaml_folder_path)
    file_paths = [os.path.join(onnx_folder_path, file_name) for file_name in os.listdir(onnx_folder_path)]
    df = pd.DataFrame(columns=['Models', 'opType', 'PM', 'Stack', 'Heap'])
    model_names_list = get_model_names(model_names_dir, model_names)
    for path in file_paths:
        model_name = path[path.rfind('/') + 1:].replace('.onnx', '')
        if len(model_names_list):
                if os.path.basename(path).replace(".onnx","") not in model_names_list:
                    continue
        csv_file = os.path.join(output_dir, model_name + ".xlsx")
        try:
            model = onnx.shape_inference.infer_shapes(onnx.load(path))
            if reuse == "True":
                if not os.path.isfile(csv_file):
                    io_extraction(csv_file, model)
                    print(f"Completed program memory analysis for: {model_name}")
            else:
                io_extraction(csv_file, model)
                print(f"Completed program memory analysis for: {model_name}")
            modelinfo = pd.read_excel(csv_file)
            info_dict = {}
            for index, row in modelinfo.iterrows():
                node = row['node']
                node_dict = {
                    'opType': row['opType'],
                    'input': row['input'],
                    'group': row['group'],
                    'kernel_shape': row['kernel_shape']
                }
                info_dict[node] = node_dict

            opr_lst = []
            for node in model.graph.node:
                if node.op_type == 'Conv':
                    pass
                if node.name in info_dict:
                    operator = info_dict[node.name]['opType']
                else:
                    operator = node.op_type
                if operator not in ['QuantizeLinear','DequantizeLinear', 'Constant', 'Identity']:
                    if operator in mapping.keys():
                        temp_list = []
                        temp_list.append(model_name)
                        temp_list.append(operator)
    
                        details = operator_details_dict[mapping[operator].replace('.yaml', '')]
                        if type(details) == list:
                            temp_list = temp_list + details
                        else:
                            temp_list = temp_list + ['NA', 'NA', 'NA']
                        if operator not in opr_lst:
                            df.loc[len(df)] = temp_list
                            opr_lst.append(operator)
                    else:
                        temp_list = []
                        temp_list.append(model_name)
                        temp_list.append(operator)
                        temp_list = temp_list + ['NA', 'NA', 'NA']
                        if operator not in opr_lst:
                            df.loc[len(df)] = temp_list
                            opr_lst.append(operator)

        except Exception as e:
            print(e)
            with open(csv_file_path, mode='a', newline='') as file:
                writer = csv.writer(file)
                writer.writerow(['program_mem_analysis', model_name, str(e)])


    df.fillna('NA', inplace=True)
    df1 = df.copy()
    df1['Remarks'] = ""
    df.replace(['NA'], np.nan, inplace = True)
    df.fillna(0, inplace=True)
    df['Stack+Heap'] = df['Stack'] + df['Heap']
    grouped = df.groupby('Models').agg({
        'PM': 'sum',
        'opType': lambda x: ', '.join(x),
        'Stack+Heap': 'max',
    })

    grouped['Total Size'] = grouped['PM'] + grouped['Stack+Heap']
    grouped.columns = ['Total PM', 'opType', 'Max(Stack+Heap)', 'Total Size']
    grouped.reset_index(inplace=True)
    grouped['>16KB'] = grouped['Total Size']/1024 > 16
    grouped['Remark'] = ""

    with pd.ExcelWriter('program_mem_analysis.xlsx') as writer:
        df1.to_excel(writer, sheet_name='program_memory_analysis_details', index=False)
        grouped.to_excel(writer, sheet_name='program_memory_analysis_summary', index=False)
    print(f"saved model_analysis.xlsx")

    return
