#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
	enum class RUNTIME_API GraphicsDeviceObjectType : Byte
	{
		RenderPass,
		Buffer,
		Texture,
		TextureView,
		Sampler,
		Shader,
		CommandList,
		CommandPool,
		Pipeline,
		Swapchain,
		Fence,
		MemoryHeap,
		DescriptorPool,
		DescriptorLayout,
		DescriptorSet,
		Queue,
		Semaphore
	};
}
