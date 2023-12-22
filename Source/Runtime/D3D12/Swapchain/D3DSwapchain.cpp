#include "D3DSwapchain.h"

#include <Runtime/D3D12/Device/D3DDevice.h>
#include <Runtime/D3D12/Instance/D3DInstance.h>
#include <Runtime/D3D12/Adapter/D3DAdapter.h>
#include <Runtime/Win32/Win32Window.h>
namespace Portakal
{
	D3DSwapchain::D3DSwapchain(const SwapchainDesc& desc, D3DDevice* pDevice) : Swapchain(desc)
	{
		ComPtr<IDXGIFactory4> factory = ((D3DInstance*)pDevice->GetOwnerAdapter()->GetOwnerInstance())->GetFactory();

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
	void D3DSwapchain::ResizeCore(const uint16 width, const uint16 height)
	{
	}
	void D3DSwapchain::OnShutdown()
	{
	}
	bool D3DSwapchain::PresentCore()
	{
		return false;
	}
	bool D3DSwapchain::SetFullScreen()
	{
		return false;
	}
	bool D3DSwapchain::SetWindowed()
	{
		return false;
	}
}