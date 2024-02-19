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
        Float32 MipLodBias;
        Float32 MaxAnisotropy;
        Bool8 bComparisonEnabled;
        CompareOperation CompareOperation;
        Float32 MinLod;
        Float32 MaxLod;
        SamplerBorderColor BorderColor;
    };
}
