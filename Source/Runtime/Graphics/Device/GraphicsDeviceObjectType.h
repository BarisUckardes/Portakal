#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
	enum class RUNTIME_API GraphicsDeviceObjectType : byte
	{
		Framebuffer,
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
		ResourceTablePool,
		ResourceTableLayout,
		ResourceTable,
		Queue
	};
}
