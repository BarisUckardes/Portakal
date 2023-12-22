#include "DirectXSwapchain.h"
#ifdef PORTAKAL_PLATFORM_WINDOWS
#include <Runtime/DirectX12/Device/DirectXDevice.h>

namespace Portakal
{
	DirectXSwapchain::DirectXSwapchain(const SwapchainDesc& desc, const SharedHeap<GraphicsDevice>& pDevice) : Swapchain(desc)
	{
	}
	void DirectXSwapchain::ResizeCore(const uint16 width, const uint16 height)
	{
	}
	void DirectXSwapchain::OnShutdown()
	{
	}
	bool DirectXSwapchain::PresentCore()
	{
		return false;
	}
	bool DirectXSwapchain::SetFullScreen()
	{
		return false;
	}
	bool DirectXSwapchain::SetWindowed()
	{
		return false;
	}
}
#endif