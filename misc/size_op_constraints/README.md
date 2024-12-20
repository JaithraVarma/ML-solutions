## This script required Python 3.8 (3.8.10 prefered)

- The model to be analysed should be uploaded in the **onnx_model** folder and its name (**excluding .onnx**) should be given as the argument in model_name.

### Download the required packages using:
```
pip install -r requirements.txt
```

### To run the script you can use the command:
```
python memcheck.py --model model_name 
```

### Example:

```
python memcheck.py --model AlexNet 
```
## Optional Arguments:
- **--size**: The size constraint ex: 1500000k (1.5mb) [**Default: 1500000**]
- **--output**: Name of the output file [**Default: analysis.txt**]
- **--mem_check**: For a check for memory constraints. [**Default: True**]
- **--nop_check**: For a check for new operators. [**Default: True**]
- **--smp_check**: For a check for symmetric padding. [**Default: True**]

## Tasks performed by Script:
- Checks memory constraints.
- Gives back new operators in the model.
- Gives back the layer with maximum size (input+output memory).
- Checks for asymmetric padding in layers.
