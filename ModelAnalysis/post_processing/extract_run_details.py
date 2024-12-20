import os
import pandas as pd
import re
import json
import argparse

class Extract_info:
    def __init__(self, directory_path, date,suite_number, is_ta_present, output_excel_path):
        self.directory_path = directory_path
        self.date = date
        self.output_excel_path = output_excel_path
        self.suite_number = suite_number
        self.is_ta_present = is_ta_present
        self.column_names = ["Finishing Frontend",
                            "Frontend Tosa passes completed",
                            "Finishing Tiling Engine",
                            "Clustering completed",
                            "Partition passes completed",
                            "Tiling engine passes completed",
                            "Backend passes completed",
                            "aiecompiler completed",
                            "ucodegen completed",
                            "x86 compilation completed",   
                        ]
        self.additional_columns =[
                            #'Operations_Onnx_Model',
                            "Operations_Model",
                            #"Operations_CPU",
                            #"Operations_Constant",
                            #"Operations_AIE_Partitions",
                            'Kernel_Mapped',
                            'Pseudo_Ops',
                            'Templated_Ops',
                            'templatedGraph',
                            'Tosa_Ops',
                            'Xtenn_Ops',
                            'Onnx_Ops',
                            'Number_Nodes_Graph',
                            'Number_Supported_Nodes',
                            "%Supported_Nodes_Model",
                            "Number_Nodes_Part0",
                            "%Supported_Nodes_Part0",
                            "%ops_Aie_Part0"
                        ]
        
    def check_string_presence(self, text, column_name):
        return "True" if column_name.lower() in text.lower() else "False"
        
    def extract_operations_model(self, text):
        lines = text.split('\n')
        operation_start = False
        operation_string = ""
        operation_count = 0
        for line in lines:
            if "Operation statistics for the model" in line:
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
            list_temp=[(':'.join(','.join(i.split(',')[1:]).split(":")[3:]).split(',')[0],':'.join(','.join(i.split(',')[1:]).split(":")[3:]).split(',')[1]) for i in temp]
        except:
            
            list_temp = [(i.split(',')[0],i.split(',')[1]) for i in temp]
            
        return dict(list_temp)
    
    def filter_dict(self, dict_inp):
        if dict_inp=='NAN':
            return {}
        new_dict={}
        for i in dict_inp.keys():
            if 'kernel' in i:
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
        if dict_inp=='NAN':
            return {},{},{},{},{},{},{}
        mapped_dict={}
        mapped_dict['Kernel_Mapped']=[]
        mapped_dict['Pseudo_Ops']=[]
        mapped_dict['Templated_Ops']=[]
        mapped_dict['Tosa_Ops']=[]
        mapped_dict['Onnx_Ops']=[]
        mapped_dict['Xtenn_Ops']=[] 
        mapped_dict['templatedGraph']=[]
        for i in dict_inp.keys():
            if 'kernel' in i:
                name=re.sub('kernel:','',i)
                if 'Templated' in i:
                    mapped_dict['Templated_Ops'].append(name)
                else:
                    mapped_dict['Kernel_Mapped'].append(name)
            elif 'pseudo-op' in i:
                name=re.sub('pseudo-op:','',i)
                mapped_dict['Pseudo_Ops'].append(name)
            elif 'templatedGraph' in i:
                name=re.sub('templatedGraph:','',i)
                mapped_dict['templatedGraph'].append(name)
            elif 'tosa' in i:
                name=re.sub('tosa.','',i)
                mapped_dict['Tosa_Ops'].append(name)
            elif 'xten_nn' in i:
                if 'output' in i or 'subgraph' in i:
                    continue
                name=re.sub('xten_nn.','',i)
                mapped_dict['Xtenn_Ops'].append(name)
            elif 'onnx' in i:
                name=re.sub('onnx.','',i)
                mapped_dict['Onnx_Ops'].append(name)
        return mapped_dict['Kernel_Mapped'],mapped_dict['Xtenn_Ops'],mapped_dict['templatedGraph'],mapped_dict['Pseudo_Ops'],mapped_dict['Templated_Ops'],mapped_dict['Tosa_Ops'],mapped_dict['Onnx_Ops']
        
                
    def extract_percentage_info(self, log):
        # Regular expression to extract the number after the specified string
        pattern1 = r"Number of nodes in the graph:\s*.*?(\d+(?:\.\d+)?)"
        pattern2 = r"Number of nodes supported by VAIML:\s*.*?(\d+(?:\.\d+)?)"
        pattern3 = r"Percentage of supported nodes by VAIML:\s*.*?(\d+(?:\.\d+)?)"
        pattern4 = r"Number of nodes in partition 0:\s*.*?(\d+(?:\.\d+)?)"
        pattern5 = r"Percentage of supported nodes in partition 0:\s*.*?(\d+(?:\.\d+)?)"
        pattern6 = r"(\d+\.\d+)% of operations will run on AIE"
        
        # Search for the pattern in the string
        match1 = re.search(pattern1, log)
        match2= re.search(pattern2, log)
        match3 = re.search(pattern3, log)
        match4 = re.search(pattern4, log)
        match5 = re.search(pattern5, log)
        match6 = re.search(pattern6, log)
        # If a match is found, extract the number
        number1,number2,number3,number4,number5,number6="","","","","",""
        if match1:
            try:
                number1 = match1.group(1)
            except:
                number1=""
        if match2:
            try:
                number2 = match2.group(1)
            except:
                number2=""
        if match3:
            try:
                number3 = match3.group(1)
            except:
                number3=""
        if match4:
            try:
                number4 = match4.group(1)
            except:
                number4=""
        if match5:
            try:
                number5 = match5.group(1)
            except:
                number5=""
        if match6:
            try:
                number6 = match6.group(1)
            except:
                number6=""
        return number1,number2,number3,number4,number5,number6
        
    def process_log(self, output_directory):
        for file_name in os.listdir(output_directory):
            if file_name.endswith(".OUTPUT") and self.date in file_name and self.suite_number in file_name and "board" not in file_name:
                if self.is_ta_present == 'False' and 'ta' in file_name:
                    continue
                print(file_name)
                file_path = os.path.join(output_directory, file_name)
                with open(file_path, 'r') as file:
                    text_data = file.read()
                data = {column_name: self.check_string_presence(text_data, column_name) for column_name in self.column_names}
                data["Model Name"] = os.path.basename(output_directory)
                
                extract_operations_data= self.extract_operations_model(text_data)
                
                operations_model_data= self.get_dict(extract_operations_data)
                
                data["Operations_Model"] = self.filter_dict(operations_model_data)
                
                data['Kernel_Mapped'],data['Xtenn_Ops'],data['templatedGraph'],data['Pseudo_Ops'],data['Templated_Ops'],data['Tosa_Ops'],data['Onnx_Ops']= self.extract_info(operations_model_data)
                
                data['Number_Nodes_Graph'],data['Number_Supported_Nodes'],data["%Supported_Nodes_Model"],data["Number_Nodes_Part0"],data["%Supported_Nodes_Part0"],data["%ops_Aie_Part0"]= self.extract_percentage_info(text_data)
                
                return data
        return []
        
    def main(self):
        all_data = []
        if os.path.isdir(self.directory_path):
            if len(os.listdir(self.directory_path)) == 0:
                return f"Input directory is Empty"
            
            for sub_dir_name in os.listdir(self.directory_path):
                sub_dir_path = os.path.join(self.directory_path, sub_dir_name)
                
                if not os.path.isdir(sub_dir_path):
                    continue
                
                if sub_dir_name == 'rdi_data' or 'flexml' in sub_dir_name or 'TSM' in sub_dir_name or 'train' in sub_dir_name or 'test' in sub_dir_name:
                    continue
                
                # For Local Runs : sub_dir is the output_directory
                if any(filename.endswith('.OUTPUT') for filename in os.listdir(sub_dir_path)):
                    is_output_directory = True
                    data = self.process_log(sub_dir_path)
                    all_data.append(data)
                    
                else:
                    is_output_directory = False
                
                
                # For XOAH Runs: sub_dir is not output_directory, it just has one folder for the model

                if not is_output_directory:
                    subdirs = os.listdir(sub_dir_path)
                    sub_dir_name = [subdir_name for subdir_name in subdirs if 'lnx' in subdir_name ][0]
                    subdir_path = os.path.join(sub_dir_path, sub_dir_name)
                    data = self.process_log(subdir_path)
                    all_data.append(data)
            all_data = [entry for entry in all_data if entry != []]
            if all_data:
                df = pd.DataFrame(all_data)
                column_order = ["Model Name"] + self.additional_columns + [col for col in self.column_names if col in df.columns]
                df = df[column_order]
                df.to_excel(self.output_excel_path, index = False)
                print('saved excel file at', self.output_excel_path)
                print(f"excel file saved at {self.output_excel_path}")
            else:
                print("No matching files found in subdirectories.")
                
        elif os.path.isfile(self.directory_path):
            pass
        
        else:
            print(f"{self.directory_path} is not a directory or a output file")
            
                        
