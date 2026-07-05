# ncnn for CatEdit AI

[ncnn](https://github.com/Tencent/ncnn) runs the offline neural style transfer model (Fast Neural Style, ~3.3 MB weights).

## One-time setup

Inside Aurora Build Engine (SSH to `mersdk@localhost`):

```bash
cd /path/to/catedit-aurora
git clone --depth 1 --branch 20240820 https://github.com/Tencent/ncnn.git third_party/ncnn/source
chmod +x third_party/ncnn/build_ncnn.sh
./third_party/ncnn/build_ncnn.sh AuroraOS_5_2_0_180_x86_64_in_aurora_os_build_engine_5_2_0_180_mb2_stwz13-Debug
```

Use your actual kit build folder name (same as under `build/` in Qt Creator).

For a physical device (aarch64), build again with the aarch64 kit directory name.

## Model

- `models/mosaic.bin` — Mosaic style weights (BSD, from [ncnn-android-styletransfer](https://github.com/nihui/ncnn-android-styletransfer))
- Network structure is embedded in `src/styletransfer.param.bin.h`

Input is downscaled for inference (max 512 px), then the result is scaled back to the original resolution — as required by the intensive case.
