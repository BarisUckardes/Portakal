#pragma once
#include <Runtime/Graphics/Common/DescriptorSetCopyEntry.h>
#include <vector>

namespace Portakal
{
	struct RUNTIME_API DescriptorSetCopyDesc
	{
		Array<DescriptorSetCopyEntry> Entries;
	};
}
