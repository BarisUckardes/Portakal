#pragma once
#include <Runtime/Object/Object.h>
#include <Runtime/Graphics/Device/GraphicsDeviceObject.h>
#include <Runtime/Graphics/Device/GraphicsBackend.h>
#include <Runtime/Graphics/Queue/GraphicsQueueFamilyType.h>
#include <Runtime/Graphics/Device/GraphicsDeviceDesc.h>
#include <Runtime/Containers/Array.h>

#include <Runtime/Graphics/Texture/TextureDesc.h>
#include <Runtime/Graphics/Texture/TextureViewDesc.h>

#include <Runtime/Graphics/Command/CommandListDesc.h>
#include <Runtime/Graphics/Command/CommandPoolDesc.h>

#include <Runtime/Graphics/Pipeline/GraphicsPipelineDesc.h>
#include <Runtime/Graphics/Pipeline/ComputePipelineDesc.h>

#include <Runtime/Graphics/Memory/GraphicsMemoryDesc.h>
#include <Runtime/Graphics/Buffer/GraphicsBufferDesc.h>

#include <Runtime/Graphics/Shader/ShaderDesc.h>
#include <Runtime/Graphics/Sampler/SamplerDesc.h>

#include <Runtime/Graphics/Descriptor/DescriptorSetLayoutDesc.h>
#include <Runtime/Graphics/Descriptor/DescriptorSetDesc.h>
#include <Runtime/Graphics/Descriptor/DescriptorSetPoolDesc.h>


#include <Runtime/Graphics/Buffer/GraphicsBufferHostUpdateDesc.h>
#include <Runtime/Graphics/Descriptor/DescriptorSetUpdateDesc.h>
#include <Runtime/Graphics/Pipeline/GraphicsPipelineDesc.h>
#include <Runtime/Graphics/Pipeline/ComputePipelineDesc.h>
#include <Runtime/Graphics/Swapchain/SwapchainDesc.h>

#include <Runtime/Graphics/Semaphore/Semaphore.h>
#include <Runtime/Graphics/Pipeline/PipelineStageFlags.h>

#include <Runtime/Graphics/Fence/Fence.h>
#include <Runtime/Graphics/Semaphore/Semaphore.h>

namespace Portakal
{
	class CommandList;
	class Texture;
	class TextureView;
	class Framebuffer;
	class CommandList;
	class CommandPool;
	class Pipeline;
	class GraphicsMemory;
	class GraphicsBuffer;
	class Shader;
	class Sampler;
	class DescriptorSetLayout;
	class DescriptorSetPool;
	class DescriptorSet;
	class GraphicsQueue;
	class Swapchain;
	class GraphicsAdapter;

	class RUNTIME_API GraphicsDevice : public Object
	{
	public:
		static SharedHeap<GraphicsDevice> Create(const GraphicsDeviceDesc& desc);
	public:
		GraphicsDevice(const GraphicsDeviceDesc* pDesc);
		~GraphicsDevice() = default;

		FORCEINLINE SharedHeap<Swapchain> GetMainSwapchain() const noexcept
		{
			return mMainSwapchain;
		}
		FORCEINLINE GraphicsAdapter* GetOwnerAdapter() const noexcept
		{
			return mOwnerAdapter;
		}
	
		SharedHeap<Texture> CreateTexture(const TextureDesc& desc);
		SharedHeap<TextureView> CreateTextureView(const TextureViewDesc& desc);
		SharedHeap<CommandList> CreateCommandList(const CommandListDesc& desc);
		SharedHeap<CommandPool> CreateCommandPool(const CommandPoolDesc& desc);
		SharedHeap<Pipeline> CreateGraphicsPipeline(const GraphicsPipelineDesc& desc);
		SharedHeap<Pipeline> CreateComputePipeline(const ComputePipelineDesc& desc);
		SharedHeap<GraphicsMemory> CreateMemoryHeap(const GraphicsMemoryDesc& desc);
		SharedHeap<GraphicsBuffer> CreateBuffer(const GraphicsBufferDesc& desc);
		SharedHeap<Shader> CreateShader(const ShaderDesc& desc);
		SharedHeap<Sampler> CreateSampler(const SamplerDesc& desc);
		SharedHeap<DescriptorSetLayout> CreateDescriptorSetLayout(const DescriptorSetLayoutDesc& desc);
		SharedHeap<DescriptorSetPool> CreateDescriptorSetPool(const DescriptorSetPoolDesc& desc);
		SharedHeap<DescriptorSet> CreateDescriptorSet(const DescriptorSetDesc& desc);
		SharedHeap<Fence> CreateFence(const bool bSignalled);
		SharedHeap<Semaphore> CreateSyncObject();
		SharedHeap<Swapchain> CreateSwapchain(const SwapchainDesc& desc);
		SharedHeap<RenderPass> CreateRenderPass(const RenderPassDesc& desc);
		SharedHeap<GraphicsQueue> RentQueue(const GraphicsQueueDesc& desc);

