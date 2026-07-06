#!/bin/sh
set -euo pipefail

ROOT="$(cd "$(dirname "$0")/.." && pwd)"
MODEL_DIR="${ROOT}/models"
mkdir -p "${MODEL_DIR}"

curl -fsSL -o "${MODEL_DIR}/mosaic.bin" \
    "https://raw.githubusercontent.com/nihui/ncnn-android-styletransfer/master/app/src/main/assets/mosaic.bin"

ONNX_PATH="${MODEL_DIR}/u2netp.onnx"
if [ ! -f "${ONNX_PATH}" ]; then
    curl -fsSL -o "${ONNX_PATH}" \
        "https://github.com/danielgatis/rembg/releases/download/v0.0.0/u2netp.onnx"
fi

if command -v pnnx >/dev/null 2>&1; then
    pnnx "${ONNX_PATH}" "inputshape=[1,3,320,320]"
    mv -f "${MODEL_DIR}/u2netp.ncnn.param" "${MODEL_DIR}/u2netp.ncnn.param"
    mv -f "${MODEL_DIR}/u2netp.ncnn.bin" "${MODEL_DIR}/u2netp.ncnn.bin"
    echo "Converted U2-NetP to ncnn format"
else
    echo "pnnx not found — install with: pip install pnnx"
    echo "Then run: pnnx ${ONNX_PATH} inputshape=[1,3,320,320]"
fi

echo "Models ready in ${MODEL_DIR}"
