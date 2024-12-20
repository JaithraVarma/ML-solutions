# VAIQ Model Generator Utility

This utility script generates quantized ONNX models in Vitis AI Pytorch environment.

## Steps to run the script

- Open Vitis AI and activate Pytorch environment. All the below steps are required to run in Vitis AI.
- Clone this repo and change the permissions of VAIQ_model_generator.
```sh
chmod 777 ML_Solutions/VAIQ_model_generator -R
```
- Use models.txt file to add/remove model base class names.
- Use quant_config.json file to provide a quantization configuration.
- Make sure onnx is installed. If not, use the below command:

```sh
pip install onnx
```
## Run Commands:

```sh
python run.py --nndct_use_torch_quantizer --no_tail <True or False> --lyr_trim <Num of layers to be removed from end>

```
- **no_tail** and **lyr_trim** are optional parameters which are to be provided when user is trying to produce a model without its tail.
- --nndct_use_torch_quantizer is required to generate the correct pt files. If you are only generating the onnx files then this is not required.
- The default value fro no_tail is False.
- The default value for lyr_trim is set as 2.
- The required dataset i.e. Imagenet can be obtained from **/proj/ai_datasets/**, This dataset need to be placed in the working directory with the name Imagenet. Here only validation dataset is required so just copying the val folder from imagenet will be enough.

NOTE: Presently the script only supports one version for one model class. Multiple versions will be supported in the future updates.


