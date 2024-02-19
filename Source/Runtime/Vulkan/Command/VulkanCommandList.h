#pragma once
#include <Runtime/Graphics/Command/CommandList.h>
#include <vulkan.h>

namespace Portakal
{
	class VulkanDevice;
	class RUNTIME_API VulkanCommandList : public CommandList
	{
	public:
		VulkanCommandList(const CommandListDesc& desc, VulkanDevice* pDevice);
		~VulkanCommandList();

		FORCEINLINE VkCommandBuffer GetVkCmdBuffer() const noexcept
		{
			return mCommandBuffer;
		}

	private:
		virtual void BeginRecordingCore() override;
		virtual void EndRecordingCore() override;
		virtual void SetVertexBuffersCore(GraphicsBuffer** ppBuffers,const Byte count) override;
		virtual void SetIndexBufferCore(GraphicsBuffer* pBuffer, const IndexBufferType type) override;
		virtual void DrawIndexedCore(const UInt32 indexCount, const UInt32 indexOffset, const UInt32 vertexOffset, const UInt32 instanceOffset, const UInt32 instanceCount) override;
		virtual void DispatchComputeCore(const UInt32 x, const UInt32 y, const UInt32 z) override;
		virtual void SetPipelineCore(Pipeline* pPipeline) override;
		virtual void BeginRenderPassCore(RenderPass* pPass,const ClearValue* pClearColorValues, const Byte clearColorValueCount, const double clearDepth, const double clearStencil) override;
		virtual void EndRenderPassCore() override;
		virtual void SetViewportsCore(ViewportDesc* pViewports, const Byte count) override;
		virtual void SetScissorsCore(ScissorDesc* pScissors, const Byte count) override;
		virtual void CopyBufferToBufferCore(const GraphicsBuffer* pSourceBuffer, const GraphicsBuffer* pDestinationBuffer, const BufferBufferCopyDesc& desc) override;
		virtual void CopyBufferToTextureCore(const GraphicsBuffer* pSourceBuffer, const Texture* pDestinationTexture, const BufferTextureCopyDesc& desc) override;
		virtual void CopyTextureToTextureCore(const Texture* pSourceTexture, const Texture* pDestinationTexture, const TextureCopyDesc& desc) override;
		virtual void SetTextureMemoryBarrierCore(const Texture* pTexture, const TextureMemoryBarrierDesc& desc) override;
		virtual void SetBufferMemoryBarrierCore(const GraphicsBuffer* pBuffer, const BufferMemoryBarrierDesc& desc) override;
		virtual void CommitResourceSetsCore(DescriptorSet** ppSets, const Byte count) override;
	private:
		VkCommandBuffer mCommandBuffer;
		VkCommandPool mCommandPool;
		VkDevice mLogicalDevice;

	};
}
