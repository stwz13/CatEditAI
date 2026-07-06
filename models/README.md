# Neural models

## Style transfer

- `mosaic.bin` — Fast Neural Style Transfer (Mosaic), ~3.2 MB  
  Source: [nihui/ncnn-android-styletransfer](https://github.com/nihui/ncnn-android-styletransfer) (BSD 3-Clause)

Network structure is embedded in `src/styletransfer.param.bin.h` from the same project.

## Segmentation (background removal)

- `u2netp.ncnn.param` + `u2netp.ncnn.bin` — U2-NetP salient object segmentation, ~4.5 MB  
  ONNX source: [rembg u2netp](https://github.com/danielgatis/rembg/releases/download/v0.0.0/u2netp.onnx)  
  Original model: [xuebinqin/U-2-Net](https://github.com/xuebinqin/U-2-Net)

Convert ONNX to ncnn with PNNX:

```bash
pip install pnnx
pnnx models/u2netp.onnx inputshape=[1,3,320,320]
```

Or run `./tools/fetch_models.sh` (downloads mosaic.bin and converts u2netp if pnnx is installed).
