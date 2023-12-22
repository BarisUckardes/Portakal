#include "DirectXSwapchain.h"
#ifdef PORTAKAL_PLATFORM_WINDOWS
#include <Runtime/DirectX12/Device/DirectXDevice.h>
#include <Runtime/DirectX12/Instance/DirectXInstance.h>
#include <Runtime/DirectX12/Adapter/DirectXAdapter.h>
#include <Runtime/Win32/Win32Window.h>
namespace Portakal
{
	DirectXSwapchain::DirectXSwapchain(const SwapchainDesc& desc, DirectXDevice* pDevice) : Swapchain(desc)
	{
		ComPtr<IDXGIFactory4> factory = ((DirectXInstance*)pDevice->GetOwnerAdapter()->GetOwnerInstance())->GetFactory();

		DXGI_SWAP_CHAIN_DESC1 swapChainDesc = {};
		swapChainDesc.BufferCount = desc.BufferCount;
		swapChainDesc.Width = desc.pWindow->GetSize().X;
		swapChainDesc.Height = desc.pWindow->GetSize().Y;
		swapChainDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;
		swapChainDesc.SampleDesc.Count = 1;
		swapChainDesc.SampleDesc.Quality = 0;
		swapChainDesc.Flags = DXGI_SWAP_CHAIN_FLAG_ALLOW_MODE_SWITCH;

		DEV_SYSTEM(SUCCEEDED(factory->CreateSwapChainForHwnd(
			pDevice->GetDevice().Get(),
			((Win32Window*)desc.pWindow.GetHeap())->GetWin32WindowHandle(),
			&swapChainDesc,
			nullptr,
			nullptr,
			&mSwapchain
		)),"DirectXSwapchain", "Failed to create DXGISwapchain", "DXGISwapchain has been created succesfully.");

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