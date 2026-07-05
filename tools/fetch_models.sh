#!/bin/sh
set -euo pipefail

ROOT="$(cd "$(dirname "$0")/.." && pwd)"
MODEL_DIR="${ROOT}/models"
mkdir -p "${MODEL_DIR}"

curl -fsSL -o "${MODEL_DIR}/mosaic.bin" \
    "https://raw.githubusercontent.com/nihui/ncnn-android-styletransfer/master/app/src/main/assets/mosaic.bin"

echo "Downloaded ${MODEL_DIR}/mosaic.bin"
