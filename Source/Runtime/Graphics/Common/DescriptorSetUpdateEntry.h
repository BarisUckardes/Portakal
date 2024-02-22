#pragma once
#include <Runtime/Graphics/Device/GraphicsDeviceObject.h>
#include <Runtime/Graphics/Descriptor/DescriptorResourceType.h>

namespace Portakal
{
	struct RUNTIME_API DescriptorSetUpdateEntry
	{
		SharedHeap<GraphicsDeviceObject> pResource;
		DescriptorResourceType Type;
		UInt32 Count;
		UInt32 ArrayElement;
		UInt64 BufferOffsetInBytes;
		UInt32 Binding;
	};
}
