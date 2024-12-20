# Post Analysis

## Configuration

- **csv_path**: `/path/to/downloaded/csv/from/xoah/input.csv`
- **root_folder**: `["/path/to/suite/roo/folder"]   (eg. ["/wrk/aiml_regr/HEAD/VAIML_REGRESSION/ISV_STX_WIN_HW/"])`
- **suit_run_name**: `suite_run_name as given in xoah   (eg. 20241117_044054_2198)`
- **output_path**: `/path/to/output.xlsx`
- **is_ta_present**: `True or False`
- **dtype**: `int8 or bf16`

## Description

- The CSV file is downloaded from XOAH with the task filter set to VAIML.
- The `suite_run_name` should match the `suite_run_id` as shown in XOAH.
- The `output_path` specifies where the user wants to store the resulting Excel file.

## Usage

1. Ensure the CSV file is located at the specified path.
2. Run the automation script to convert the CSV to an Excel file.
3. The Excel file will be saved at the specified output path.

## Command:

```bash
python extract_run_info.py --config_path extraction_config.json
```

## Notes

- Make sure the `suite_run_name` is correctly set to match the suite run ID from XOAH.
- Verify the output path is correct and accessible.

## Dependencies Installation:

```bash
pip install -r requirements.txt
```
