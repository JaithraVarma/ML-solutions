import sys
sys.path.insert(0, '/wrk/ai_regr/heeran/gflops/onnx-tool')

import onnx_tool
import pandas as pd
import argparse
import logging

# Configure logging
logging.basicConfig(level=logging.INFO, format='%(asctime)s - %(levelname)s - %(message)s')

def main():
    try:
        parser = argparse.ArgumentParser(description='Generate ONNX model profile and calculate FLOPs.')
        parser.add_argument('--onnx', required=True, type=str, help='Path to the ONNX model file')
        args = parser.parse_args()

        onnx_path = args.onnx

        onnx_tool.model_profile(onnx_path, None, None, save_profile='model_profile.csv')

        df = pd.read_csv('model_profile.csv')
        df = df[['Name', 'Type', 'Forward_MACs']]
        df['GFLOPs'] = (df['Forward_MACs'] * 2) / 1e9
        df = df.drop(columns=['Forward_MACs'])

        df.to_csv('model_profile.csv', index=False)
        print(f"model_profile.csv saved successfully!")

    except Exception as e:
        logging.error(f"Error generating profile for {onnx_path}: {e}")

if __name__ == '__main__':
    main()