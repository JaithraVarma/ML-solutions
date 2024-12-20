#!/bin/bash

# Default Configuration Variables
BASE_CONDA_ENV="310"  # Default base conda environment with Python 3.10
LATEST_TA="/proj/rdi-xco/aiebuilds/ryzen-ai/ryzen-ai-TA/release_rai_1_3/ryzenai_release_daily_latest/lnx64"
EXTRA_INDEX_URLS=(
    "http://artifactory.xilinx.com/artifactory/api/pypi/act-pypi-modules/simple"
    "http://xcoartifactory.xilinx.com/artifactory/api/pypi/flexml-pypi/simple"
    "http://xcoartifactory.xilinx.com/artifactory/api/pypi/mllib-wheel/simple"
    "http://xcoartifactory.xilinx.com/artifactory/api/pypi/dlanalyzer-wheel/simple"
    "https://download.pytorch.org/whl/cpu"
    "https://pages.gitenterprise.xilinx.com/FaaSApps/ccache/simple"
)
TRUSTED_HOSTS=(
    "artifactory.xilinx.com"
    "xcoartifactory.xilinx.com"
    "download.pytorch.org"
)

usage() {
    echo "Usage: source ${BASH_SOURCE[0]} [-e <conda_env>] [-p <env_path>] [-t <latest_ta_path>] [-d <whls_with_deps>] [-n <whls_no_deps>]"
    echo "  -e: Base conda environment name (default: $BASE_CONDA_ENV)"
    echo "  -p: FULL Path to install the new environment"
    echo "  -t: FULL Path to the LATEST_TA directory (default: $LATEST_TA)"
    echo "  -d: Comma-separated list of .whl files to install with dependencies"
    echo "  -n: Comma-separated list of .whl files to reinstall without dependencies (THIS WILL TAKE PRECEDENCE)"
    return 1
}

while getopts "e:p:t:n:d:" opt; do
    case "$opt" in
        e) BASE_CONDA_ENV="$OPTARG" ;;
        p) ENV_PATH="$OPTARG" ;;
        t) LATEST_TA="$OPTARG" ;;
        d) WHLS_WITH_DEPS=(${OPTARG//,/ }) ;;
        n) WHLS_NO_DEPS=(${OPTARG//,/ }) ;;
        *) usage ;;
    esac
done

if [[ -z "$ENV_PATH" ]]; then
    echo "Error: -p (environment path) is required."
    usage
    return 1
fi

install_package_no_deps() {
    local package_wheel=$1
    if [[ -n $package_wheel ]]; then
        echo "Installing $package_wheel without dependencies..."
        pip install --no-deps "$package_wheel"
    fi
}

install_package_with_deps() {
    local package_wheel=$1
    if [[ -n $package_wheel ]]; then
        echo "Installing $package_wheel with dependencies..."
        pip install "$package_wheel" \
            $(printf -- "--extra-index-url %s " "${EXTRA_INDEX_URLS[@]}") \
            $(printf -- "--trusted-host %s " "${TRUSTED_HOSTS[@]}")
    fi
}

echo "Activating conda environment $BASE_CONDA_ENV..."
conda activate "$BASE_CONDA_ENV"

echo "Running the installer script to create the base environment..."
cd "$LATEST_TA/wheels/ryzen_ai-1.3.0"
./install_ryzen_ai_1_3.sh -a yes -p "$ENV_PATH" -l
cd -

echo "Activating the new environment at $ENV_PATH..."
source "$ENV_PATH/bin/activate"

for whl in "${WHLS_WITH_DEPS[@]}"; do
    install_package_with_deps "$whl"
done

for whl in "${WHLS_NO_DEPS[@]}"; do
    install_package_no_deps "$whl"
done

echo "Installation completed."
