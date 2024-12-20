# GMAC Calculations:

### Using Onnx Model:
This script requires you to be in the flexml environment. Activate flexml env by using following commands:
```
export XILINX_FLEXML=/proj/rdi-xco/aiebuilds/ryzen-ai/ryzen-ai-TA/main/ryzenai_main_daily_latest/lnx64/
source ${XILINX_FLEXML}/bin/activate
```
Currently the script only takes the GMAC from **Conv, ConvTranspose, Gemm, MatMul & BatchNorm** operator into consideration.
```
python onnx_mac.py --onnx <path/to/your/onnx/model> --json <path to tensor_dims.json file>
```

**--onnx**: Give the path to your onnx model whose GMAC is to be calculated.

**--json**: (Optional) only operators present in tensor_dims.json file will contribute to the GMAC count.

**--mlir**: (Optional) only operators present in dse.mlir or tosa.mlir file will contribute to the GMAC count.
