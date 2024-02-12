#pragma once 

#include <Runtime/Graphics/Device/GraphicsDevice.h>
#include <Runtime/D3D12/D3DIncludes.h>

namespace Portakal
{
	class RUNTIME_API D3DDevice : public GraphicsDevice
	{
	public:
		D3DDevice(const GraphicsDeviceDesc& desc);
		~D3DDevice() = default;

		FORCEINLINE ComPtr<ID3D12Device> GetD3DDevice() const noexcept { return mDevice; }
		FORCEINLINE ComPtr<IDXGIAdapter1> GetAdapter() const noexcept { return mAdapter; }
		FORCEINLINE ComPtr<ID3D12CommandQueue> GetGraphicsQueue() const noexcept { return mGraphicsQueue; }
		FORCEINLINE ComPtr<ID3D12CommandQueue> GetComputeQueue() const noexcept { return mComputeQueue; }
		FORCEINLINE ComPtr<ID3D12CommandQueue> GetTransferQueue() const noexcept { return mTransferQueue; }

		SharedHeap<Texture> CreateD3DSwapchainTexture(const TextureDesc& desc, ComPtr<ID3D12Resource> pResource);
		SharedHeap<TextureView> CreateD3DSwapchainTextureView(const TextureViewDesc& desc, ComPtr<ID3D12DescriptorHeap> pDescriptorHeap);
	protected:
		// Inherited via GraphicsDevice
		virtual Texture* CreateTextureCore(const TextureDesc& desc) override;
		virtual TextureView* CreateTextureViewCore(const TextureViewDesc& desc) override;
		virtual CommandList* CreateCommandListCore(const CommandListDesc& desc) override;
		virtual CommandPool* CreateCommandPoolCore(const CommandPoolDesc& desc) override;
		virtual Pipeline* CreateGraphicsPipelineCore(const GraphicsPipelineDesc& desc) override { return nullptr; }
		virtual SharedHeap<Pipeline> CreateComputePipelineCore(const ComputePipelineDesc& desc) override { return nullptr; }
		virtual GraphicsMemoryHeap* CreateMemoryHeapCore(const GraphicsMemoryHeapDesc& desc) override { return nullptr; }
		virtual GraphicsBuffer* CreateBufferCore(const GraphicsBufferDesc& desc) override { return nullptr; }
		virtual Shader* CreateShaderCore(const ShaderDesc& desc) override { return nullptr; }
		virtual Sampler* CreateSamplerCore(const SamplerDesc& desc) override { return nullptr; }
		virtual ResourceTableLayout* CreateResourceTableLayoutCore(const ResourceTableLayoutDesc& desc) override { return nullptr; }
		virtual ResourceTablePool* CreateResourceTablePoolCore(const ResourceTablePoolDesc& desc) override { return nullptr; }
		virtual ResourceTable* CreateResourceTableCore(const ResourceTableDesc& desc) override { return nullptr; }
		virtual Fence* CreateFenceCore(const bool bSignalled) override;
		virtual Swapchain* CreateSwapchainCore(const SwapchainDesc& desc) override;
		virtual RenderPass* CreateRenderPassCore(const RenderPassDesc& desc) override { return nullptr; }

		virtual void ResetFencesCore(Fence** ppFences, const Byte count) override;
		virtual void WaitFencesCore(Fence** ppFences, const Byte count) override {}
		virtual void WaitDeviceIdleCore() override {}
		virtual void WaitQueueDefaultCore(const GraphicsQueueType type) override {}
		virtual void UpdateHostBufferCore(GraphicsBuffer* pBuffer, const GraphicsBufferHostUpdateDesc& desc) override {}
		virtual void UpdateResourceTableCore(ResourceTable* pTable, const ResourceTableUpdateDesc& desc) override {}
		virtual void SubmitCommandListsCore(CommandList** ppCmdLists, const Byte cmdListCount, const GraphicsQueueType type, const Fence* pFence) override {}

		virtual void OnShutdown() override {};
	private:
		ComPtr<ID3D12Device> mDevice;
		ComPtr<IDXGIAdapter1> mAdapter;

		ComPtr<ID3D12CommandQueue> mGraphicsQueue;
		ComPtr<ID3D12CommandQueue> mComputeQueue;
		ComPtr<ID3D12CommandQueue> mTransferQueue;

	};
}
