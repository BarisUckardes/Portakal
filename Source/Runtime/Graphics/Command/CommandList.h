#pragma once
#include <Runtime/Graphics/Device/GraphicsDeviceObject.h>
#include <Runtime/Graphics/Command/CommandListDesc.h>
#include <Runtime/Graphics/Command/CommandListIndexBufferType.h>
#include <Runtime/Graphics/Command/CommandListTextureMemoryBarrierDesc.h>
#include <Runtime/Graphics/Command/CommandPool.h>
#include <Runtime/Graphics/Command/ViewportDesc.h>
#include <Runtime/Graphics/Command/ScissorDesc.h>
#include <Runtime/Graphics/Command/BufferTextureCopyDesc.h>
#include <Runtime/Graphics/Command/BufferBufferCopyDesc.h>
#include <Runtime/Graphics/Command/TextureCopyDesc.h>
#include <Runtime/Graphics/Command/BufferBarrierDesc.h>
#include <Runtime/Containers/Array.h>

namespace Portakal
{
	class GraphicsBuffer;
	class Framebuffer;
	class Texture;
	class Pipeline;
	class ResourceTable;
	class RenderPass;

	class RUNTIME_API CommandList : public GraphicsDeviceObject
	{
	public:
		CommandList(const CommandListDesc& desc);
		~CommandList() = default;

		FORCEINLINE SharedHeap<CommandPool> GetCmdPool() const noexcept
		{
			return mCmdPool;
		}
		FORCEINLINE bool IsRecording() const noexcept { return mRecording; }
		FORCEINLINE const SharedHeap<GraphicsBuffer>& GetBoundVertexBuffer() const noexcept { return mBoundVertexBuffer; }
		FORCEINLINE const SharedHeap<GraphicsBuffer>& GetBoundIndexBuffer() const noexcept { return mBoundIndexBuffer; }
		FORCEINLINE const SharedHeap<Pipeline>& GetBoundPipeline() const noexcept { return mBoundPipeline; }
		virtual GraphicsDeviceObjectType GetObjectType() const noexcept override final
		{
			return GraphicsDeviceObjectType::CommandList;
		}

		void BeginRecording();
		void EndRecording();
		void SetVertexBuffer(const SharedHeap<GraphicsBuffer>& pBuffer);
		void SetIndexBuffer(const SharedHeap<GraphicsBuffer>& pBuffer, const CommandListIndexBufferType type);
		void DrawIndexed(const uint32 indexCount, const uint32 indexOffset, const uint32 vertexoffset, const uint32 instanceCount, const uint32 instanceOffset);
		void DispatchCompute(const uint32 groupX, const uint32 groupY, const uint32 groupZ);
		void SetPipeline(const SharedHeap<Pipeline>& pPipeline);
		void BeginRenderPass(const SharedHeap<RenderPass>& pRenderPass);
		void EndRenderPass();
		void SetViewports(const ViewportDesc* pViewports, const byte count);
		void SetScissors(const ScissorDesc* pScissors, const byte count);
		void CopyBufferToTexture(const GraphicsBuffer* pSource, const Texture* pDestination, const BufferTextureCopyDesc& desc);
		void CopyBufferToBuffer(const GraphicsBuffer* pBuffer, const GraphicsBuffer* pDestination, const BufferBufferCopyDesc& desc);
		void CopyTextureToTexture(const Texture* pSource, const Texture* pDestination, const TextureCopyDesc& desc);
		void SetTextureMemoryBarrier(const Texture* pTexture, const CommandListTextureMemoryBarrierDesc& desc);
		void SetBufferMemoryBarrier(const GraphicsBuffer* pBuffer, const BufferBarrierDesc& desc);
		void CommitResources(const Array<ResourceTable*>& tables);
	protected:
		virtual void BeginRecordingCore() = 0;
		virtual void EndRecordingCore() = 0;
		virtual void SetVertexBufferCore(const GraphicsBuffer* pBuffer) = 0;
		virtual void SetIndexBufferCore(const GraphicsBuffer* pBuffer, const CommandListIndexBufferType type) = 0;
		virtual void DrawIndexedCore(const uint32 indexCount, const uint32 indexOffset, const uint32 vertexoffset, const uint32 instanceCount, const uint32 instanceOffset) = 0;
		virtual void DispatchComputeCore(const uint32 groupX, const uint32 groupY, const uint32 groupZ) = 0;
		virtual void SetPipelineCore(const Pipeline* pPipeline) = 0;
		virtual void BeginRenderPassCore(const RenderPass* pRenderPass) = 0;
		virtual void EndRenderPassCore() = 0;
		virtual void SetViewportsCore(const ViewportDesc* pViewports, const byte count) = 0;
		virtual void SetScissorsCore(const ScissorDesc* pScissors, const byte count) = 0;
		virtual void CopyBufferToTextureCore(const GraphicsBuffer* pBuffer, const Texture* pDestination, const BufferTextureCopyDesc& desc) = 0;
		virtual void CopyBufferToBufferCore(const GraphicsBuffer* pBuffer, const GraphicsBuffer* pDestination, const BufferBufferCopyDesc& desc) = 0;
		virtual void CopyTextureToTextureCore(const Texture* pSource, const Texture* pDestination, const TextureCopyDesc& desc) = 0;
		virtual void SetTextureMemoryBarrierCore(const Texture* pTexture, const CommandListTextureMemoryBarrierDesc& desc) = 0;
		virtual void SetBufferMemoryBarrierCore(const GraphicsBuffer* pBuffer, const BufferBarrierDesc& desc) = 0;
		virtual void CommitResourcesCore(const Array<ResourceTable*>& tables) = 0;
	private:
		const SharedHeap<CommandPool> mCmdPool;
		SharedHeap<GraphicsBuffer> mBoundVertexBuffer;
		SharedHeap<GraphicsBuffer> mBoundIndexBuffer;
		SharedHeap<Pipeline> mBoundPipeline;
		SharedHeap<RenderPass> mBoundRenderPass;
		bool mRecording;
	};
}
