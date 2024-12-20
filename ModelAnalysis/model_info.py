import os
import sys
import csv
import onnx
import pandas as pd

from onnx_checker import OnnxChecker


def get_model_info(model_path):
    model = onnx.load(model_path)
    opset_version = model.opset_import[0].version if len(model.opset_import) > 0 else None
    input_count = len(model.graph.input)
    input_shapes = []
    is_dynamic = False
    dynamic_type = "Not_Dynamic"
   
    for input in model.graph.input:
        input_shapes.append([dim.dim_value for dim in input.type.tensor_type.shape.dim])
        dims = input.type.tensor_type.shape.dim
        is_dynamic, dynamic_type = check_dynamic(dims, is_dynamic, dynamic_type)
        
    output_count = len(model.graph.output)
    output_shapes = []
    for output in model.graph.output:
        output_shapes.append([dim.dim_value for dim in output.type.tensor_type.shape.dim])
        dims = output.type.tensor_type.shape.dim
        is_dynamic, dynamic_type = check_dynamic(dims, is_dynamic, dynamic_type)

    del model
    return opset_version, input_count, input_shapes, output_count, output_shapes, is_dynamic, dynamic_type


def check_dynamic(dims, is_dynamic, dynamic_type):
    '''checks if the model has dynamic shapes and detects if it's dynamic or symbolic'''
    for dim in dims:
        if not is_dynamic:
            if isinstance(dim.dim_param, str) and len(dim.dim_param)>0:
                is_dynamic = True
                if "unk_" in dim.dim_param:
                    dynamic_type = "Dynamic"
                else:
                    dynamic_type = "Symbolic"
    return is_dynamic, dynamic_type

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

def main(config):
    csv_file_path = os.path.join(config['out_dir'], 'error.csv')
    dtype = config['dtype']
    folder_path = config['input_dir']
    model_paths = [os.path.join(folder_path, model) for model in os.listdir(folder_path) if model.endswith('.onnx')]
    df = pd.DataFrame(columns = ['Model Name', 'Opset', 'Input Count', 'Input Shapes', 'Input Dimension', 'Output Count', 'Output Shapes', 'Output Dimension', 'Opset Check (op=17)', 'Inference Check', 'Inference Error', 'zero point check', 'power of 2 check', 'Model Path','Remarks', 'Dynamic Type'])
    problems = {}
    model_names_list = get_model_names(config['model_names_dir'], config['model_names'])
    
    for path in model_paths:
        if len(model_names_list):
            if os.path.basename(path).replace(".onnx", "") not in model_names_list:
                continue
        
        inference_error = None  # Initialize inference_error as None
        
        try:
            onnx_checker = OnnxChecker(path, csv_file_path)
            opset_check = onnx_checker.check_opset()
            inference_check, inference_error = onnx_checker.infer_check()

            if dtype == "int8":
                power_2_check = onnx_checker.check_power_of_two()
                zerp_pt_check = onnx_checker.check_zero_point()
            else:
                power_2_check = "NA"
                zerp_pt_check = "NA"
            model_name = path[path.rfind('/')+1:]
            opset_version, input_count, input_shapes, output_count, output_shapes, is_dynamic, dynamic_type = get_model_info(path)
            
            if len(input_shapes) == 1:
                input_dimension = f"{len(input_shapes[0])}D"
                input_shape_info = input_shapes[0]
            else:
                input_dimension = []
                for shape in input_shapes:
                    input_dimension.append(f"{len(shape)}D")
                input_shape_info = input_shapes

            if len(output_shapes) == 1:
                output_dimension = f"{len(output_shapes[0])}D"
                output_shape_info = output_shapes[0]
            else:
                output_dimension = []
                for shape in output_shapes:
                    output_dimension.append(f"{len(shape)}D")
                output_shape_info = output_shapes

            if len(output_shapes) == 1 and 0 in output_shape_info:
                remark = 'Model output shape is missing'
            elif len(output_shapes) != 1 and 0 in [x for output in output_shapes for x in output]:
                remark = 'Model output shape is missing'
            else:
                remark = None

            temp = [model_name[:-5], opset_version, input_count, input_shape_info, input_dimension, output_count, output_shape_info, output_dimension, opset_check, inference_check, inference_error, zerp_pt_check, power_2_check, path, remark,dynamic_type]
            df.loc[len(df)] = temp
            print(f"Completed I/O shape analysis for: {model_name}")
        
        except Exception as e:
            print(f"{model_name}, {e}")
            problems[model_name] = e
            file_name = path[path.rfind('/') + 1: ]
            with open(csv_file_path, mode='a', newline='') as file:
                writer = csv.writer(file)
                writer.writerow(['model_info_analysis', file_name.replace('.onnx', ''), str(e)])
    
    # Save the DataFrame to Excel
    df.to_excel('model_info.xlsx', index = False)
    print('\n')
    print(f"saved output in model_info.xlsx")
    print('\n')
    
    if len(problems.keys()) == 0:
        print('all models evaluated successfully')
    else:
        print('error occurred while evaluating the following models:', '\n', problems.keys())
