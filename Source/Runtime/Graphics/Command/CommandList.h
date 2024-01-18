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
#include <Runtime/Math/Color4.h>

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
		FORCEINLINE Bool8 IsRecording() const noexcept { return mRecording; }
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
		void DrawIndexed(const UInt32 indexCount, const UInt32 indexOffset, const UInt32 vertexoffset, const UInt32 instanceCount, const UInt32 instanceOffset);
		void DispatchCompute(const UInt32 groupX, const UInt32 groupY, const UInt32 groupZ);
		void SetPipeline(const SharedHeap<Pipeline>& pPipeline);
		void BeginRenderPass(const SharedHeap<RenderPass>& pRenderPass,const Color4F& clearColor,const Byte subFramebufferIndex = 0);
		void EndRenderPass();
		void SetViewports(const ViewportDesc* pViewports, const Byte count);
		void SetScissors(const ScissorDesc* pScissors, const Byte count);
		void CopyBufferToTexture(const GraphicsBuffer* pSource, const Texture* pDestination, const BufferTextureCopyDesc& desc);
		void CopyBufferToBuffer(const GraphicsBuffer* pBuffer, const GraphicsBuffer* pDestination, const BufferBufferCopyDesc& desc);
		void CopyTextureToTexture(const Texture* pSource, const Texture* pDestination, const TextureCopyDesc& desc);
		void SetTextureMemoryBarrier(const Texture* pTexture, const CommandListTextureMemoryBarrierDesc& desc);
		void SetBufferMemoryBarrier(const GraphicsBuffer* pBuffer, const BufferBarrierDesc& desc);
		void CommitResources(ResourceTable** ppTables,const UInt32 count);
		void ClearTexture(const Texture* pTexture, const Color4F clearColor);
	protected:
		virtual void BeginRecordingCore() = 0;
		virtual void EndRecordingCore() = 0;
		virtual void SetVertexBufferCore(const GraphicsBuffer* pBuffer) = 0;
		virtual void SetIndexBufferCore(const GraphicsBuffer* pBuffer, const CommandListIndexBufferType type) = 0;
		virtual void DrawIndexedCore(const UInt32 indexCount, const UInt32 indexOffset, const UInt32 vertexoffset, const UInt32 instanceCount, const UInt32 instanceOffset) = 0;
		virtual void DispatchComputeCore(const UInt32 groupX, const UInt32 groupY, const UInt32 groupZ) = 0;
		virtual void SetPipelineCore(const Pipeline* pPipeline) = 0;
		virtual void BeginRenderPassCore(const RenderPass* pRenderPass, const Color4F& clearColor, const Byte subFramebufferIndex) = 0;
		virtual void EndRenderPassCore() = 0;
		virtual void SetViewportsCore(const ViewportDesc* pViewports, const Byte count) = 0;
		virtual void SetScissorsCore(const ScissorDesc* pScissors, const Byte count) = 0;
		virtual void CopyBufferToTextureCore(const GraphicsBuffer* pBuffer, const Texture* pDestination, const BufferTextureCopyDesc& desc) = 0;
		virtual void CopyBufferToBufferCore(const GraphicsBuffer* pBuffer, const GraphicsBuffer* pDestination, const BufferBufferCopyDesc& desc) = 0;
		virtual void CopyTextureToTextureCore(const Texture* pSource, const Texture* pDestination, const TextureCopyDesc& desc) = 0;
		virtual void SetTextureMemoryBarrierCore(const Texture* pTexture, const CommandListTextureMemoryBarrierDesc& desc) = 0;
		virtual void SetBufferMemoryBarrierCore(const GraphicsBuffer* pBuffer, const BufferBarrierDesc& desc) = 0;
		virtual void CommitResourcesCore(ResourceTable** ppTables, const UInt32 count) = 0;
		virtual void ClearTextureCore(const Texture* pTexture, const Color4F clearColor) = 0;
	private:
		const SharedHeap<CommandPool> mCmdPool;
		SharedHeap<GraphicsBuffer> mBoundVertexBuffer;
		SharedHeap<GraphicsBuffer> mBoundIndexBuffer;
		SharedHeap<Pipeline> mBoundPipeline;
		SharedHeap<RenderPass> mBoundRenderPass;
		Bool8 mRecording;
	};
}
