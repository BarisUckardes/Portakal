#pragma once

#include <Runtime/Graphics/Swapchain/Swapchain.h>

#include <Runtime/D3D12/D3DIncludes.h>

namespace Portakal
{
	class D3DDevice;

	class RUNTIME_API D3DSwapchain : public Swapchain
	{
	public:
		D3DSwapchain(const SwapchainDesc& desc, D3DDevice* pDevice);
		~D3DSwapchain() override = default;
	private:
		virtual void ResizeCore(const uint16 width, const uint16 height) override;
		virtual void OnShutdown() override;
		virtual bool PresentCore() override;
		virtual bool SetFullScreen() override;
		virtual bool SetWindowed() override;

	private:
		ComPtr<IDXGISwapChain1> mSwapchain;
		Array<ComPtr<ID3D12Resource>> mBackBuffers;
		ComPtr<ID3D12DescriptorHeap> mRTVHeap;
		uint32 mRTVDescriptorSize;
		uint32 mBackBufferIndex;
	};
}