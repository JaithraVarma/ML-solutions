# Model Analysis

## Installing the packages needed to run Model Analysis
```sh

 pip install -r requirements.txt
```

## main.py
```sh

 python main.py --config </path/to/the/configFile>
```
### Input: 
Give the path to the configFile when running the command and provide required parameters in the configFile. The configFile contains the following parameters:
- **input_dir**: "Folder path having onnx",
- **out_dir**: "Folder path wher xlsx files will be generated for each model ",
- **analysis**: "Default: provides all analysis. Other Options : operator_analysis, memory_analysis, model_info, program_memory_analysis, onnx_gmacs_gflops",
- **optimization_flag**: "Default: True, means the script will take optimization techniques like fusion into account else False"
- **operators_yaml_dir**: "provide path to the the directory containing the yaml files of the operators which is used for program_memory_analysis",
- **model_names**: "(LEAVE BLANK TO NOT USE) model names for which analysis needed ex. 'ResNet50.onnx, ResNet101.onnx'",
- **model_names_dir**:"(LEAVE BLANK TO NOT USE) Folder path whose sub-dirs names correspond to model names to be considered. ex. AIModelTesting/flexml/vision_onnx/CNN_shortlisted_models",
- **reuse**: "set True if want to use existing analysis xlsx file generated for the models",
- **dtype**: "bf16 or int8"


### Output: 
- generates an excel sheet named model_analysis.xlsx which contains the required analysis.
