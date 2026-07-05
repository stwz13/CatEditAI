// Copyright 2022 Tencent
// SPDX-License-Identifier: BSD-3-Clause

#ifndef LAYER_GELU_X86_FMA_H
#define LAYER_GELU_X86_FMA_H

#include "gelu.h"

namespace ncnn {

class GELU_x86_fma : public GELU
{
public:
    GELU_x86_fma();

    virtual int create_pipeline(const Option& opt);
    virtual int forward_inplace(Mat& bottom_top_blob, const Option& opt) const;

protected:
#if NCNN_BF16
    int forward_inplace_bf16s(Mat& bottom_top_blob, const Option& opt) const;
#endif
};

} // namespace ncnn

#endif // LAYER_GELU_X86_FMA_H
