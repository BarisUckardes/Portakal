#pragma once
#include <Runtime/Graphics/Descriptor/DescriptorSetLayout.h>
#include <Runtime/Graphics/Descriptor/DescriptorPool.h>
#include <Runtime/Memory/SharedHeap.h>

namespace Portakal
{
	struct RUNTIME_API DescriptorSetDesc
	{
		SharedHeap<DescriptorSetLayout> pLayout;
		SharedHeap<DescriptorPool> pPool;
	};
}
