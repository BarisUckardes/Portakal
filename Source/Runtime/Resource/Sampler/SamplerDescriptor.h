#pragma once

#include <Runtime/Core/Core.h>
#include <Runtime/Graphics/Sampler/SamplerAddressMode.h>
#include <Runtime/Graphics/Sampler/SamplerFiltering.h>
#include <Runtime/Graphics/Sampler/SamplerMapMode.h>
#include <Runtime/Graphics/Sampler/SamplerBorderColor.h>
#include <Runtime/Graphics/Common/CompareOperation.h>
#include "SamplerDescriptor.reflected.h"

namespace Portakal
{
    PCLASS();
	struct RUNTIME_API SamplerDescriptor
	{
        PFIELD();
        SamplerFiltering mMinFilter;
        PFIELD();
        SamplerFiltering mMagFilter;
        PFIELD();
        SamplerMapMode mMipmapMode;
        PFIELD();
        SamplerAddressMode mAddressModeU;
        PFIELD();
        SamplerAddressMode mAddressModeV;
        PFIELD();
        SamplerAddressMode mAddressModeW;
        PFIELD();
        Float32 mMipLodBias;
        PFIELD();
        Float32 mMaxAnisotropy;
        PFIELD();
        Bool8 mComparisonEnabled;
        PFIELD();
        CompareOperation mCompareOperation;
        PFIELD();
        Float32 mMinLod;
        PFIELD();
        Float32 mMaxLod;
        PFIELD();
        SamplerBorderColor mBorderColor;
	};
}

