import re
import json
import argparse

def get_offsets(mlo_file):
    lines = []
    start_line_pattern = r"std::vector<uint32_t>\s*wts_ddr_offset.*=\s*{.*"
    end_line_pattern = r".*};\s*"

    capturing = False

    with open(mlo_file, 'r') as f:
        for line in f:
            # Check if the line matches the start line pattern
            if not capturing and re.match(start_line_pattern, line.strip()):
                capturing = True

            # Read lines until the end line is found
            if capturing:
                lines.append(line.strip())
                # Check if the line matches the end line pattern
                if re.match(end_line_pattern, line.strip()):
                    break

    return ' '.join(lines)

def get_json_io():
    # Sample input lists
    inputs_list = [
        {
            "name": "compute_graph.ifm_ddr",
            "scale_factor": 0.03125,
            "format": "NHWC",
            "cpu_shape": [1, 224, 224, 4],
            "hw_shape": [1, 224, 224, 4]
        }
    ]

    outputs_list = [
        {
            "name": "compute_graph.ofm_ddr",
            "scale_factor": 0.125,
            "format": "NCHW",
            "cpu_shape": [1, 2048, 1, 1],
            "hw_shape": [1, 2048, 4, 1]
        }
    ]
    return inputs_list, outputs_list

def generate_json(inputs, outputs, offsets):
    json_data = {
        "inputs": inputs,
        "outputs": outputs,
        "weights": {
            "layers": [{"name": f"compute_graph.resnet_layers[{i - 1}].wts_ddr", "offset": offset} for i, offset in enumerate(offsets, start=1)]
        }
    }
    return json.dumps(json_data, indent=4)


def main():
    parser = argparse.ArgumentParser(
        description="Generate a JSON file based on input lists and offsets."
    )
    parser.add_argument(
        "--tiling_path", 
        type=str, required=True, 
        help="Path to the tiling.h file"
    )
    args = parser.parse_args()
    file_path = args.tiling_path

    offsets_string = get_offsets(file_path)
    # Extract numbers between '{' and '}'
    numbers = re.findall(r'{(.*?)}', offsets_string)
    # Split the numbers by commas and convert to integers
    offset_list = [int(num) for num in numbers[0].split(',')]
    inputs_list, outputs_list = get_json_io()
    # Generate JSON
    json_str = generate_json(inputs_list, outputs_list, offset_list)
    # Write the JSON to a file
    output_file_path = "flexmlrt-hsi.json"
    with open(output_file_path, "w") as json_file:
        json_file.write(json_str)

    print(f"JSON data written to {output_file_path}.")

    return 0

if __name__ == '__main__':
    main()


