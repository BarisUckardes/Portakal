#pragma once
#include <Runtime/Object/Object.h>
#include <Runtime/Graphics/Device/GraphicsDeviceObject.h>
#include <Runtime/Graphics/Device/GraphicsBackend.h>
#include <Runtime/Graphics/Queue/GraphicsQueueType.h>
#include <Runtime/Graphics/Device/GraphicsDeviceDesc.h>
#include <Runtime/Containers/Array.h>

namespace Portakal
{
	class CommandList;
	class Fence;
	class Texture;
	class TextureView;
	class Framebuffer;
	class CommandList;
	class CommandPool;
	class Pipeline;
	class GraphicsMemoryHeap;
	class GraphicsBuffer;
	class Shader;
	class Sampler;
	class ResourceTableLayout;
	class ResourceTablePool;
	class ResourceTable;
	class GraphicsQueue;
	class Swapchain;
	class GraphicsAdapter;

	struct TextureDesc;
	struct TextureViewDesc;
	struct FramebufferDesc;
	struct CommandListDesc;
	struct CommandPoolDesc;
	struct PipelineDesc;
	struct GraphicsMemoryHeapDesc;
	struct GraphicsBufferDesc;
	struct ShaderDesc;
	struct SamplerDesc;
	struct ResourceTableLayoutDesc;
	struct ResourceTablePoolDesc;
	struct ResourceTableDesc;
	struct GraphicsQueueDesc;
	struct SwapchainDesc;
	struct GraphicsBufferHostUpdateDesc;
	struct ResourceTableUpdateDesc;
	class RUNTIME_API GraphicsDevice : public Object
	{
	public:
		GraphicsDevice(const GraphicsDeviceDesc& desc);
		~GraphicsDevice() = default;

		FORCEINLINE SharedHeap<Swapchain> GetMainSwapchain() const noexcept
		{
			return mMainSwapchain;
		}
		FORCEINLINE virtual GraphicsBackend GetBackend() const noexcept = 0;

		SharedHeap<Texture> CreateTexture(const TextureDesc& desc);
		SharedHeap<TextureView> CreateTextureView(const TextureViewDesc& desc);
		SharedHeap<Framebuffer> CreateFramebuffer(const FramebufferDesc& desc);
		SharedHeap<CommandList> CreateCommandList(const CommandListDesc& desc);
		SharedHeap<CommandPool> CreateCommandPool(const CommandPoolDesc& desc);
		SharedHeap<Pipeline> CreatePipeline(const PipelineDesc& desc);
		SharedHeap<GraphicsMemoryHeap> CreateMemoryHeap(const GraphicsMemoryHeapDesc& desc);
		SharedHeap<GraphicsBuffer> CreateBuffer(const GraphicsBufferDesc& desc);
		SharedHeap<Shader> CreateShader(const ShaderDesc& desc);
		SharedHeap<Sampler> CreateSampler(const SamplerDesc& desc);
		SharedHeap<ResourceTableLayout> CreateResourceTableLayout(const ResourceTableLayoutDesc& desc);
		SharedHeap<ResourceTablePool> CreateResourceTablePooLDesc(const ResourceTablePoolDesc& desc);
		SharedHeap<ResourceTable> CreateResourceTable(const ResourceTableDesc& desc);
		SharedHeap<GraphicsQueue> CreateQueue(const GraphicsQueueDesc& desc);
		SharedHeap<Fence> CreateFence();
		SharedHeap<Swapchain> CreateSwapchain(const SwapchainDesc& desc);
		FORCEINLINE GraphicsAdapter* GetOwnerAdapter() const noexcept
		{
			return mOwnerAdapter;
		}
		void WaitFences(Fence* ppFences, const byte count);
		void WaitQueueIdle(GraphicsQueue* pQueue);
		void WaitDeviceIdle();
		void WaitQueueDefault(const GraphicsQueueType type);
		void UpdateHostBuffer(GraphicsBuffer* pBuffer, const GraphicsBufferHostUpdateDesc& desc);
		void UpdateResourceTable(ResourceTable* pTable, const ResourceTableUpdateDesc& desc);
	protected:
		void RegisterChild(const SharedHeap<GraphicsDeviceObject>& pObject);
		void RemoveChild(const SharedHeap<GraphicsDeviceObject>& pObject);

		virtual Texture* CreateTextureCore(const TextureDesc& desc) = 0;
		virtual TextureView* CreateTextureViewCore(const TextureViewDesc& desc) = 0;
		virtual Framebuffer* CreateFramebufferCore(const FramebufferDesc& desc) = 0;
		virtual CommandList* CreateCommandListCore(const CommandListDesc& desc) = 0;
		virtual Pipeline* CreatePipelineCore(const PipelineDesc& desc) = 0;
		virtual GraphicsMemoryHeap* CreateMemoryHeapCore(const GraphicsMemoryHeapDesc& desc) = 0;
		virtual GraphicsBuffer* CreateBufferCore(const GraphicsBufferDesc& desc) = 0;
		virtual Shader* CreateShaderCore(const ShaderDesc& desc) = 0;
		virtual Sampler* CreateSamplerCore(const SamplerDesc& desc) = 0;
		virtual ResourceTableLayout* CreateResourceTableLayoutCore(const ResourceTableLayoutDesc& desc) = 0;
		virtual ResourceTablePool* CreateResourceTablePoolCore(const ResourceTablePoolDesc& desc) = 0;
		virtual ResourceTable* CreateResourceTableCore(const ResourceTableDesc& desc) = 0;
		virtual Fence* CreateFenceCore() = 0;
		virtual Swapchain* CreateSwapchainCore(const SwapchainDesc& desc) = 0;
	private:
		Array<SharedHeap<GraphicsDeviceObject>> mChilds;
		SharedHeap<Swapchain> mMainSwapchain;
		GraphicsAdapter* mOwnerAdapter;
	};
}
