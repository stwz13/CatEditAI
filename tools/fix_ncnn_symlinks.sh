#!/bin/bash
# Git for Windows cannot index CMake symlinks (libncnn.so). Replace with real copies.
set -euo pipefail

ROOT="$(cd "$(dirname "$0")/.." && pwd)"
BASE="$ROOT/third_party/ncnn/build/AuroraOS_5_2_0_180_x86_64_in_aurora_os_build_engine_5_2_0_180_mb2_stwz13-Debug"

for sub in lib install/lib64 source/src; do
  dir="$BASE/$sub"
  real="$dir/libncnn.so.1.0.20260705"
  [ -f "$real" ] || continue
  for name in libncnn.so libncnn.so.1; do
    link="$dir/$name"
    [ -e "$link" ] && rm -f "$link"
    cp -f "$real" "$link"
  done
done

# Avoid git submodule pointer for cloned ncnn source
if [ -d "$ROOT/third_party/ncnn/source/.git" ]; then
  rm -rf "$ROOT/third_party/ncnn/source/.git"
fi

echo "Done. Run: git add . && git commit -m \"init\" && git push -u origin main"
