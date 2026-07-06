#!/bin/bash
set -euo pipefail

ROOT_DIR="$(cd "$(dirname "$0")/../.." && pwd)"
OPENCV_ROOT="${ROOT_DIR}/third_party/opencv"
SOURCE_DIR="${OPENCV_ROOT}/source_full"

if [ ! -f "${SOURCE_DIR}/CMakeLists.txt" ]; then
    echo "Full OpenCV source not found. Clone it first:"
    echo "  git clone --depth 1 --branch 4.7.0 https://github.com/opencv/opencv.git ${SOURCE_DIR}"
    exit 1
fi

KIT_NAME="${1:-$(basename "${PWD}")}"
BUILD_DIR="${OPENCV_ROOT}/build/${KIT_NAME}"
INSTALL_DIR="${BUILD_DIR}/opencv"

mkdir -p "${BUILD_DIR}"
cd "${BUILD_DIR}"

cmake "${SOURCE_DIR}" \
    -DCMAKE_BUILD_TYPE=Release \
    -DCMAKE_INSTALL_PREFIX="${INSTALL_DIR}" \
    -DBUILD_LIST=core,imgproc \
    -DBUILD_SHARED_LIBS=ON \
    -DBUILD_TESTS=OFF \
    -DBUILD_PERF_TESTS=OFF \
    -DBUILD_EXAMPLES=OFF \
    -DBUILD_opencv_apps=OFF \
    -DBUILD_opencv_world=OFF \
    -DWITH_OPENMP=OFF \
    -DWITH_IPP=OFF \
    -DWITH_TBB=OFF \
    -DWITH_EIGEN=OFF \
    -DWITH_OPENCL=OFF \
    -DWITH_CUDA=OFF \
    -DWITH_FFMPEG=OFF \
    -DWITH_GTK=OFF \
    -DWITH_JPEG=ON \
    -DWITH_PNG=ON \
    -DCV_ENABLE_INTRINSICS=OFF \
    -DCV_DISABLE_OPTIMIZATION=ON

cmake --build . --parallel "$(nproc)"
cmake --install .

echo "OpenCV installed to ${INSTALL_DIR}"
echo "Verify dependencies:"
readelf -d "${INSTALL_DIR}/lib/libopencv_core.so.407" | grep NEEDED || true
