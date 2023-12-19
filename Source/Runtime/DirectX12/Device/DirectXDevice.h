#pragma once 

#include <Runtime/Graphics/Device/GraphicsDevice.h>

#include <Runtime/DirectX12/DXIncludes.h>

namespace Portakal
{
	class RUNTIME_API DirectXDevice : public GraphicsDevice
	{
	public:
		DirectXDevice(const GraphicsDeviceDesc& desc);
		~DirectXDevice() = default;

		FORCEINLINE virtual GraphicsBackend GetBackend() const noexcept override { return GraphicsBackend::DirectX12; }

		FORCEINLINE ComPtr<ID3D12Device> GetDevice() const noexcept { return mDevice; }
	protected:
		// Inherited via GraphicsDevice
		virtual Texture* CreateTextureCore(const TextureDesc& desc) override;
		virtual TextureView* CreateTextureViewCore(const TextureViewDesc& desc) override;
		virtual CommandList* CreateCommandListCore(const CommandListDesc& desc) override;
		virtual CommandPool* CreateCommandPoolCore(const CommandPoolDesc& desc) override;
		virtual Pipeline* CreateGraphicsPipelineCore(const GraphicsPipelineDesc& desc) override;
		virtual SharedHeap<Pipeline> CreateComputePipelineCore(const ComputePipelineDesc& desc) override;
		virtual GraphicsMemoryHeap* CreateMemoryHeapCore(const GraphicsMemoryHeapDesc& desc) override;
		virtual GraphicsBuffer* CreateBufferCore(const GraphicsBufferDesc& desc) override;
		virtual Shader* CreateShaderCore(const ShaderDesc& desc) override;
		virtual Sampler* CreateSamplerCore(const SamplerDesc& desc) override;
		virtual ResourceTableLayout* CreateResourceTableLayoutCore(const ResourceTableLayoutDesc& desc) override;
		virtual ResourceTablePool* CreateResourceTablePoolCore(const ResourceTablePoolDesc& desc) override;
		virtual ResourceTable* CreateResourceTableCore(const ResourceTableDesc& desc) override;
		virtual Fence* CreateFenceCore() override;
		virtual Swapchain* CreateSwapchainCore(const SwapchainDesc& desc) override;
		virtual RenderPass* CreateRenderPassCore(const RenderPassDesc& desc) override;

		virtual void WaitFencesCore(Fence** ppFences, const byte count) override;
		virtual void WaitDeviceIdleCore() override;
		virtual void WaitQueueDefaultCore(const GraphicsQueueType type) override;
		virtual void UpdateHostBufferCore(GraphicsBuffer* pBuffer, const GraphicsBufferHostUpdateDesc& desc) override;
		virtual void UpdateResourceTableCore(ResourceTable* pTable, const ResourceTableUpdateDesc& desc) override;
		virtual void SubmitCommandListsCore(CommandList** ppCmdLists, const byte cmdListCount, const GraphicsQueueType type, const Fence* pFence) override;

		virtual void OnShutdown() override;
	private:
		ComPtr<ID3D12Device> mDevice;
	};
}