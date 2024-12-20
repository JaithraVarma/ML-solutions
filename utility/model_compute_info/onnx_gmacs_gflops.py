import sys
sys.path.insert(0, '/wrk/ai_regr/heeran/gflops/onnx-tool')

import os
import pandas as pd
import onnx_tool
import argparse
import logging

logging.basicConfig(level=logging.ERROR, format='%(asctime)s - %(levelname)s - %(message)s')

def onnx_model_profile(model_path, save_path):
    model_name = os.path.basename(model_path).replace('.onnx', '')
    profile_filename = os.path.join(save_path, f"{model_name}_profile.csv")

    try:
        onnx_tool.model_profile(model_path, None, None, save_profile=profile_filename)
    except Exception as e:
        logging.error(f"Error generating profile for {model_path}: {e}")
        return

    try:
        df = pd.read_csv(profile_filename)

        df = df[['Name', 'Type', 'Forward_MACs']].rename(columns={
            'Name': 'Op_Name',
            'Type': 'Op_Type',
            'Forward_MACs': 'GMACs'
        })

        df['GMACs'] = df['GMACs'] / 1e9

        op_list = ['Conv', 'ConvTranspose', 'Gemm', 'BatchNormalization', 'MatMul'] 
        df['GFLOPs'] = df.apply(lambda row: 2 * row['GMACs'] if row['Op_Type'] in op_list else row['GMACs'], axis=1)

        total_gflops = df['GFLOPs'].iloc[:-1].sum()
        
        if df['Op_Name'].iloc[-1] == 'Total':
            df.at[df.index[-1], 'GFLOPs'] = total_gflops
            
        gmacs = df['GMACs'].iloc[-1]
        gflops = df['GFLOPs'].iloc[-1]
        
        print(f"Total GMACs: {gmacs}")
        print(f"Total GFLOPs: {gflops}")

        df.to_csv(profile_filename, index=False)

    except Exception as e:
        logging.error(f"Error reading profile file {profile_filename}: {e}")

def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--onnx', required=True, type=str, help='path to onnx file')
    parser.add_argument('--path', default='', type=str, help='Path to save the profile CSV file')
    args = parser.parse_args()

    model_path = args.onnx
    save_path = args.path

    onnx_model_profile(model_path, save_path)

if __name__ == '__main__':
    main()
