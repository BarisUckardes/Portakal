#pragma once
#include <Runtime/Graphics/Descriptor/DescriptorSetLayoutEntry.h>
#include <Runtime/Containers/Array.h>

namespace Portakal
{
	struct RUNTIME_API DescriptorSetLayoutDesc
	{
		Array<DescriptorSetLayoutEntry> Entries;
	};
}
