#pragma once

#include <Runtime/Graphics/Swapchain/Swapchain.h>

#ifdef PORTAKAL_PLATFORM_WINDOWS
#include <Runtime/DirectX12/DXIncludes.h>

using namespace Microsoft::WRL;

namespace Portakal
{
	class RUNTIME_API DirectXSwapchain : public Swapchain
	{
	public:
		DirectXSwapchain(const SwapchainDesc& desc, const SharedHeap<GraphicsDevice>& pDevice);
		~DirectXSwapchain() override = default;
	private:
		virtual void ResizeCore(const uint16 width, const uint16 height) override;
		virtual void OnShutdown() override;
		virtual bool PresentCore() override;
		virtual bool SetFullScreen() override;
		virtual bool SetWindowed() override;

	private:
		ComPtr<IDXGISwapChain4> mSwapchain;
		ComPtr<ID3D12Resource> mBackBuffers[2];
		ComPtr<ID3D12DescriptorHeap> mRTVHeap;
		uint32 mRTVDescriptorSize;
		uint32 mBackBufferIndex;
	};
}
#endif