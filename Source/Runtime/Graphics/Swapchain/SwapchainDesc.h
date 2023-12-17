#pragma once
#include <Runtime/Graphics/Texture/TextureFormat.h>
#include <Runtime/Platform/PlatformWindow.h>
#include <Runtime/Graphics/Device/GraphicsDevice.h>

namespace Portakal
{
	struct RUNTIME_API SwapchainDesc
	{
		byte BufferCount;
		TextureFormat ColorFormat;
		TextureFormat DepthStencilFormat;
		SharedHeap<PlatformWindow> pWindow;
		SharedHeap<GraphicsDevice> pDevice;
	};
}
