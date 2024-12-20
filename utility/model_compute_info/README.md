# 1. Model Profile:

### Using Onnx Model:

Script to report node level GFLOPs, find the "model_profile.csv" file to get node level GFLOPs.

To run the script:

```
python model_profile.py --onnx <path/to/your/onnx/model>
```

**--onnx**: Give the path to your onnx model.


# 2. GFLOP Calculations:

Script to calculate the GFLOPs by consedering almost every operators available in the model except ['Identity', 'Constant', 'Shape', 'Squeeze', 'Unsqueeze', 'Reshape', 'ConstantOfShape', 'Cast', 'Pad', 'Concat', 'Slice', 'Gather'].

To run the script:

```
python onnx_flop.py --onnx <path/to/your/onnx/model> --profile <path/to/save/profile>
```

**--onnx**: Give the path to your onnx model whose GFLOPs is to be calculated.

**--profile**: (Optional) path to save the profile CSV file.


# 3. GMAC/GFLOP Calculations:

Script to calculate the layer-wise (Operators) GMACs & GFLOPs.

To run the script:

```
python onnx_gmacs_gflops.py --onnx <path/to/your/onnx/model> --path <path/to/save/csv_profile>
```

**--onnx**: Give the path to your onnx model whose GFLOPs is to be calculated.

**--path**: (Optional) path to save the CSV file.

Read more - [https://pypi.org/project/onnx-tool/](onnx-tool)