if __name__=='__main__':
    parser = argparse.ArgumentParser()
    
    parser.add_argument('--config_path', help = 'path to config.json file')
    
    args = parser.parse_args()
     
    with open(args.config_path, 'r') as json_file:
        config = json.load(json_file)
        
    directory_path = config["directory_path"]
    output_dir = config["output_dir"]
    suite_name = config["suite_name"]
    date = config["date"]
    suite_index = config["suite_index"]
    is_ta_present = config["is_ta_present"]
    
    output_excel_path = os.path.join(output_dir, f"vaiml_run_details_{suite_name}.xlsx")
    
    a = Extract_info(directory_path, date, suite_index, is_ta_present, output_excel_path)
    a.main()      
        
# directory_path = '/wrk/ai_regr/sagar_testing/XOAH_Runs/default_run_P0_P1/results/2024.2_PCIE_CNN_IPU_P1_hw_lin_lin_x86/'
# excel_file_path = '/proj/rdi/nobkup6/pukgupta/dev/dev5/vaiml_comp_analysis/excel_files/b.xlsx'
# date="20240417"

# directory_path =  '/proj/rdi-xco/fis/results/vitis/2024.1/z1aiebuild/VAIML_REGRESSION/CNN_IPU_P1_ONNXQ_ORT_O1_PHX_LNX_HW/'
# excel_file_path = '/proj/rdi/nobkup6/pukgupta/dev/dev5/vaiml_comp_analysis/excel_files/m.xlsx'
# date="20240605"

# directory_path = '/wrk/ai_regr/santosh/workspace/ma/xoah/1/results/2024.2_PCIE_CNN_IPU_P0_ONNXQ_ORT_O1_PHX_LNX_hw_lin_lin_x86/
# excel_file_path = '/proj/rdi/nobkup6/pukgupta/dev/dev5/vaiml_comp_analysis/excel_files/cvml_xoah_run.xlsx'
# date = '20240605'