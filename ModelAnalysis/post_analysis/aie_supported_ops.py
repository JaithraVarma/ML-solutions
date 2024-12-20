import os
import onnx
import json
import argparse
import pandas as pd

# Extracts the shape of a tensor by its name from the ONNX model
def extract_tensor_shape(model, tensor_name):
    tensor_shape = []

    # Search for the tensor's shape in value_info (intermediate values)
    for itm in model.graph.value_info:
        if itm.name == tensor_name:
            if hasattr(itm.type.tensor_type, 'shape'):
                if hasattr(itm.type.tensor_type.shape, 'dim'):
                    tensor_shape = [dim.dim_value for dim in itm.type.tensor_type.shape.dim]
                    break

    # If not found, search in model inputs and outputs
    if not tensor_shape:
        for inp in model.graph.input:
            if inp.name == tensor_name:
                tensor_shape = [dim.dim_value for dim in inp.type.tensor_type.shape.dim]
        for op in model.graph.output:
            if op.name == tensor_name:
                tensor_shape = [dim.dim_value for dim in op.type.tensor_type.shape.dim]
    return tensor_shape

# Gets the input/output tensor shapes for a list of tensor names
def get_input_output_tensor_shape(model, tensor_names):
    tensor_shapes = []
    for tn in tensor_names:
        tensor_shape = extract_tensor_shape(model, tn)
        if tensor_shape:
            tensor_shapes.append(tensor_shape)
    return tensor_shapes

# Calculates the size of a tensor given its shape (multiplies dimensions)
def get_tensor_size(tensor_shape):
    size = 1
    for dim in tensor_shape:
        if dim:
            size *= dim
    return size

# Traverse all ONNX nodes, extracting information about input/output shapes and sizes
def traverse_onnx_nodes(model, model_name):
    ops_info = []
    dtype_sz = 2  # Data type size in bytes (assuming 16-bit, change if necessary)

    # Iterate through each node (operator) in the model
    for node in model.graph.node:
        op_type = node.op_type
        op_name = node.name
        ifm_shape = []  # Input feature map shapes
        ofm_shape = []  # Output feature map shapes
        ifm_size = 0    # Input feature map size (KB)
        ofm_size = 0    # Output feature map size (KB)

        # Extract input shapes and calculate size
        for inp in node.input:
            shape = extract_tensor_shape(model, inp)
            if shape:
                ifm_shape.append('x'.join(map(str, shape)))  # Format shape as string
                size = get_tensor_size(shape)
                ifm_size += size * dtype_sz / 1024  # Convert size to KB

        # Extract output shapes and calculate size
        for out in node.output:
            shape = extract_tensor_shape(model, out)
            if shape:
                ofm_shape.append('x'.join(map(str, shape)))  # Format shape as string
                size = get_tensor_size(shape)
                ofm_size += size * dtype_sz / 1024  # Convert size to KB

        # Collect node information into a dictionary
        ops_info.append({
            "Model_Name": model_name,
            "Layer_Name": op_name,
            "Operator_Type": op_type,
            "IFM_Shape": ','.join(ifm_shape) if ifm_shape else 'None',
            "IFM_Size(KB)": ifm_size,
            "OFM_Shape": ','.join(ofm_shape) if ofm_shape else 'None',
            "OFM_Size(KB)": ofm_size
        })

    return ops_info

# Checks whether each operator in the model is supported based on a JSON list of unsupported ops
def check_supported_ops(ops_info, unsupported_ops):
    for op in ops_info:
        op_name = op["Layer_Name"]
        op["Is_Supported"] = "False" if op_name in unsupported_ops else "True"
    return ops_info

# Processes a single ONNX model to extract operator info and return the data
def process_model(model_path, unsupported_ops_json, model_name):
    try:
        # Load the ONNX model and infer its shapes
        model = onnx.load(model_path)
        model = onnx.shape_inference.infer_shapes(model)

        # Extract operator information from the model
        ops_info = traverse_onnx_nodes(model, model_name)

        # Load the unsupported operators from JSON file
        with open(unsupported_ops_json, 'r') as f:
            unsupported_ops = json.load(f)

        # Check which operators are supported
        ops_info = check_supported_ops(ops_info, unsupported_ops)

        return ops_info

    except Exception as e:
        # Handle and report errors during model processing
        print(f"Error processing model {model_name} ({model_path}): {e}")
        return []

# Main function to parse arguments and process ONNX models in the directory
def main():
    parser = argparse.ArgumentParser()

    parser.add_argument('--config_path', help='Path to config.json file')
    args = parser.parse_args()

    # Load configuration from JSON file
    with open(args.config_path, 'r') as json_file:
        config = json.load(json_file)

    path = config["suite_path"]
    date = config["suite_date"]
    suite_index = config["suite_index"]
    output_dir = config["output_dir"]

    suite_name = '/'.join(path.rstrip('/').split('/')[-1:])

    # Set the output Excel file path
    output_file = os.path.join(output_dir, f"{suite_name}_aie_supported_ops.xlsx")

    # Initialize a list to collect all operators' information
    all_ops_info = []

    # Traverse files and directories to find models and their unsupported ops JSON files
    files = os.listdir(path)
    for i in files:
        if os.path.isdir(path + i):
            if i == 'rdi_data':
                continue
            new_path = path + i
            new_sub_path = ""
            for sub_file in os.listdir(new_path):
                if os.path.isdir(new_path + '/' + sub_file) and date in sub_file and suite_index in sub_file and 'ta' not in sub_file:
                    new_sub_path = new_path + '/' + sub_file + '/'
                    for j in os.listdir(new_sub_path):
                        if os.path.isdir(new_sub_path + '/' + j):
                            if j not in ['rdi', 'xtc', 'onnx_model']:
                                for k in os.listdir(new_sub_path + '/' + j):
                                    if os.path.isdir(new_sub_path + '/' + j + '/' + k):
                                        if k == 'vaiml_partition_fe.flexml':
                                            model_path = os.path.join(new_sub_path, j, k, 'OnnxModel.onnx')
                                            unsupported_ops_json = os.path.join(new_sub_path, j, k, 'aie_unsupported_original_ops.json')

                                            # Process the model if the required files exist
                                            if os.path.exists(model_path) and os.path.exists(unsupported_ops_json):
                                                ops_info = process_model(model_path, unsupported_ops_json, i)
                                                all_ops_info.extend(ops_info)
                                            else:
                                                # Report missing model or JSON file
                                                if not os.path.exists(model_path):
                                                    print(f"Missing 'OnnxModel.onnx' in folder: {os.path.join(new_sub_path, j, k)}")
                                                if not os.path.exists(unsupported_ops_json):
                                                    print(f"Missing 'aie_unsupported_original_ops.json' in folder: {os.path.join(new_sub_path, j, k)}")

    # Convert the collected operator information to a pandas DataFrame
    df = pd.DataFrame(all_ops_info)

    # Save the DataFrame to an Excel file
    df.to_excel(output_file, index=False)

    print(f"Operator information saved to: {output_file}")

if __name__ == "__main__":
    main()