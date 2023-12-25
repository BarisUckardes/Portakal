#include "D3DSwapchain.h"

#include <Runtime/D3D12/Device/D3DDevice.h>
#include <Runtime/D3D12/Instance/D3DInstance.h>
#include <Runtime/D3D12/Adapter/D3DAdapter.h>
#include <Runtime/Win32/Win32Window.h>
#include <Runtime/Platform/PlatformMonitor.h>

#include <Runtime/D3D12/Texture/D3DTextureUtils.h>
#include <Runtime/D3D12/Texture/D3DTexture.h>

namespace Portakal
{
	D3DSwapchain::D3DSwapchain(const SwapchainDesc& desc, D3DDevice* pDevice) : Swapchain(desc), mD3DDevice(pDevice)
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
		swapChainDesc.Format = D3DTextureUtils::GetD3DTextureFormat(desc.ColorFormat);
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
	void D3DSwapchain::CreateRenderTargetViews()
	{
		// Resize RTVHandles
		mRTVHandles.Resize(GetBufferCount());

		// Get RTV descriptor size
		mRTVDescriptorSize = mD3DDevice->GetD3DDevice()->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV);

		// Get Swapchain buffers
		Array<ComPtr<ID3D12Resource>> swapchainBuffers(GetBufferCount());
		for (uint32 i = 0; i < GetBufferCount(); i++)
		{
			DEV_SYSTEM(SUCCEEDED(mSwapchain->GetBuffer(i, IID_PPV_ARGS(&swapchainBuffers[i]))),
					   "DirectXSwapchain", "Failed to get swapchain buffer", "Swapchain buffer has been gotten succesfully.");
		}

		// Create Render Target Views
		for (uint32 i = 0; i < GetBufferCount(); i++)
		{
			D3D12_RENDER_TARGET_VIEW_DESC rtvDesc = {};
			rtvDesc.Format = D3DTextureUtils::GetD3DTextureFormat(GetColorFormat());
			rtvDesc.ViewDimension = D3D12_RTV_DIMENSION_TEXTURE2D;
			rtvDesc.Texture2D.MipSlice = 0;
			rtvDesc.Texture2D.PlaneSlice = 0;

			mRTVHandles[i] = mRenderTargetView->GetCPUDescriptorHandleForHeapStart();
			mRTVHandles[i].ptr += i * mRTVDescriptorSize;

			mD3DDevice->GetD3DDevice()->CreateRenderTargetView(swapchainBuffers[i].Get(), &rtvDesc, mRTVHandles[i]);
		}

		// Store swapchain textures and texture views
		Array<SharedHeap<Texture>> swapchainTextures;
		Array< SharedHeap<TextureView>> swapchainTextureViews;
		for (uint32 i = 0; i < GetBufferCount(); i++)
		{
			D3D12_RESOURCE_DESC swapchainResourceDesc = swapchainBuffers[i]->GetDesc();

			TextureDesc swapchainBufferDesc = {};
			swapchainBufferDesc.ArrayLevels = swapchainResourceDesc.DepthOrArraySize;
			swapchainBufferDesc.Format = GetColorFormat();
			swapchainBufferDesc.MipLevels = swapchainResourceDesc.MipLevels;
			swapchainBufferDesc.SampleCount = TextureSampleCount::SAMPLE_COUNT_1;
			swapchainBufferDesc.Size = { (uint16)swapchainResourceDesc.Width, (uint16)swapchainResourceDesc.Height, 1 };
			swapchainBufferDesc.Type = TextureType::Texture2D;
			swapchainBufferDesc.Usage = TextureUsage::ColorAttachment;

			SharedHeap<Texture> scTexture = mD3DDevice->CreateD3DSwapchainTexture(swapchainBufferDesc, swapchainBuffers[i]);
			swapchainTextures.Add(scTexture);

			TextureViewDesc swapchainBufferViewDesc = {};
			swapchainBufferViewDesc.ArrayLevel = swapchainBufferDesc.ArrayLevels;
			swapchainBufferViewDesc.MipLevel = swapchainBufferDesc.MipLevels;
			swapchainBufferViewDesc.pTexture = scTexture;

		}
	}
	void D3DSwapchain::CreateDepthStencilView()
	{
	}
	void D3DSwapchain::ResizeCore(const uint16 width, const uint16 height)
	{
	}
	void D3DSwapchain::OnShutdown()
	{
	}
	bool D3DSwapchain::PresentCore()
	{
		return true;
	}
	bool D3DSwapchain::SetFullScreen()
	{
		if (SUCCEEDED(mSwapchain->SetFullscreenState(true, nullptr)))
			return true;

		return false;
	}
	bool D3DSwapchain::SetWindowed()
	{
		if (SUCCEEDED(mSwapchain->SetFullscreenState(false, nullptr)))
			return true;

		return false;
	}
}