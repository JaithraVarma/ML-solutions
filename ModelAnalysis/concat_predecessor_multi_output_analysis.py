import os
import onnx
import onnx_graphsurgeon as gs
import pandas as pd
from collections import Counter

def check_concat_parents(graph):
    nodes_with_multiple_outputs = set()
    for node in graph.nodes:
        if node.op == "Concat":
            for idx in range(len(node.inputs)):
                if hasattr(node.inputs[idx],'values'):
                    continue
                ip_node = node.inputs[idx].inputs[0]
                if len(ip_node.outputs[0].outputs) > 1:
                    while ip_node.op in {"DequantizeLinear", "QuantizeLinear"}:
                        ip_node = ip_node.i() 
                    nodes_with_multiple_outputs.add((ip_node.name, ip_node.op))
    return nodes_with_multiple_outputs

def process_onnx_file(file_path):
    model_name = os.path.basename(file_path)
    res = []
    try:
        original_model = onnx.load(file_path)
        graph = gs.import_onnx(original_model)
        concat_problem_nodes = check_concat_parents(graph)
        res += [(model_name, op, node_name, "Concat Parent Multiple Output Issue") for node_name, op in concat_problem_nodes]
    except Exception as e:
        print(f"Error processing {file_path}: {e}")
    return res

def main(folder_path, output_file):
    results = []
    for file_name in os.listdir(folder_path):
        if file_name.endswith(".onnx"):
            file_path = os.path.join(folder_path, file_name)
            results += process_onnx_file(file_path)

    results = list(set(results))
    file_name_counts = Counter(item[0] for item in results)
    results = [(item[0], item[1], item[2], item[3], file_name_counts[item[0]]) for item in results]
    df = pd.DataFrame(results, columns=["file_name", "problematic_operator", "problematic_node_name", "problem_type", "n_occurences_in_model"])
    df = df.sort_values(by="file_name")
    df.to_excel(output_file, index=False)
    print(f"Results saved to {output_file}")

if __name__ == "__main__":
    folder_path = "/proj/ai_models/topaz_models/fp32/opset-17"
    output_file = "concat_problematic_nodes_topaz.xlsx"
    main(folder_path, output_file)