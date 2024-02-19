#pragma once
#include <Runtime/Graphics/Texture/TextureFormat.h>
#include <Runtime/Platform/PlatformWindow.h>
#include <Runtime/Graphics/Swapchain/PresentMode.h>
#include <Runtime/Graphics/Queue/GraphicsQueue.h>

namespace Portakal
{
	struct RUNTIME_API SwapchainDesc
	{
		PresentMode Mode;
		Byte BufferCount;
		TextureFormat ColorFormat;
		TextureFormat DepthStencilFormat;
		SharedHeap<PlatformWindow> pWindow;
		GraphicsQueue* pQueue;
	};
}
