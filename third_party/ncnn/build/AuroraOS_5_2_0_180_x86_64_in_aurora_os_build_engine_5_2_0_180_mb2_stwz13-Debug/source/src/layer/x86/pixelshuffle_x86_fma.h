// Copyright 2026 Tencent
// SPDX-License-Identifier: BSD-3-Clause

#ifndef LAYER_PIXELSHUFFLE_X86_FMA_H
#define LAYER_PIXELSHUFFLE_X86_FMA_H

#include "pixelshuffle.h"

namespace ncnn {

class PixelShuffle_x86_fma : public PixelShuffle
{
public:
    PixelShuffle_x86_fma();

    virtual int forward(const Mat& bottom_blob, Mat& top_blob, const Option& opt) const;
};

} // namespace ncnn

#endif // LAYER_PIXELSHUFFLE_X86_FMA_H
