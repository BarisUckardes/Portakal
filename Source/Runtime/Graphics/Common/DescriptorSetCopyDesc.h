#pragma once
#include <Runtime/Graphics/Common/DescriptorSetCopyEntry.h>
#include <Runtime/Containers/Array.h>

namespace Portakal
{
	struct RUNTIME_API DescriptorSetCopyDesc
	{
		Array<DescriptorSetCopyEntry> Entries;
	};
}
