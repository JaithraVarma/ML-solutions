# Test Suite Management (TSM) USage

## Vitis FlexML TSM Guidelines

Welcome to the documentation to use TSM for FlexML! This script facilitates the setup and execution of tests for Vitis FlexML. Before using this script, please ensure that you have cloned the `vitis_flexml` repository in the same path as this script.

### Prerequisites

- Clone the `vitis_flexml` repository in the same path as this script.
- Modify the repository path in the script according to your paths.

### About

The provided script creates a virtual environment with FlexML installed and initiates a TSM (Test Suite Management) run based on the configurations specified in `env.json`. Preferably, use this script from an XCO NFS area.

#### Usage

1. Set the `ENV_NAME` variable in the script to define the name of the folder for the virtual environment.
2. Provide the link to a nightly wheel file for FlexML installation.
3. Make sure to include the same environment path in `env.json` for `XILINX_FLEXML` value.

#### Running a Full Suite

To run a full suite, include the name of the suite in the `"suite_include_list"` key in `env.json`. Ensure there is no `"test_include_list"` override for this suite (it runs full suite by default).

#### Running Individual Testcases

If you pass a testcase name that does not exist in a suite, no testcases are run. Alternately, if you want to run select testcases, pass the exact names as in XOAH for those testcases.

### Additional Resources

For more detailed information, please refer to the following pages:

- [Test Suite Management (TSM) System User FAQ](https://confluence.xilinx.com/display/SPRITE/Test+Suite+Management+%28TSM%29+System+User+FAQ)
- [Steps for Running FlexML Testcases](https://confluence.xilinx.com/display/XSW/Steps+for+running+Flexml+testcases)

Feel free to explore, contribute, and optimize the Vitis FlexML Test Suite Automation according to your needs! If you encounter any issues or have suggestions, please feel free to contact Praveen Iyer.

Happy testing!