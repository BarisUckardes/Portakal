#pragma once
#include <Runtime/Graphics/Sampler/SamplerFiltering.h>
#include <Runtime/Graphics/Sampler/SamplerMapMode.h>
#include <Runtime/Graphics/Sampler/SamplerAddressMode.h>
#include <Runtime/Graphics/Sampler/SamplerBorderColor.h>
#include <Runtime/Graphics/Common/CompareOperation.h>

namespace Portakal
{
    struct RUNTIME_API SamplerDesc
    {
        SamplerFiltering MinFilter;
        SamplerFiltering MagFilter;
        SamplerMapMode MipmapMode;
        SamplerAddressMode AddressModeU;
        SamplerAddressMode AddressModeV;
        SamplerAddressMode AddressModeW;
        float MipLodBias;
        float MaxAnisotropy;
        bool ComparisonEnabled;
        CompareOperation CompareOperation;
        float MinLod;
        float MaxLod;
        SamplerBorderColor BorderColor;
    };
}
