#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
    enum class RUNTIME_API GraphicsResourceType : byte
    {
        Sampler,
        SampledTexture,
        StorageTexture,
        CombinedTextureSampler,
        ConstantBuffer,
        StorageBuffer
    };
}
