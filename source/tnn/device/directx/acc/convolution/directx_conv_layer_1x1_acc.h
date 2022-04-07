// Tencent is pleased to support the open source community by making TNN available.
//
// Copyright (C) 2020 THL A29 Limited, a Tencent company. All rights reserved.
//
// Licensed under the BSD 3-Clause License (the "License"); you may not use this file except
// in compliance with the License. You may obtain a copy of the License at
//
// https://opensource.org/licenses/BSD-3-Clause
//
// Unless required by applicable law or agreed to in writing, software distributed
// under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
// CONDITIONS OF ANY KIND, either express or implied. See the License for the
// specific language governing permissions and limitations under the License.

#ifndef TNN_SOURCE_TNN_DEVICE_DIRECTX_ACC_DIRECTX_CONV_LAYER_1X1_ACC_H_
#define TNN_SOURCE_TNN_DEVICE_DIRECTX_ACC_DIRECTX_CONV_LAYER_1X1_ACC_H_

#include "tnn/device/directx/acc/convolution/directx_conv_layer_acc_impl.h"
#include "tnn/device/directx/directx_memory.h"

namespace TNN_NS {
namespace directx {

class DirectXConvLayer1x1Acc : public DirectXConvLayerAccImpl {
public:
    static bool IsPrefered(const ConvLayerParam *param, const std::vector<Blob *> &inputs,
                           const std::vector<Blob *> &outputs);

    virtual Status Init(Context *context, LayerParam *param, LayerResource *resource, const std::vector<Blob *> &inputs,
                        const std::vector<Blob *> &outputs) override;

    virtual ~DirectXConvLayer1x1Acc() override;

    virtual Status Reshape(const std::vector<Blob *> &inputs, const std::vector<Blob *> &outputs) override;

    virtual Status DoForward(const std::vector<Blob *> &inputs, const std::vector<Blob *> &outputs) override;

private:

    Status CreateCB(const std::vector<Blob *> &inputs, const std::vector<Blob *> &outputs) ;

    bool stride_is_1_ = false;

    std::shared_ptr<ID3D11Buffer> const_buffer_;
};

}  // namespace directx
}  // namespace TNN_NS

#endif  // TNN_SOURCE_TNN_DEVICE_DIRECTX_ACC_DIRECTX_CONV_LAYER_1X1_ACC_H_
