#pragma once
#include <Runtime/Graphics/Device/GraphicsDeviceObject.h>
#include <Runtime/Graphics/Command/CommandListDesc.h>
#include <Runtime/Graphics/Common/IndexBufferType.h>
#include <Runtime/Graphics/Common/ViewportDesc.h>
#include <Runtime/Graphics/Common/ScissorDesc.h>
#include <Runtime/Graphics/Common/BufferBufferCopyDesc.h>
#include <Runtime/Graphics/Common/BufferTextureCopyDesc.h>
#include <Runtime/Graphics/Common/TextureCopyDesc.h>
#include <Runtime/Graphics/Common/TextureMemoryBarrierDesc.h>
#include <Runtime/Graphics/Common/BufferMemoryBarrierDesc.h>
#include <Runtime/Graphics/Common/ClearValue.h>

namespace Portakal
{
	class GraphicsBuffer;
	class Pipeline;
	class RenderPass;
	class Texture;
	class DescriptorSet;
	class RUNTIME_API CommandList : public GraphicsDeviceObject
	{
	public:
		~CommandList();

		FORCEINLINE SharedHeap<CommandPool> GetCmdPool() const noexcept
		{
			return mCmdPool;
		}
		FORCEINLINE bool IsRecording() const noexcept
		{
			return mRecording;
		}
		virtual GraphicsDeviceObjectType GetObjectType() const noexcept override final
		{
			return GraphicsDeviceObjectType::CommandList;
		}

		void BeginRecording();
		void EndRecording();
		void SetVertexBuffers(GraphicsBuffer** ppBuffers, const Byte count);
		void SetIndexBuffer(GraphicsBuffer* pBuffer, const IndexBufferType type);
		void DrawIndexed(const UInt32 indexCount, const UInt32 indexOffset, const UInt32 vertexOffset, const UInt32 instanceOffset, const UInt32 instanceCount);
		void DispatchCompute(const UInt32 x, const UInt32 y, const UInt32 z);
		void SetPipeline(Pipeline* pPipeline);
		void BeginRenderPass(RenderPass* pPass,const ClearValue* pClearColorValues,const Byte clearColorValueCount,const double clearDepth,const double clearStencil);
		void EndRenderPass();
		void SetViewports(ViewportDesc* pViewports,const Byte count);
		void SetScissors(ScissorDesc* pScissors, const Byte count);
		void CopyBufferToBuffer(const GraphicsBuffer* pSourceBuffer,const GraphicsBuffer* pDestinationBuffer,const BufferBufferCopyDesc& desc);
		void CopyBufferToTexture(const GraphicsBuffer* pSourceBuffer,const Texture* pDestinationTexture,const BufferTextureCopyDesc& desc);
		void CopyTextureToTexture(const Texture* pSourceTexture,const Texture* pDestinationTexture,const TextureCopyDesc& desc);
		void SetTextureMemoryBarrier(const Texture* pTexture,const TextureMemoryBarrierDesc& desc);
		void SetBufferMemoryBarrier(const GraphicsBuffer* pBuffer,const BufferMemoryBarrierDesc& desc);
		void CommitResourceSets(DescriptorSet** ppSets, const Byte count);
	protected:
		CommandList(const CommandListDesc& desc, GraphicsDevice* pDevice);

		virtual void BeginRecordingCore() = 0;
		virtual void EndRecordingCore() = 0;
		virtual void SetVertexBuffersCore(GraphicsBuffer** ppBuffers, const Byte count) = 0;
		virtual void SetIndexBufferCore(GraphicsBuffer* pBuffer, const IndexBufferType type) = 0;
		virtual void DrawIndexedCore(const UInt32 indexCount, const UInt32 indexOffset, const UInt32 vertexOffset, const UInt32 instanceOffset, const UInt32 instanceCount) = 0;
		virtual void DispatchComputeCore(const UInt32 x, const UInt32 y, const UInt32 z) = 0;
		virtual void SetPipelineCore(Pipeline* pPipeline) = 0;
		virtual void BeginRenderPassCore(RenderPass* pPass,const ClearValue* pClearColorValues,const Byte clearColorValueCount, const double clearDepth, const double clearStencil) = 0;
		virtual void EndRenderPassCore() = 0;
		virtual void SetViewportsCore(ViewportDesc* pViewports, const Byte count) = 0;
		virtual void SetScissorsCore(ScissorDesc* pScissors, const Byte count) = 0;
		virtual void CopyBufferToBufferCore(const GraphicsBuffer* pSourceBuffer, const GraphicsBuffer* pDestinationBuffer, const BufferBufferCopyDesc& desc) = 0;
		virtual void CopyBufferToTextureCore(const GraphicsBuffer* pSourceBuffer, const Texture* pDestinationTexture, const BufferTextureCopyDesc& desc) = 0;
		virtual void CopyTextureToTextureCore(const Texture* pSourceTexture, const Texture* pDestinationTexture, const TextureCopyDesc& desc) = 0;
		virtual void SetTextureMemoryBarrierCore(const Texture* pTexture, const TextureMemoryBarrierDesc& desc) = 0;
		virtual void SetBufferMemoryBarrierCore(const GraphicsBuffer* pBuffer, const BufferMemoryBarrierDesc& desc) = 0;
		virtual void CommitResourceSetsCore(DescriptorSet** ppSets, const Byte count) = 0;

		FORCEINLINE SharedHeap<Pipeline> GetBoundPipeline() const noexcept
		{
			return mBoundPipeline;
		}
		FORCEINLINE SharedHeap<RenderPass> GetBoundRenderPass() const noexcept
		{
			return mBoundRenderPass;
		}

		void ClearCachedState();
	private:
		SharedHeap<CommandPool> mCmdPool;
		SharedHeap<Pipeline> mBoundPipeline;
		SharedHeap<RenderPass> mBoundRenderPass;
		bool mRecording;
	};
}

