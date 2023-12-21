#pragma once
#include <Runtime/Graphics/Texture/TextureFormat.h>
#include <Runtime/Platform/PlatformWindow.h>
#include <Runtime/Graphics/Swapchain/PresentMode.h>

namespace Portakal
{
	class GraphicsDevice;
	struct RUNTIME_API SwapchainDesc
	{
		PresentMode PresentMode;
		byte BufferCount;
		TextureFormat ColorFormat;
		TextureFormat DepthStencilFormat;
		SharedHeap<PlatformWindow> pWindow;
		SharedHeap<GraphicsDevice> pDevice;
	};
}
