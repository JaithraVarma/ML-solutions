import onnx
from onnxsim import simplify
from onnx import shape_inference
import os
import pandas as pd
import argparse
import glob

def save_onnx_model(model, file_name, do_shape_inference=True):
    if do_shape_inference:
        inferred_model = shape_inference.infer_shapes(model)
    else:
        inferred_model = model
    onnx.save(inferred_model, file_name)

def get_unique_ops(onnx_model):
    ops = set()
    for node in onnx_model.graph.node:
        ops.add(node.op_type)
    return ops

def count_occurrences(onnx_model, op):
    count = sum(1 if node.op_type == op else 0 for node in onnx_model.graph.node)
    return count

def get_count_dict_for_ops(onnx_model, ops_list):
    op_dict = {}
    for node in onnx_model.graph.node:
        if node.op_type in ops_list:
            op_dict[node.op_type] = op_dict.get(node.op_type, 0) + 1
    return op_dict

def simplify_model(onnx_model, file_name, do_shape_inference=True):
    try:
        simplified_model, check = simplify(onnx_model, skip_shape_inference=(not do_shape_inference))
        assert check, "Simplified ONNX model could not be validated"
        return simplified_model
    except Exception as e:
        print(f"Error simplifying model: {e}, File: {file_name}")
        print("Skipping and proceeding")
        return None

def generate_excel(df, output_file):
    with pd.ExcelWriter(output_file, engine='xlsxwriter') as writer:
        average_percentage_reduction = df.groupby('operator')['percentage_reduction'].mean().reset_index()
        model_dict = df.groupby(['operator', 'model_name'])['percentage_reduction'].mean().unstack().reset_index()
        operator_info_df = pd.merge(average_percentage_reduction, model_dict, on='operator', how='outer')
        operator_info_df = operator_info_df.rename(columns={'operator': 'Operator', 'percentage_reduction': 'average_percentage_reduction'})
        model_columns = operator_info_df.columns[2:]
        operator_info_df['model_percentage_reduction'] = operator_info_df.apply(
            lambda row: {model: percentage for model, percentage in zip(model_columns, row[2:]) if not pd.isna(percentage)},
            axis=1
        )
        operator_info_df = operator_info_df.drop(model_columns, axis=1)

        operator_info_df = operator_info_df.sort_values(by='average_percentage_reduction', ascending=False)
        operator_info_df.to_excel(writer, sheet_name='Operator_Info', index=False)
        df.to_excel(writer, sheet_name='Model_Data', index=False)

        unique_model_names = df['model_name'].unique()
        model_names_df = pd.DataFrame({'Model_Name': unique_model_names})
        model_names_df.to_excel(writer, sheet_name='Model_Names', index=False)
        writer.sheets['Model_Names'] = writer.sheets.pop('Model_Names')

        print(f"\nOutput generated at {output_file}\n")

def parse_arguments():
    parser = argparse.ArgumentParser(description="ONNX Model Simplification Analysis")
    parser.add_argument('--input_path', type=str, required=True, help='Path to input ONNX models')
    parser.add_argument('--simplified_models_path', type=str, required=True, help='Directory path to save simplified ONNX models')
    parser.add_argument('--output_excel', type=str, required=True, help='Path to save Excel file with percentage reduced ops and raw data')
    parser.add_argument('--do_shape_inference', type=bool, default=True, help='Flag to control shape inference. Can be disabled for models with dynamic shapes')
    return parser.parse_args()

def main(input_path, simplified_models_path, output_excel, do_shape_inference=True):
    print(f"\nStarting ONNX simplifier analysis with do_shape_inference={do_shape_inference}\n")
    os.makedirs(simplified_models_path, exist_ok=True)

    column_names = ['model_name', 'operator', 'initial_count', 'simplified_count', 'percentage_reduction']
    df = pd.DataFrame(columns=column_names)

    for file_name in glob.glob(os.path.join(input_path, "*.onnx")):
        if os.path.basename(file_name).endswith('.onnx'):
            onnx_model = onnx.load(file_name)

            unique_ops = get_unique_ops(onnx_model)
            initial_dict = get_count_dict_for_ops(onnx_model, unique_ops)

            simplified_model = simplify_model(onnx_model, file_name, do_shape_inference=do_shape_inference)
            if simplified_model is None:
                continue
            simplified_dict = get_count_dict_for_ops(simplified_model, unique_ops)

            save_onnx_model(simplified_model, os.path.join(simplified_models_path, os.path.splitext(os.path.basename(file_name))[0] + "_simplified.onnx"), do_shape_inference=do_shape_inference)

            percentage_reduced = {}
            for op in unique_ops:
                initial_count = initial_dict.get(op, 0)
                simplified_count = simplified_dict.get(op, 0)
                percentage_reduction = 100 - ((simplified_count / initial_count) * 100) if initial_count != 0 else 0
                percentage_reduced[op] = percentage_reduction
                row = {
                    'model_name': os.path.splitext(os.path.basename(file_name))[0],
                    'operator': op,
                    'initial_count': initial_count,
                    'simplified_count': simplified_count,
                    'percentage_reduction': percentage_reduction
                }
                df = pd.concat([df, pd.DataFrame([row], columns=column_names)], ignore_index=True)
    generate_excel(df, output_excel)

if __name__ == "__main__":
    args = parse_arguments()
    main(args.input_path, args.simplified_models_path, args.output_excel, args.do_shape_inference)
