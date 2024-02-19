#pragma once
#include <Runtime/Graphics/Texture/TextureFormat.h>
#include <Runtime/Platform/PlatformWindow.h>
#include <Runtime/Graphics/Swapchain/PresentMode.h>
#include <Runtime/Graphics/Queue/GraphicsQueue.h>

namespace Portakal
{
	class GraphicsDevice;
	struct RUNTIME_API SwapchainDesc
	{
		PresentMode PresentMode;
		Byte BufferCount;
		TextureFormat ColorFormat;
		TextureFormat DepthStencilFormat;
		SharedHeap<PlatformWindow> pWindow;
		SharedHeap<GraphicsDevice> pDevice;
		SharedHeap<GraphicsQueue> pQueue;
	};
}
