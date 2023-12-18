#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
	enum class RUNTIME_API GraphicsDeviceObjectType : byte
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
		ResourceTablePool,
		ResourceTableLayout,
		ResourceTable,
		Queue
	};
}
