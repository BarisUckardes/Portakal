#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
	enum class RUNTIME_API DescriptorResourceType : Byte
	{
		Sampler,
		SampledTexture,
		StorageTexture,
		ConstantBuffer,
		StorageBuffer
	};
}
