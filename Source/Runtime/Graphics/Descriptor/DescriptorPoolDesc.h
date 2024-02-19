#pragma once
#include <Runtime/Core/Core.h>
#include <Runtime/Graphics/Descriptor/DescriptorPoolSize.h>
#include <Runtime/Graphics/Descriptor/DescriptorMemoryType.h>
#include <Runtime/Containers/Array.h>

namespace Portakal
{
	struct RUNTIME_API DescriptorPoolDesc
	{
		DescriptorMemoryType Type;
		Array<DescriptorPoolSize> Sizes;
		UInt64 SetCount;
	};
}
