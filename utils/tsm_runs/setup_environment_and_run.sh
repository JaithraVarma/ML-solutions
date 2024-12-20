#!/bin/bash

# Set environment name and wheel file path
ENV_NAME="mixed_whl"
WHL_FILE_LINK="http://xiractjenmstr01.xilinx.com:8080/view/FlexML%20Jobs/job/FlexML_Nightly/1558/artifact/flexml-2024.1+d231219174546.g89663dba8d-py3-none-any.whl"
JSON_PATH="$PWD/env.json"

mkdir -p "$ENV_NAME"
rm -rf flexml*.whl
wget "$WHL_FILE_LINK"
"$PWD/vitis_flexml/scripts/wheel_deployment/download/installScript.sh" "$PWD/$ENV_NAME" "3.8" --local-wheel-folder "$PWD"
cp -r /proj/rdi-xco/xbuilds/flexml/HEAD/INTEGRATION_VERIFIED/plc/ "$ENV_NAME"
/proj/testcases/xtc/tools/PROD/apps/TSM/bin/tsm --release 2024.1 --super-suite-tsd FLEXML_NEW_FEATURE -e -o "$JSON_PATH" -w "$PWD"
