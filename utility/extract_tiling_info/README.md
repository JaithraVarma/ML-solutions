## get_tiling_info.py
This script can be used to extract ifm_sv, ofm_sv, wts_sv and iters from tensor_dims.json of all the partitions for a compiled design. 
```
python get_tiling_info.py --config_path </path/to/config.json>>
```
**config.json**: This json should contain the following arguments:
- *basepath*: path to directory which has the vaiml_par_{i} folders for the compiled model. Ex- *'/proj/rdi-xco/fis/results/vitis/2024.1/HEAD/z1aiebuild/VAIML_NEW_FEATURE/VIT_SUBGRAPHS_O2_PHX_LNX_HW/vit_bevformer_tiny/vit_bevformer_sole_r50backbone_batch1_1instance_multipartition/vit_bevformer_sole_r50backbone_batch1_1instance_multipartition-hw-ipu_phx_lnx/TEST_WORK_20241021_044213_IPU_PHX_LNX_flexml_lnx64/vit_bevformer_sole_r50backbone_batch1_1instance/'*
- *num_pars*: number of partitions created for the design. Ex- *6*

**Output**: Excel file with ifm_sv, ofm_sv, wts_sv and iters will be saved in the directory where the script is run.
