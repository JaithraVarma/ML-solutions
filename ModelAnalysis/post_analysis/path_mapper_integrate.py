import pandas as pd
import os
import re
import json
import argparse
import numpy as np


RED = '\033[91m'
GREEN = '\033[92m'
YELLOW = '\033[93m'
RESET = '\033[0m'



def map_root_folders(test_data,paths):
    unique_suites = test_data['Suite'].unique()
    # Create a dictionary to map suite names to paths
    suite_to_path = {}
    for suite in unique_suites:
        matched_path = next((path for path in paths if suite in path), paths[0]) #paths[0] should be 'NA' , paths[0] should never be used when using it for multi suites
        suite_to_path[suite] = matched_path
    # Add a new column 'root_path' to the dataframe
    test_data['root_path'] = test_data['Suite'].map(suite_to_path)
    return test_data


def extract_paths(test_data,suit_run_name,output_result_path):
    print(f'{GREEN}***'*30)
    print(f'{RESET}')
    for index, row in test_data.iterrows():
        root_folder = row['root_path']
        print(f"current root_folder: {root_folder}")
        test_case_name = row['Test Case Name']
        error_msg = row['Err Message']
        #comment this for all cases, uncomment this for only OFM Mismatch errors
        # if 'OFM mismatch' not in str(error_msg):
        #     continue
        # Form the new path
        new_path = None
        for subdir, dirs, files in os.walk(root_folder):
            dirs[:] = [d for d in dirs if not (d.startswith('TEST_WORK') )]
            if test_case_name in dirs:
                new_path = os.path.join(subdir, test_case_name)
                print(f"{GREEN} Found test case folder '{test_case_name}' in '{new_path}'. {RESET}")
                break

        if new_path is None:
            print(f"{RED} Test case folder '{test_case_name}' not found in any subdirectories of '{root_folder}'. {RESET}")
            continue

        if os.path.exists(new_path):
            # Step 6: List all .OUTPUT files in the directory
            output_files = [f for f in os.listdir(new_path) if f.endswith('.OUTPUT') and suit_run_name in f and 'board' not in f] 
            for output_file in output_files:
                # print(f'{GREEN}***'*30)
                # print(f'{RESET}')
                output_file_path = os.path.join(new_path, output_file)
                test_data.at[index, 'vaiml_log_path'] = output_file_path
                print(f'{GREEN}vaiml  output file path: {output_file_path}') 
                print(f'{RESET}')

            test_case_folders = [d for d in os.listdir(new_path) if suit_run_name in d ]
            test_case_folders = [d for d in test_case_folders if os.path.isdir(os.path.join(new_path, d))]
            
            test_case_folders = [os.path.join(new_path,folder) for folder in test_case_folders]
            # print(test_case_folders)
            test_case_sub_folder = []
            vaiml_partition_path = ""
            for folder in test_case_folders:
                for subdir, dirs, files in os.walk(folder):
                    if 'vaiml_partition_fe.flexml' in dirs:
                        vaiml_partition_path = os.path.join(subdir, 'vaiml_partition_fe.flexml')
                        test_case_sub_folder.append(vaiml_partition_path)
                        print(f"{GREEN}Found 'vaiml_partition_fe.flexml' in '{vaiml_partition_path}'.{RESET}")
                        break
                else:
                    continue
                break

            
            if os.path.exists(vaiml_partition_path):
                aie_unsupported_ops_path = ""
                vaiml_optimized_onnx_path = ""
                fused_viz_json_path = ""

                for subdir, dirs, files in os.walk(vaiml_partition_path):
                    if 'aie_unsupported_original_ops.json' in files:
                        aie_unsupported_ops_path = os.path.join(subdir, 'aie_unsupported_original_ops.json')
                    # print(f"{GREEN}Found 'aie_unsupported_original_ops.json' in '{aie_unsupported_ops_path}'.{RESET}")
                    if 'vaiml_optimized.onnx' in files:
                        vaiml_optimized_onnx_path = os.path.join(subdir, 'vaiml_optimized.onnx')
                    # print(f"{GREEN}Found 'vaiml_optimized.onnx' in '{vaiml_optimized_onnx_path}'.{RESET}")
                    if 'fused.viz.json' in files:
                        fused_viz_json_path = os.path.join(subdir, 'fused.viz.json')
                    # print(f"{GREEN}Found 'fused.viz.json' in '{fused_viz_json_path}'.{RESET}")

                test_data.at[index, 'aie_unsupported_ops_path'] = aie_unsupported_ops_path
                test_data.at[index, 'vaiml_optimized_onnx_path'] = vaiml_optimized_onnx_path
                test_data.at[index, 'fused_viz_json_path'] = fused_viz_json_path
                
            
    print('***'*30)
    test_data = test_data[['Suite','Test Name', 'Task','Status','Err Message','vaiml_log_path','aie_unsupported_ops_path', 'vaiml_optimized_onnx_path','fused_viz_json_path']]
    test_data.to_excel(output_result_path, index=False)
    print(f"output size: {test_data.shape}")
    print(f"{YELLOW} ouput saved at {output_result_path} {RESET}")
    print('***'*30)
    return test_data




def get_paths(csv_path,root_folder,suit_run_name,output_path='./result.xlsx'):
    test_data = pd.read_csv(csv_path) #pd.read_excel('OFM_data.xlsx') #xoah excel file
    root_folder = root_folder #"/proj/rdi-xco/nobkup6/praveeni/csr_only_avgpool/results_313/2025.1_PCIE_BF16_CNN_IPU_P0_ORT_O1_STX_WIN_hw_lin_lin_x86"
    suit_run_name = suit_run_name #"20241003_113200_313" 
    ouput_path = output_path #"/wrk/xcohdnobkup7/smattupa/tolerance_extract/output.xlsx"

    
    test_data = map_root_folders(test_data, root_folder)
    
    test_data['vaiml_log_path'] = ''
    test_data['aie_unsupported_ops_path'] = ''
    test_data['vaiml_optimized_onnx_path'] = ''
    test_data['fused_viz_json_path'] = ''



    try:
        test_data = extract_paths(test_data, suit_run_name, ouput_path)
        return test_data
    except Exception as e:
        print(f"An error occurred: {e}")
    return test_data


