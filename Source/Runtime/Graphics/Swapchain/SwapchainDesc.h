#pragma once
#include <Runtime/Graphics/Texture/TextureFormat.h>
#include <Runtime/Platform/PlatformWindow.h>

namespace Portakal
{
	struct RUNTIME_API SwapchainDesc
	{
		byte BufferCount;
		TextureFormat ColorFormat;
		TextureFormat DepthStencilFormat;
		SharedHeap<PlatformWindow> pWindow;
	};
}