		void ResetFences(Fence** ppFences,const Byte count);
		void WaitFences(Fence** ppFences, const Byte count);
		void WaitDeviceIdle();
		void UpdateHostBuffer(GraphicsBuffer* pBuffer, const GraphicsBufferHostUpdateDesc& desc);
		void UpdateDescriptorSet(DescriptorSet* pTable, const DescriptorSetUpdateDesc& desc);
		void SubmitCommandLists(CommandList** ppCmdLists, const unsigned char cmdListCount,
			const GraphicsQueue* pTargetQueue,
			Semaphore** ppSignalSemaphores, const unsigned int signalSemaphoreCount,
			Semaphore** ppWaitSemaphores, const PipelineStageFlags* pWaitStageFlags, const unsigned int waitSemaphoreCount,
			const Fence* pSignalFence);

		virtual GraphicsBackend GetBackend() const noexcept = 0;
	protected:
		void RegisterChild(const SharedHeap<GraphicsDeviceObject>& pObject);
		void RemoveChild(const SharedHeap<GraphicsDeviceObject>& pObject);

		virtual void OnShutdown() override;
		virtual Texture* CreateTextureCore(const TextureDesc& desc) = 0;
		virtual TextureView* CreateTextureViewCore(const TextureViewDesc& desc) = 0;
		virtual CommandList* CreateCommandListCore(const CommandListDesc& desc) = 0;
		virtual CommandPool* CreateCommandPoolCore(const CommandPoolDesc& desc) = 0;
		virtual Pipeline* CreateGraphicsPipelineCore(const GraphicsPipelineDesc& desc) = 0;
		virtual SharedHeap<Pipeline> CreateComputePipelineCore(const ComputePipelineDesc& desc) = 0;
		virtual GraphicsMemory* CreateMemoryHeapCore(const GraphicsMemoryDesc& desc) = 0;
		virtual GraphicsBuffer* CreateBufferCore(const GraphicsBufferDesc& desc) = 0;
		virtual Shader* CreateShaderCore(const ShaderDesc& desc) = 0;
		virtual Sampler* CreateSamplerCore(const SamplerDesc& desc) = 0;
		virtual DescriptorSetLayout* CreateDescriptorSetLayoutCore(const DescriptorSetLayoutDesc& desc) = 0;
		virtual DescriptorSetPool* CreateDescriptorSetPoolCore(const DescriptorSetPoolDesc& desc) = 0;
		virtual DescriptorSet* CreateDescriptorSetCore(const DescriptorSetDesc& desc) = 0;
		virtual Fence* CreateFenceCore(const bool bSignalled) = 0;
		virtual Semaphore* CreateSyncObjectCore() = 0;
		virtual Swapchain* CreateSwapchainCore(const SwapchainDesc& desc) = 0;
		virtual RenderPass* CreateRenderPassCore(const RenderPassDesc& desc) = 0;
		virtual GraphicsQueue* RentQueueCore(const GraphicsQueueDesc& desc) = 0;

		virtual void ResetFencesCore(Fence** ppFences, const Byte count) = 0;
		virtual void WaitFencesCore(Fence** ppFences, const Byte count) = 0;
		virtual void WaitDeviceIdleCore() = 0;
		virtual void UpdateHostBufferCore(GraphicsBuffer* pBuffer, const GraphicsBufferHostUpdateDesc& desc) = 0;
		virtual void UpdateDescriptorSetCore(DescriptorSet* pTable, const DescriptorSetUpdateDesc& desc) = 0;
		virtual void SubmitCommandListsCore(CommandList** ppCmdLists, const unsigned char cmdListCount,
			const GraphicsQueue* pTargetQueue,
			Semaphore** ppSignalSemaphores, const unsigned int signalSemaphoreCount,
			Semaphore** ppWaitSemaphores, const PipelineStageFlags* pWaitStageFlags, const unsigned int waitSemaphoreCount,
			const Fence* pSignalFence) = 0;
	private:
		GraphicsAdapter* mOwnerAdapter;
		Array<SharedHeap<GraphicsDeviceObject>> mChilds;
		SharedHeap<Swapchain> mMainSwapchain;
	};
}
