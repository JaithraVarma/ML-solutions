import sys
sys.path.insert(0, '/wrk/ai_regr/heeran/gflops/onnx-tool')

import onnx_tool
import csv
import logging
import argparse

# Configure logging
logging.basicConfig(level=logging.INFO, format='%(asctime)s - %(levelname)s - %(message)s')

def generate_profile(onnx_path, profile_path):
    try:  
        onnx_tool.model_profile(onnx_path, None, None, save_profile=profile_path)
        return True
    except Exception as e:
        logging.error(f"Error generating profile for {onnx_path}: {e}")
        return False

def print_type_and_flop(profile_path):
    try:
        with open(profile_path, 'r') as csvfile:
            reader = csv.DictReader(csvfile)
            for row in reader:
                op_type = row['Type']
                forward_macs = int(row['Forward_MACs'])
                if op_type == '_':
                    op_type = 'Total'
                print(f"{op_type}: {(2 * forward_macs) / 1e9}")
    except Exception as e:
        logging.error(f"Error reading profile file {profile_path}: {e}")

def main():
    parser = argparse.ArgumentParser(description='ONNX model to calculate and print GFLOPs.')
    parser.add_argument('--onnx', required=True, type=str, help='Path to the ONNX model file')
    parser.add_argument('--profile', default='model_profile.csv', type=str, help='Path to save the profile CSV file')

    args = parser.parse_args()

    onnx_path = args.onnx
    profile_path = args.profile

    # Generate the profile and GFLOPs
    if generate_profile(onnx_path, profile_path):
        print_type_and_flop(profile_path)

if __name__ == '__main__':
    main()