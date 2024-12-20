########### USER INPUTS ###########
## Usage: Set all the fields below in the User inputs section and then source the file!
ENV_NAME="b2632_new"
BASE_310_CONDA_ENV="310" #Need to have a base python conda env with 3.10 python version and in NFS area

# Version names if left empty, will pick latest from artifactory. For overrides, you can use 1 of the following 2 options:
# 1) Provide a version string (eg: "2024.1+d240603103204.gc9538a55e6")
# 2) Provide a path to the whl file (eg: "/path/to/whl/file")
FLEXML_VERSION=""
ONNXRUNTIME_VERSION=""
VOE_VERSION=""
###################################

conda activate $BASE_310_CONDA_ENV
echo "Printing path of pip being used for craeting a new venv, please verify!"
which pip
python -m venv $ENV_NAME
source $ENV_NAME/bin/activate
echo "Printing path of pip being used after sourcing newly created venv, please verify!"
which pip

INSTALLATION_STR="\
    --extra-index-url https://download.pytorch.org/whl/cpu \
    --extra-index-url https://xcoartifactory.xilinx.com/artifactory/api/pypi/flexml-pypi/simple \
    --extra-index-url https://xcoartifactory.xilinx.com/artifactory/api/pypi/mllib-wheel/simple \
    --extra-index-url https://xcoartifactory.xilinx.com/artifactory/api/pypi/dlanalyzer-wheel/simple \
    --extra-index-url https://xcoartifactory.xilinx.com/artifactory/api/pypi/vai-ml-pypi-local/simple \
    --find-links http://xcoartifactory.xilinx.com/artifactory/flexml-wheel/HEAD \
    --find-links http://xcoartifactory.xilinx.com/artifactory/aie-ipu-dev-local/com/xilinx/vai-ml-artifacts/ \
    --find-links https://xcoartifactory.xilinx.com/artifactory/vai-rt-ipu-prod-local/com/amd/onnx-rt/stx/rai-1.2.1/latest/linux \
    --trusted-host xcoartifactory.xilinx.com"

install_package() {
    PACKAGE_NAME=$1
    PACKAGE_VERSION=$2
    if [ -z "$PACKAGE_VERSION" ]; then
        pip install $PACKAGE_NAME $INSTALLATION_STR
    elif [[ $PACKAGE_VERSION == *.whl ]]; then
        pip install $PACKAGE_VERSION $INSTALLATION_STR
    else
        pip install $PACKAGE_NAME==$PACKAGE_VERSION $INSTALLATION_STR
    fi
}

install_package flexml $FLEXML_VERSION
install_package vaiml~=1.2.1.dev0
install_package vaiml_custom_ops~=1.3.0.dev0
install_package onnxruntime_vitisai $ONNXRUNTIME_VERSION
install_package voe $VOE_VERSION
# pip install --pre "vaiml>1.2.0,<=1.3.0" --extra-index-url https://xcoartifactory.xilinx.com/artifactory/api/pypi/vai-ml-pypi-local/simple --trusted-host xcoartifactory.xilinx.com
# pip install "vaiml_custom_ops~=1.3.0.dev0" --extra-index-url https://xcoartifactory.xilinx.com/artifactory/api/pypi/flexml-pypi/simple --trusted-host xcoartifactory.xilinx.com
echo "Installations done, now starting other env mods..."

#Download and untar onnx-rt to include onnx_perftest file in TA
rm -rf ${ENV_NAME}/onnx-rt
wget https://xcoartifactory.xilinx.com/artifactory/vai-rt-ipu-prod-local/com/amd/onnx-rt/stx/rai-1.2.1/latest/linux/onnx-rt.tar.gz
mkdir ${ENV_NAME}/onnx-rt
tar -xf onnx-rt.tar.gz -C ${ENV_NAME}/onnx-rt
rm -rf onnx-rt.tar.gz

if [ ! -d "VAI-ML" ]; then
    git clone https://gitenterprise.xilinx.com/FaaSApps/VAI-ML.git
else
    cd VAI-ML
    git pull
    cd ..
fi

cp VAI-ML/.github/scripts/setup.sh $ENV_NAME
patch -u $ENV_NAME/bin/activate -i VAI-ML/.github/scripts/activate.patch
patch -u $ENV_NAME/bin/activate.csh -i VAI-ML/.github/scripts/activate.csh.patch

echo "Environemnt has been setup and is ready to use!"

pip show flexml
pip show vaiml
pip show onnxruntime_vitisai
pip show voe