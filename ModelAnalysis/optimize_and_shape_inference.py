import os
import onnx
from onnx import shape_inference
from onnx import onnx_pb
import onnxruntime as ort

def optimize_onnx_model(file_path, output_filename=None):
    sess_options = ort.SessionOptions()
    base_filename = os.path.splitext(os.path.basename(file_path))[0]
    output_filename = output_filename if output_filename else f"{base_filename}_optimized.onnx"
    sess_options.graph_optimization_level = ort.GraphOptimizationLevel.ORT_ENABLE_BASIC
    sess_options.optimized_model_filepath = output_filename
    session = ort.InferenceSession(file_path, sess_options)
    print("Optimized model saved as:", output_filename)
    infer_shapes(output_filename, output_filename=output_filename)

def validate_onnx_model(model):
    """
    Validate the ONNX model.
    """
    try:
        onnx.checker.check_model(model)
        print("Input ONNX model is valid.")
        return True
    except onnx.onnx_cpp2py_export.checker.ValidationError as e:
        print("Input ONNX model is not valid.")
        print(e)
        return False

def infer_shapes(input_filename, output_filename=None):
    model = onnx.load(input_filename)
    if not validate_onnx_model(model):
        return
    inferred_model = shape_inference.infer_shapes(model, data_prop=True)
    base_filename = os.path.splitext(os.path.basename(input_filename))[0]
    output_filename = output_filename if output_filename else f"{base_filename}_shape_inferred.onnx"
    onnx.save(inferred_model, output_filename)
    print("Shape-inferred model saved as:", output_filename)

def main(input_dir, output_dir):
    if not os.path.exists(output_dir):
        os.makedirs(output_dir)
    for filename in os.listdir(input_dir):
        if filename.endswith(".onnx"):
            input_filepath = os.path.join(input_dir, filename)
            output_filename = f"{os.path.splitext(filename)[0]}_optimized.onnx"
            output_filepath = os.path.join(output_dir, output_filename)
            try:
                optimize_onnx_model(input_filepath, output_filepath)
            except Exception as e:
                print(f"Model {input_filepath} fails with error {e}")
                print("Skipping and continuing ...")

if __name__ == "__main__":
    input_dir = "/proj/ai_models/topaz_models/fp32/opset-17"
    output_dir = "topaz_optimized_for_log"
    main(input_dir, output_dir)

