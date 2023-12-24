#include "D3DSwapchain.h"

#include <Runtime/D3D12/Device/D3DDevice.h>
#include <Runtime/D3D12/Instance/D3DInstance.h>
#include <Runtime/D3D12/Adapter/D3DAdapter.h>
#include <Runtime/Win32/Win32Window.h>
#include <Runtime/Platform/PlatformMonitor.h>
namespace Portakal
{
	D3DSwapchain::D3DSwapchain(const SwapchainDesc& desc, D3DDevice* pDevice) : Swapchain(desc)
	{
		IDXGIFactory4* factory = ((D3DInstance*)pDevice->GetOwnerAdapter()->GetOwnerInstance())->GetFactory().Get();
		Win32Window* pWindow = (Win32Window*)desc.pWindow.GetHeap();

		if (pWindow->GetWin32WindowHandle() == nullptr)
		{
			DEV_LOG("DirectXSwapchain", "Window handle is nullptr", "Window handle is nullptr");
		}

		DXGI_SWAP_CHAIN_DESC1 swapChainDesc = {};
		swapChainDesc.BufferCount = desc.BufferCount;
		swapChainDesc.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		swapChainDesc.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;
		swapChainDesc.SampleDesc.Count = 1;
		swapChainDesc.SampleDesc.Quality = 0;
		swapChainDesc.Flags = 0;
		swapChainDesc.Width = pWindow->GetSize().X;
		swapChainDesc.Height = pWindow->GetSize().Y;
		swapChainDesc.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		swapChainDesc.AlphaMode = DXGI_ALPHA_MODE_IGNORE;
		swapChainDesc.Scaling = DXGI_SCALING_NONE;
		swapChainDesc.Stereo = false;

		DXGI_SWAP_CHAIN_FULLSCREEN_DESC fullScreenDesc = {};
		fullScreenDesc.RefreshRate.Numerator = pWindow->GetMonitor()->GetCurrentDisplayMode().RefreshRate;
		fullScreenDesc.RefreshRate.Denominator = 1;
		fullScreenDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
		fullScreenDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;

		switch (pWindow->GetMode())
		{
		case WindowMode::Windowed:
		{
			fullScreenDesc.Windowed = true;
			break;
		}
		case WindowMode::Fullscreen:
		{
			fullScreenDesc.Windowed = false;
			break;
		}
		case WindowMode::WindowedBorderless:
		{
			fullScreenDesc.Windowed = true;
			break;
		}
		}

		DEV_SYSTEM(SUCCEEDED(factory->CreateSwapChainForHwnd(
			pDevice->GetGraphicsQueue().Get(),
			pWindow->GetWin32WindowHandle(),
			&swapChainDesc,
			&fullScreenDesc,
			nullptr,
			&mSwapchain)),
			"DirectXSwapchain", "Failed to create DXGISwapchain", "DXGISwapchain has been created succesfully.");
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