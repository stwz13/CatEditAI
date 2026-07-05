#!/bin/bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "$0")/../.." && pwd)"
NCNN_ROOT="${ROOT_DIR}/third_party/ncnn"
SOURCE_DIR="${NCNN_ROOT}/source"

if [ ! -f "${SOURCE_DIR}/CMakeLists.txt" ]; then
    echo "ncnn source not found. Clone it first:"
    echo "  git clone --depth 1 https://github.com/Tencent/ncnn.git ${SOURCE_DIR}"
    exit 1
fi

KIT_NAME="${1:-$(basename "${PWD}")}"
BUILD_DIR="${NCNN_ROOT}/build/${KIT_NAME}"

mkdir -p "${BUILD_DIR}"
cd "${BUILD_DIR}"

cmake "${NCNN_ROOT}" \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_INSTALL_PREFIX="${BUILD_DIR}/install"

cmake --build . --parallel "$(nproc)"
cmake --install .

mkdir -p "${BUILD_DIR}/lib"
if ls "${BUILD_DIR}/install/lib/"libncnn.so* 1>/dev/null 2>&1; then
    cp -a "${BUILD_DIR}/install/lib/"libncnn.so* "${BUILD_DIR}/lib/"
else
    find "${BUILD_DIR}" -name 'libncnn.so*' -exec cp -a {} "${BUILD_DIR}/lib/" \;
fi

echo "ncnn built into ${BUILD_DIR}"
