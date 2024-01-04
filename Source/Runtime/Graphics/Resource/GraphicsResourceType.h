#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
    enum class RUNTIME_API GraphicsResourceType : Byte
    {
        Sampler,
        SampledTexture,
        StorageTexture,
        CombinedTextureSampler,
        ConstantBuffer,
        StorageBuffer
    };
}
