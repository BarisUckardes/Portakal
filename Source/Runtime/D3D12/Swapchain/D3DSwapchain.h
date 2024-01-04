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

		void CreateRenderTargetViews();
		void CreateDepthStencilView();

	private:
		virtual void ResizeCore(const Uint16 width, const Uint16 height) override;
		virtual void OnShutdown() override;
		virtual Bool8 PresentCore() override;
		virtual Bool8 SetFullScreen() override;
		virtual Bool8 SetWindowed() override;

	private:
		D3DDevice* mD3DDevice;
		ComPtr<IDXGISwapChain1> mSwapchain;
		ComPtr<ID3D12DescriptorHeap> mRenderTargetView;
		Array<D3D12_CPU_DESCRIPTOR_HANDLE> mRTVHandles;
		Uint32 mRTVDescriptorSize;
	};
}