#include "D3DSwapchain.h"

#include <Runtime/D3D12/Device/D3DDevice.h>
#include <Runtime/D3D12/Instance/D3DInstance.h>
#include <Runtime/D3D12/Adapter/D3DAdapter.h>
#include <Runtime/Win32/Win32Window.h>
#include <Runtime/Platform/PlatformMonitor.h>

#include <Runtime/D3D12/Texture/D3DTextureUtils.h>
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

		D3D12_DESCRIPTOR_HEAP_DESC rtvHeapDesc = {};
		rtvHeapDesc.NumDescriptors = desc.BufferCount;
		rtvHeapDesc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_RTV;
		rtvHeapDesc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;

		pDevice->GetDevice()->CreateDescriptorHeap(&rtvHeapDesc, IID_PPV_ARGS(&mRTVHeap));

		mRTVDescriptorSize = pDevice->GetDevice()->GetDescriptorHandleIncrementSize(D3D12_DESCRIPTOR_HEAP_TYPE_RTV);

		D3D12_CPU_DESCRIPTOR_HANDLE rtvHandle(mRTVHeap->GetCPUDescriptorHandleForHeapStart());

		Array<SharedHeap<Texture>> textures;
		Array<SharedHeap<TextureView>> textureViews;
		for (uint32 i = 0; i < desc.BufferCount; i++)
		{
			ComPtr<ID3D12Resource> backBuffer;
			DEV_SYSTEM(SUCCEEDED(mSwapchain->GetBuffer(i, IID_PPV_ARGS(&backBuffer))), "D3D12Swapchain", "Failed to get back buffer", "Get backbuffer successfully.");
			pDevice->GetDevice()->CreateRenderTargetView(backBuffer.Get(), nullptr, rtvHandle);
			rtvHandle.ptr += mRTVDescriptorSize;

			D3D12_RESOURCE_DESC bufferDesc = backBuffer->GetDesc();

			TextureDesc textureDesc = {};
			textureDesc.Type = TextureType::Texture2D;
			textureDesc.Format = GetColorFormat();
			textureDesc.Usage = TextureUsage::ColorAttachment;
			textureDesc.Size = { (uint16)bufferDesc.Width,(uint16)bufferDesc.Height, 1 };
			textureDesc.MipLevels = 1;
			textureDesc.ArrayLevels = 1;
			textureDesc.SampleCount = TextureSampleCount::SAMPLE_COUNT_1;
			textureDesc.pHeap = nullptr;

			SharedHeap<Texture> pTexture = pDevice->CreateD3DSwapchainTexture(textureDesc, backBuffer.Get());
			textures.Add(pTexture);

			// Create texture view

			TextureViewDesc textureViewDesc = {};
			textureViewDesc.pTexture = pTexture.GetHeap();
			textureViewDesc.ArrayLevel = 1;
			textureViewDesc.MipLevel = 1;

			SharedHeap<TextureView> pTextureView = pDevice->CreateTextureView(textureViewDesc);
			textureViews.Add(pTextureView);
		}
		
		SetTextures(textures, textureViews);

		ResizeCore(pWindow->GetSize().X, pWindow->GetSize().Y);
	}
	void D3DSwapchain::ResizeCore(const uint16 width, const uint16 height)
	{
		mSwapchain->ResizeBuffers(GetBufferCount(), width, height, D3DTextureUtils::GetD3DTextureFormat(GetColorFormat()), 0);
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