#pragma once
#include <Runtime/Graphics/Common/DescriptorSetUpdateEntry.h>
#include <Runtime/Containers/Array.h>

namespace Portakal
{
	struct RUNTIME_API DescriptorSetUpdateDesc
	{
		Array<DescriptorSetUpdateEntry> Entries;
	};
}
