import os
import pandas as pd
import re
import json
import argparse
import glob
from extract_partition_info import LogExtractor
from post_pre_compare import pre_post_analyzer
from path_mapper_integrate import get_paths

class Extract_info:
    def __init__(self, df, output_path, is_ta_present, prepost_result):
        self.df = df
        self.is_ta_present = is_ta_present
        self.output_path = output_path
        self.prepost_result =  prepost_result
        self.column_names = [ 
            "No. of ops",
            "GOPs",
            "No. of ops supported by VAIML",
            "% of ops supported by VAIML",
            "GOPs supported by VAIML",
            "% of GOPs supported by VAIML",
            "Number of subgraphs supported by VAIML",
            "No. of operators offloaded by VAIML",
            "% of ops offloaded by VAIML",
            "GOPs offloaded by VAIML",
            "% of GOPs offloaded by VAIML",
            "Number of subgraphs offloaded by VAIML",
            "Number of subgraphs with compilation issue",
            "Number of subgraphs below GOPs% (2%) threshold",
            "No. of ops CPU",
            "No. of ops VAIML"
        ]
        self.additional_columns =[
                            #'Operations_Onnx_Model',
                            "Operations_Model",
                            #"Operations_CPU",
                            #"Operations_Constant",
                            #"Operations_AIE_Partitions",
                            'CpuBecause',
                            'Kernel_Mapped',
                            'Pseudo_Ops',
                            'Templated_Ops',
                            'templatedGraph',
                            'Tosa_Ops',
                            'Xtenn_Ops',
                            'Onnx_Ops',

                        ]
        
    def check_string_presence(self, text, column_name):
        return "True" if column_name.lower() in text.lower() else "False"
        
    def extract_operations_model(self, text):
        lines = text.split('\n')
        operation_start = False
        operation_string = ""
        operation_count = 0
        
        for i, line in enumerate(lines):
            if "Operation statistics for the model" in line:
                # Ensure the line before this contains the required string
                if i > 0 and "vaiml_partition_fe.flexml/OnnxModel.chained_kernel.tosa.mlir" not in lines[i-1]:
                    lines.insert(i, "vaiml_partition_fe.flexml/OnnxModel.chained_kernel.tosa.mlir")
                operation_start = True
                operation_count = 0
                continue
            if operation_start and operation_count < 2:
                operation_count += 1
                continue
            if operation_start:
                if "-----------------------" in line:
                    break

                operation_string += line.strip() + "\n"
        
        return operation_string.strip()
    
    def get_dict(self, string):
        if pd.isna(string):
            return 'NAN'
        temp=re.sub(' ','',string).split('\n')
        if len(temp[0])==0:
            return 'NAN'

        try:
            list_temp=[(','.join(':'.join(','.join(i.split(',')[1:]).split(":")[3:]).split(',')[:-1]),':'.join(','.join(i.split(',')[1:]).split(":")[3:]).split(',')[-1]) for i in temp]
            # list_temp = [(','.join(i.split(',')[:-1]), i.split(',')[-1]) for i in temp]
        except:
            
            list_temp = [(i.split(',')[0],i.split(',')[1]) for i in temp]
        # print(dict(list_temp))
        return dict(list_temp)
    
    def filter_dict(self, dict_inp):
            if dict_inp=='NAN':
                return {}
            new_dict={}
            for i in dict_inp.keys():
                if 'CpuBecause' in i:
                    new_dict[i] = dict_inp[i]
                elif 'kernel' in i:
                    name=re.sub('kernel:','',i)
                    new_dict[name]=dict_inp[i]
                elif 'pseudo-op' in i:
                    name=re.sub('pseudo-op:','',i)
                    new_dict[name]=dict_inp[i]
                elif 'xten_nn' in i:
                    if 'output' in i or 'subgraph' in i:
                        continue
                    name=re.sub('xten_nn.','',i)
                    new_dict[name]=dict_inp[i]
                elif 'templatedGraph' in i:
                    name=re.sub('templatedGraph:','',i)
                    new_dict[name]=dict_inp[i]
                elif 'tosa' in i:
                    name=re.sub('tosa.','',i)
                    new_dict[name]=dict_inp[i]
                elif 'onnx' in i:
                    name=re.sub('onnx.','',i)
                    new_dict[name]=dict_inp[i]
            return new_dict
        
    def extract_info(self, dict_inp):
            # Check for invalid input
            if dict_inp == 'NAN' or dict_inp is None:
                return {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}

            mapped_dict = {
                'CpuBecause': [],
                'Kernel_Mapped': [],
                'Pseudo_Ops': [],
                'Templated_Ops': [],
                'Tosa_Ops': [],
                'Onnx_Ops': [],
                'Xtenn_Ops': [], 
                'templatedGraph': []
            }

            cpubecause_dict = {}
            kernelmapped_dict = {}
            tosa_dict = {}
            xtenn_dict = {}
            onnx_dict = {}
            templatedgraph_dict = {}
            templated_ops_dict = {}
            pseudo_ops_dict = {}

            for i, value in dict_inp.items():
                try:
                    value = int(value)
                except ValueError:
                    value = 0

                if "CpuBecause" in i:
                    mapped_dict['CpuBecause'].append(f"{i}:{value}")
                    if i not in cpubecause_dict:
                        cpubecause_dict[i] = 0
                    cpubecause_dict[i] += value

                elif 'kernel' in i:
                    name = re.sub('kernel:', '', i)
                    if 'Templated' in i:
                        mapped_dict['Templated_Ops'].append(f"{name}:{value}")
                        if i not in templated_ops_dict:
                            templated_ops_dict[i] = 0
                        templated_ops_dict[i] += value
                    else:
                        mapped_dict['Kernel_Mapped'].append(f"{name}:{value}")
                        if i not in kernelmapped_dict:
                            kernelmapped_dict[i] = 0
                        kernelmapped_dict[i] += value
                        
                elif 'pseudo-op' in i:
                    name = re.sub('pseudo-op:', '', i)
                    mapped_dict['Pseudo_Ops'].append(f"{name}:{value}")
                    if i not in pseudo_ops_dict:
                            pseudo_ops_dict[i] = 0
                    pseudo_ops_dict[i] += value
                    
                elif 'templatedGraph' in i:
                    name = re.sub('templatedGraph:', '', i)
                    mapped_dict['templatedGraph'].append(f"{name}:{value}")
                    if i not in templatedgraph_dict:
                            templatedgraph_dict[i] = 0
                    templatedgraph_dict[i] += value
                    
                elif 'tosa' in i:
                    name = re.sub('tosa.', '', i)
                    mapped_dict['Tosa_Ops'].append(f"{name}:{value}")
                    if i not in tosa_dict:
                        tosa_dict[i] = 0
                    tosa_dict[i] += value
                    
                elif 'xten_nn' in i:
                    if 'output' in i or 'subgraph' in i:
                        continue
                    name = re.sub('xten_nn.', '', i)
                    mapped_dict['Xtenn_Ops'].append(f"{name}:{value}")
                    if i not in xtenn_dict:
                        xtenn_dict[i] = 0
                    xtenn_dict[i] += value
                    
                elif 'onnx' in i:
                    name = re.sub('onnx.', '', i)
                    mapped_dict['Onnx_Ops'].append(f"{name}:{value}")
                    if i not in onnx_dict:
                        onnx_dict[i] = 0  # Initialize if not present
                    onnx_dict[i] += value

            return (mapped_dict['CpuBecause'], mapped_dict['Kernel_Mapped'], mapped_dict['Xtenn_Ops'], 
                    mapped_dict['templatedGraph'], mapped_dict['Pseudo_Ops'], mapped_dict['Templated_Ops'], 
                    mapped_dict['Tosa_Ops'], mapped_dict['Onnx_Ops'], 
                    cpubecause_dict, kernelmapped_dict, tosa_dict, xtenn_dict, onnx_dict, templatedgraph_dict, templated_ops_dict, pseudo_ops_dict)
            
                    
        
    def extract_percentage_info(self, log):
            # Regular expression to extract the required information
            pattern1 = r"Number of operators in the model:\s*(\d+)"  # Original pattern to extract number of operators
            pattern2 = r"GOPs of the model:\s*(\d+\.\d+)"  # Existing pattern to extract GOPs
            pattern3 = r"Number of operators supported by VAIML:\s*(\d+)\s*\((\d+\.\d+)%\)"
            pattern4 = r"GOPs supported by VAIML:\s*(\d+\.\d+)\s*\((\d+\.\d+)%\)"
            pattern5 = r"Number of subgraphs supported by VAIML:\s*(\d+)"
            pattern6 = r"Number of operators offloaded by VAIML:\s*(\d+)\s*\((\d+\.\d+)%\)"
            pattern7 = r"GOPs offloaded by VAIML:\s*(\d+\.\d+)\s*\((\d+\.\d+)%\)"
            pattern8 = r"Number of subgraphs offloaded by VAIML:\s*(\d+)"
            pattern9 = r"Number of subgraphs with compilation issue:\s*(\d+)"
            pattern10 = r"Number of subgraphs below GOPs%\s*\(2%\)\s*threshold:\s*(\d+)"

            # New patterns to extract CPU and VAIML operators
            pattern_cpu_vaiml = r"\[Vitis AI EP\] No\. of Operators\s*:\s*CPU\s*(\d+)\s*VAIML\s*(\d+)"

            # Search for the patterns in the log
            match1 = re.search(pattern1, log)
            match2 = re.search(pattern2, log)
            match3 = re.search(pattern3, log)
            match4 = re.search(pattern4, log)
            match5 = re.search(pattern5, log)
            match6 = re.search(pattern6, log)
            match7 = re.search(pattern7, log)
            match8 = re.search(pattern8, log)
            match9 = re.search(pattern9, log)
            match10 = re.search(pattern10, log)
            match_cpu_vaiml = re.search(pattern_cpu_vaiml, log)

            number1, number2 = "", ""
            number3, percent3 = "", ""
            number4, percent4 = "", ""
            number5, number6 = "", ""
            percent6, number7, percent7 = "", "", ""
            number8, number9, number10 = "", "", ""
            cpu_operators, vaiml_operators = "", ""

            if match1:
                number1 = match1.group(1)
            if match2:
                number2 = match2.group(1)
            if match3:
                number3, percent3 = match3.group(1), match3.group(2)
            if match4:
                number4, percent4 = match4.group(1), match4.group(2)
            if match5:
                number5 = match5.group(1)
            if match6:
                number6, percent6 = match6.group(1), match6.group(2)
            if match7:
                number7, percent7 = match7.group(1), match7.group(2)
            if match8:
                number8 = match8.group(1)
            if match9:
                number9 = match9.group(1)
            if match10:
                number10 = match10.group(1)

            # Extract CPU and VAIML operators if found
            if match_cpu_vaiml:
                cpu_operators = match_cpu_vaiml.group(1)
                vaiml_operators = match_cpu_vaiml.group(2)

            # Return extracted values
            return (number1, number2, number3, percent3, number4, percent4, 
                    number5, number6, percent6, number7, percent7, 
                    number8, number9, number10, cpu_operators, vaiml_operators)
            
    def read_excel(self):

        # df = pd.read_excel("/wrk/xcohdnobkup6/srmanthe/ml_solutions/ModelAnalysis/postanalysis/result.xlsx")
        return df[['Test Name', 'vaiml_log_path']].to_dict('records')

    def process_log(self, model_name, output_file_path):
        # Initialize the main data dictionary and operation dictionaries with default values
        data = {"Model Name": model_name}
        cpubecause_dict = {}
        kernelmapped_dict = {}
        tosa_dict = {}
        xtenn_dict = {}
        onnx_dict = {}
        templatedgraph_dict = {}
        templated_ops_dict = {}
        pseudo_ops_dict = {}

        with open(output_file_path, 'r') as file:
            text_data = file.read()

        # Populate the `data` dictionary with column names
        data.update({column_name: self.check_string_presence(text_data, column_name) for column_name in self.column_names})

        # Extract operation model data and apply filtering
        extract_operations_data = self.extract_operations_model(text_data)
        operations_model_data = self.get_dict(extract_operations_data)
        data["Operations_Model"] = self.filter_dict(operations_model_data)

        # Attempt to extract various operation types and catch potential issues
        try:
            (data['CpuBecause'], data['Kernel_Mapped'], data['Xtenn_Ops'], data['templatedGraph'],
             data['Pseudo_Ops'], data['Templated_Ops'], data['Tosa_Ops'], data['Onnx_Ops'],
             cpubecause_dict, kernelmapped_dict, tosa_dict, xtenn_dict, onnx_dict, templatedgraph_dict, templated_ops_dict, pseudo_ops_dict) = self.extract_info(operations_model_data)
        except Exception as e:
            print(f"Error in extract_info: {e}")
            # Define defaults for each data point if extraction fails
            data.update({k: None for k in ['CpuBecause', 'Kernel_Mapped', 'Xtenn_Ops', 'templatedGraph',
                                           'Pseudo_Ops', 'Templated_Ops', 'Tosa_Ops', 'Onnx_Ops']})

        # Attempt to extract other percentage-based information
        try:
            (data["No. of ops"], data["GOPs"], data["No. of ops supported by VAIML"], data["% of ops supported by VAIML"],
             data["GOPs supported by VAIML"], data["% of GOPs supported by VAIML"], data["Number of subgraphs supported by VAIML"],
             data["No. of operators offloaded by VAIML"], data["% of ops offloaded by VAIML"], data["GOPs offloaded by VAIML"],
             data["% of GOPs offloaded by VAIML"], data["Number of subgraphs offloaded by VAIML"],
             data["Number of subgraphs with compilation issue"], data["Number of subgraphs below GOPs% (2%) threshold"],
             data["No. of ops CPU"], data["No. of ops VAIML"]) = self.extract_percentage_info(text_data)
        except Exception as e:
            print(f"Error in extract_percentage_info: {e}")
            # Define defaults for each data point if extraction fails
            data.update({k: None for k in ["No. of ops", "GOPs", "No. of ops supported by VAIML", "% of ops supported by VAIML",
                                           "GOPs supported by VAIML", "% of GOPs supported by VAIML", "Number of subgraphs supported by VAIML",
                                           "No. of operators offloaded by VAIML", "% of ops offloaded by VAIML", "GOPs offloaded by VAIML",
                                           "% of GOPs offloaded by VAIML", "Number of subgraphs offloaded by VAIML",
                                           "Number of subgraphs with compilation issue", "Number of subgraphs below GOPs% (2%) threshold",
                                           "No. of ops CPU", "No. of ops VAIML"]})

        return (data, cpubecause_dict, kernelmapped_dict, tosa_dict, xtenn_dict, onnx_dict, templatedgraph_dict, templated_ops_dict, pseudo_ops_dict)

    def main(self):
        # Read model information from the Excel file
        model_info_list = self.read_excel()

        all_data = []
        all_data_2 = []
        partition_data = []

        for model_info in model_info_list:
            model_name = model_info['Test Name']
            output_file_path = model_info['vaiml_log_path']

            # Process each model's log
            (data, cpubecause_dict, kernelmapped_dict, tosa_dict, xtenn_dict, onnx_dict, templatedgraph_dict, templated_ops_dict, pseudo_ops_dict) = self.process_log(model_name, output_file_path)
            all_data_2.append((data["Model Name"], cpubecause_dict, kernelmapped_dict, tosa_dict, xtenn_dict, onnx_dict, templatedgraph_dict, templated_ops_dict, pseudo_ops_dict))
            all_data.append(data)

            # Use LogExtractor to get partition-specific CPU and AIE operations
            log_extractor = LogExtractor()
            log_extractor.process_output_file(output_file_path)
            cpu_ops = log_extractor.partition_wise_cpu_ops
            aie_ops = log_extractor.partition_wise_aie_ops

            # Compile partition data for the 'Partition_Ops' sheet
            partition_row = {"Model": data["Model Name"]}
            for part_num in range(1, 8):
                partition_row[f"Partition_{part_num}_CPU_Ops"] = cpu_ops.get(part_num, 'NAN')
                partition_row[f"Partition_{part_num}_AIE_Ops"] = aie_ops.get(part_num, 'NAN')
            partition_data.append(partition_row)

        if all_data:
            # Save results to Excel
            df = pd.DataFrame(all_data)
            column_order = ["Model Name"] + self.additional_columns + [col for col in self.column_names if col in df.columns]
            df = df[column_order]

            with pd.ExcelWriter(self.output_path, engine='openpyxl') as writer:
                prepost_result.to_excel(writer, index=False, sheet_name = 'Post_Pre_comparative_analysis')
                df.to_excel(writer, index=False, sheet_name='Ops Summary')
                print('Saved excel file at', self.output_path)

                detailed_ops_data = {"Model_Name": [], "Op Category": [], "Op Name": [], "Op Count": [], "Remark": []}
                for model_name, cpubecause_dict, kernelmapped_dict, tosa_dict, xtenn_dict, onnx_dict, templatedgraph_dict, templated_ops_dict, pseudo_ops_dict in all_data_2:
                    for op_category, op_dict in {"CPU Because": cpubecause_dict, "Kernel Mapped": kernelmapped_dict,
                                                 "TOSA": tosa_dict, "Xtenn": xtenn_dict, "ONNX": onnx_dict, "Templated Graph": templatedgraph_dict, 
                                                 "Templated Ops": templated_ops_dict, "Pseudo Ops": pseudo_ops_dict}.items():
                        for op_name, op_count in op_dict.items():
                            detailed_ops_data["Model_Name"].append(model_name)
                            detailed_ops_data["Op Category"].append(op_category)
                            detailed_ops_data["Op Name"].append(op_name)
                            detailed_ops_data["Op Count"].append(op_count)
                            detailed_ops_data["Remark"].append("")
                detailed_ops_df = pd.DataFrame(detailed_ops_data)
                detailed_ops_df.to_excel(writer, index=False, sheet_name='Detailed Operations')

                partition_ops_df = pd.DataFrame(partition_data)
                partition_ops_df.to_excel(writer, index=False, sheet_name='Partition_Ops')
        else:
            print("No matching files found in Excel file.")

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('--config_path', help='Path to config.json file')
    args = parser.parse_args()

    with open(args.config_path, 'r') as json_file:
        config = json.load(json_file)

    csv_path = config["csv_path"]
    root_folder = config["root_folder"]
    suit_run_name = config["suit_run_name"]
    output_path = config["output_path"]
    is_ta_present = config["is_ta_present"]
    df = get_paths(csv_path,root_folder,suit_run_name,output_path='./result.xlsx')
    prepost_result = pre_post_analyzer(config, df)
    a = Extract_info(df, output_path, is_ta_present, prepost_result)
    a.main()
