This folder contains two scripts: one to extract vaiml run details for a given suite, and second to compare two different vaiml runs/suites.

## extract_run_details.py
This script can be used to extract various information from the .OUTPUT files (logs) for various models present in a suite.
```
python extract_run_details.py --config_path </path/to/extraction_config.json>>
```
**extraction_config.json**: This json should contain the following arguments:
- *directory_path*: Path to directory where the log files of the models are present.
- *output_excel_path*: Path of directory where the output excel file with all details is to be saved.
- *suite_name*: Name of the suite.
- *date*: The date for which the .OUTPUT files should be considered (Ex: '20240613).
- *suite_index*: The index of the suite (for considering multiple runs in a day).
Ex- *TEST_WORK_vaiml_20240613_190055_ta_cust_IPU_PHX_LNX_flexml_lnx64.OUTPUT*: here '20240613' is the date and '190055' is the suite_index. 
Note- Suite_index will be same for all the models in a suite.
- *is_ta_present*: Set as True if 'ta' should be present in the name of the .OUTPUT file, otherwise set False. Default = True.

**Output**: Excel file with run details of all models in the suite saved in 'output_dir' with name 'vaiml_run_details_{suite_name}.xlsx'.

## compare_vaiml_runs.py
This scripts takes as input 2 excel files (generated using *extract_run_details.py*), corresponding to / containing vaiml run details for two different suites. 
```
python compare_vaiml_runs.py --config_path </path/to/comparison_config.json>>
```

**comparison_config.json**: this json contains the following arguments:
- *excel_suite1_path*: path to excel file containing run details for suite1.
- *excel_suite2_path*: path to excel file containing run details for suite2.
- *suite1_name*: name of suite 1.
- *suite2_name*: name of suite 2.
- *output_dir*: path to directory where the comparison excel file is to be saved.

**Output**: excel file with *comparison of all models in the suite2 w.r.t suite1* saved in 'output_dir' with name 'vaiml_run_comparison_{suite2_name}_vs_{suite1_name}.xlsx'.

