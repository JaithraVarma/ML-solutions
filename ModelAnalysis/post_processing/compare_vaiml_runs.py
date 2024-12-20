
import ast
import pandas as pd
import argparse
import json
import os

class Comparison:
    def __init__(self, suite1_name, suite2_name, excel_suite1_path, excel_suite2_path, output_excel_path):
        self.suite1_name = suite1_name
        self.suite2_name = suite2_name
        self.df_suite_1 = pd.read_excel(excel_suite1_path)
        self.df_suite_2 = pd.read_excel(excel_suite2_path)
        self.output_excel_path = output_excel_path
          
    def main(self):
        # column_list = ['Model Name', 'Operations_Model_ORT', 'Operations_Model_ONNXQ_ORT', 'Tosa_Ops_ORT', 'Tosa_Ops_ONNXQ_ORT', 'Onnx_Ops_ORT', 'Onnx_Ops_ONNXQ_ORT', 'Onnx_Ops_ONNXQ_ORT', 'Compare_Onnx_Ops_ONNXQ_vs_ORT', '%Supported_Nodes_Model_ORT', '%Supported_Nodes_Model_ONNXQ', '%offload_Aie_Part0_ORT', '%offload_Aie_Part0_ONNXQ']
        
        
        column_list = ['Model Name', f'Operations_Model_{self.suite1_name}', f'Operations_Model_{self.suite2_name}', f'Tosa_Ops_{self.suite1_name}', f'Tosa_Ops_{self.suite2_name}', f'Onnx_Ops_{self.suite1_name}', f'Onnx_Ops_{self.suite2_name}', f'Compare_Tosa_Ops_{self.suite2_name}_vs_{self.suite1_name}\ndiff = count({self.suite2_name})-count({self.suite1_name})', f'Compare_Onnx_Ops_{self.suite2_name}_vs_{self.suite1_name}\ndiff = count({self.suite2_name})-count({self.suite1_name})', f'%Supported_Nodes_Model_{self.suite1_name}', f'%Supported_Nodes_Model_{self.suite2_name}', f'%offload_Aie_Part0_{self.suite1_name}', f'%offload_Aie_Part0_{self.suite2_name}']
        
        comparison_df = pd.DataFrame(columns = column_list)
        error_dict = dict()
        # comparing suite_2 w.r.t suite_1: => changes in suite_2 w.r.t suite_1 will be highlighted
        for index , row in self.df_suite_2.iterrows():
            model_name = row['Model Name']    # this 'row' corresponds to a specific model in suite2 named 'model_name'
            
            tosa_op_remarks = list()
            onnx_op_remarks = list()
            
            
            
            
            ops_count_dict_suite2 = ast.literal_eval(row['Operations_Model'])
            tosa_ops_list_suite2 = ast.literal_eval(row['Tosa_Ops'])
            onnx_ops_list_suite2 = ast.literal_eval(row['Onnx_Ops'])
            percentage_supported_ops_suite2 = row['%Supported_Nodes_Model']
            percentage_ops_aie_part0_suite2 = row['%ops_Aie_Part0']
            
            #get corresponding model row of 'model_name' from suite_1 df
            model_row = self.df_suite_1[self.df_suite_1['Model Name'] == model_name]
            if not model_row.empty:
                ops_count_dict_suite1 = ast.literal_eval(model_row['Operations_Model'].values[0])
                tosa_ops_list_suite1 = ast.literal_eval(model_row['Tosa_Ops'].values[0])
                onnx_ops_list_suite1 = ast.literal_eval(model_row['Onnx_Ops'].values[0])
                percentage_supported_ops_suite1 = model_row['%Supported_Nodes_Model'].values[0]
                percentage_ops_aie_part0_suite1 = row['%ops_Aie_Part0']
            else:
                error_dict[model_name] = 'not present in suite1 but present in suite1'
                continue
                
            
            for name in tosa_ops_list_suite2:
                tosa_op_count_suite2 = ops_count_dict_suite2[name]
                if name not in tosa_ops_list_suite1:
                    tosa_op_remarks.append(f"{name}: {int(tosa_op_count_suite2)}")
                elif name in tosa_ops_list_suite1:
                    tosa_op_count_suite1 = ops_count_dict_suite1[name]
                    if tosa_op_count_suite1 != tosa_op_count_suite2:
                        tosa_op_remarks.append(f"{name}: {int(tosa_op_count_suite2) - int(tosa_op_count_suite1)}")
                        
            for name in onnx_ops_list_suite2:
                onnx_op_count_suite2 = ops_count_dict_suite2[name]
                if name not in onnx_ops_list_suite1:
                    onnx_op_remarks.append(f"{name}: {int(onnx_op_count_suite2)}")
                    continue
                elif name in onnx_ops_list_suite1:
                    onnx_op_count_suite1 = ops_count_dict_suite1[name]
                    if onnx_op_count_suite1 != onnx_op_count_suite2:
                        onnx_op_remarks.append(f"{name}: {int(onnx_op_count_suite2) - int(onnx_op_count_suite1)}")
                    
            comparison_df.loc[len(comparison_df)] = [model_name, ops_count_dict_suite1, ops_count_dict_suite2, tosa_ops_list_suite1, tosa_ops_list_suite2, onnx_ops_list_suite1, onnx_ops_list_suite2, tosa_op_remarks, onnx_op_remarks, percentage_supported_ops_suite1, percentage_supported_ops_suite2, percentage_ops_aie_part0_suite1, percentage_ops_aie_part0_suite2 ]
        error_df = pd.DataFrame(list(error_dict.items()), columns = ['model_name', 'error'])
        
        
        with pd.ExcelWriter(self.output_excel_path) as writer:
            comparison_df.to_excel(writer, sheet_name = 'Comparison', index = False)
            error_df.to_excel(writer, sheet_name = 'errors', index = False)
        print(f"output excel file saved at {self.output_excel_path}")

if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('--config_path', help="Path to config.json file")
    
    args = parser.parse_args()
    with open(args.config_path, 'r') as json_file:
        config = json.load(json_file)
        
    excel_suite1_path = config["excel_suite1_path"]
    excel_suite2_path = config["excel_suite2_path"]
    suite1_name = config["suite1_name"] 
    suite2_name = config["suite2_name"]
    output_dir = config["output_dir"]
    output_excel_path = os.path.join(output_dir, f"vaiml_run_comparison_{suite2_name}_vs_{suite1_name}.xlsx")
    c = Comparison(suite1_name, suite2_name, excel_suite1_path, excel_suite2_path, output_excel_path)
    c.main()
    
    
    
