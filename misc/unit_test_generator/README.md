# Unit Test Generator Utility

This utility script generates the Conv unit test ONNX models.

## Steps to run the script

- Create conda environment

```sh
python3 -m pip install onnx_graphsurgeon --index-url https://pypi.ngc.nvidia.com
pip install onnx
pip install torch
```
## Run Commands:

```sh
python unit_test_gen.py <ONNX file path> <model directory name to save onnx files>

```
NOTE: Presently the script only supports Conv unit test creation. It can be extended to support multiple operators.
