import sys
sys.path.insert(0, '/wrk/ai_regr/heeran/gflops/onnx-tool')

import os
import pandas as pd
import onnx_tool
import logging

logging.basicConfig(level=logging.ERROR, format='%(asctime)s - %(levelname)s - %(message)s')

def onnx_model_profile(model_path, model_name):
    try:
        profile_csv_filename = f"{model_name}_temp_profile.csv"  
        onnx_tool.model_profile(model_path, None, None, save_profile=profile_csv_filename) # Generate the profile as a temporary CSV
    
    except Exception as e:
        logging.error(f"Error generating profile for {model_path}: {e}")
        return None, str(e)

    try:
        df = pd.read_csv(profile_csv_filename)

        # Rename columns and calculate GMACs
        df = df[['Name', 'Type', 'Forward_MACs']].rename(columns={
            'Name': 'Layer_Name',
            'Type': 'Op_Type',
            'Forward_MACs': 'GMACs'
        })
        df.insert(0, 'Model_Name', model_name)

        df['GMACs'] = df['GMACs'] / 1e9

        
        op_list = ['Conv', 'ConvTranspose', 'Gemm', 'BatchNormalization', 'MatMul'] # Define the operator types for GFLOP calculation
        df['GFLOPs'] = df.apply(lambda row: 2 * row['GMACs'] if row['Op_Type'] in op_list else row['GMACs'], axis=1)

        total_gflops = df['GFLOPs'].iloc[:-1].sum()
        if df['Layer_Name'].iloc[-1] == 'Total':
            df.at[df.index[-1], 'GFLOPs'] = total_gflops

        os.remove(profile_csv_filename)

        return df, None

    except Exception as e:
        logging.error(f"Error reading or processing profile file for {model_path}: {e}")
        return None, str(e)

def main(config):
    model_directory = config['input_dir']

    all_profiles = []
    onnx_files = [f for f in os.listdir(model_directory) if f.endswith('.onnx')]

    if not onnx_files:
        print(f"No ONNX models found in the directory: {model_directory}")
        return

    for onnx_file in onnx_files:
        model_path = os.path.join(model_directory, onnx_file)
        model_name = os.path.basename(model_path).replace('.onnx', '')
        print(f"Processing: {onnx_file}")
        
        profile_df, error = onnx_model_profile(model_path, model_name)
        if error:
            print(f"Error processing {onnx_file}: {error}")
            # Add the error row for this model in case of error and not generating profile
            error_row = pd.DataFrame({
                'Model_Name': [model_name],
                'Layer_Name': ['Total'],
                'Op_Type': ['_'],
                'GMACs': [error],
                'GFLOPs': [error]
            })
            all_profiles.append(error_row)
            continue
        
        all_profiles.append(profile_df)

    if all_profiles:

        combined_df = pd.concat(all_profiles, ignore_index=True)

        total_rows_df = combined_df[combined_df['Layer_Name'] == 'Total'].drop(columns=['Op_Type', 'Layer_Name']) # Create a new DataFrame for model wise scores           
        
        # Save the combined DataFrame as sheets to a single Excel file
        with pd.ExcelWriter('onnx_gmacs_gflops.xlsx') as writer:
            total_rows_df.to_excel(writer, sheet_name='gmac_gflop', index=False)
            combined_df.to_excel(writer, sheet_name='layer_wise_gmac_gflop', index=False)