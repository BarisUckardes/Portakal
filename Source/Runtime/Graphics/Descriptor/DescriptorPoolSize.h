#pragma once
#include <Runtime/Graphics/Descriptor/DescriptorResourceType.h>

namespace Portakal
{
	struct RUNTIME_API DescriptorPoolSize
	{
		DescriptorResourceType Type;
		UInt64 Count;
	};
}
