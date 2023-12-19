#include "CommandList.h"
#include <Runtime/Graphics/Pipeline/Pipeline.h>
namespace Portakal
{
	CommandList::CommandList(const CommandListDesc& desc) : mCmdPool(desc.pPool)
	{
		
	}
	void CommandList::BeginRecording()
	{
		BeginRecordingCore();
		mRecording = true;
	}
	void CommandList::EndRecording()
	{
		EndRecordingCore();
		mRecording = false;
		mBoundRenderPass = nullptr;
		mBoundIndexBuffer = nullptr;
		mBoundVertexBuffer = nullptr;
		mBoundPipeline = nullptr;
	}
	void CommandList::SetVertexBuffer(const SharedHeap<GraphicsBuffer>& pBuffer)
	{
		if (IsShutdown())
			return;
		if (pBuffer.IsShutdown())
			return;

		SetVertexBufferCore(pBuffer.GetHeap());

		mBoundVertexBuffer = pBuffer;
	}
	void CommandList::SetIndexBuffer(const SharedHeap<GraphicsBuffer>& pBuffer, const CommandListIndexBufferType type)
	{
		if (IsShutdown())
			return;
		if (pBuffer.IsShutdown())
			return;

		SetIndexBufferCore(pBuffer.GetHeap(), type);

		mBoundIndexBuffer = pBuffer;
	}
	void CommandList::DrawIndexed(const uint32 indexCount, const uint32 indexOffset, const uint32 vertexOffset, const uint32 instanceCount, const uint32 instanceOffset)
	{
		if (IsShutdown())
			return;

		DrawIndexedCore(indexCount, indexOffset, vertexOffset, instanceCount, instanceOffset);
	}
	void CommandList::DispatchCompute(const uint32 groupX, const uint32 groupY, const uint32 groupZ)
	{
		if (IsShutdown())
			return;

		DEV_ASSERT(mBoundPipeline != nullptr, "CommandList", "No pipeline is bound for dispatching the compute shader");

		DEV_ASSERT(mBoundPipeline->GetBindPoint() == PipelineBindPoint::Compute, "CommandList", "Bound pipeline is not a compute pipeline, cannot dispatch the compute shader");

		DispatchComputeCore(groupX, groupY, groupZ);
	}
	void CommandList::SetPipeline(const SharedHeap<Pipeline>& pPipeline)
	{
		if (IsShutdown())
			return;

		SetPipelineCore(pPipeline.GetHeap());

		mBoundPipeline = pPipeline;
	}
	void CommandList::BeginRenderPass(const SharedHeap<RenderPass>& pRenderPass)
	{
		if (IsShutdown())
			return;

		BeginRenderPassCore(pRenderPass.GetHeap());

		mBoundRenderPass = pRenderPass;
	}
	void CommandList::EndRenderPass()
	{
		if (IsShutdown())
			return;

		EndRenderPassCore();
		mBoundRenderPass = nullptr;
	}
	void CommandList::SetViewports(const ViewportDesc* pViewports, const byte count)
	{
		if (IsShutdown())
			return;

		SetViewportsCore(pViewports, count);
	}
	void CommandList::SetScissors(const ScissorDesc* pScissors, const byte count)
	{
		if (IsShutdown())
			return;

		SetScissorsCore(pScissors, count);
	}
	void CommandList::CopyBufferToTexture(const GraphicsBuffer* pSource, const Texture* pDestination, const BufferTextureCopyDesc& desc)
	{
		if (IsShutdown())
			return;

		CopyBufferToTextureCore(pSource, pDestination, desc);
	}
	void CommandList::CopyBufferToBuffer(const GraphicsBuffer* pSource, const GraphicsBuffer* pDestination, const BufferBufferCopyDesc& desc)
	{
		if (IsShutdown())
			return;

		CopyBufferToBufferCore(pSource, pDestination, desc);
	}
	void CommandList::CopyTextureToTexture(const Texture* pSource, const Texture* pDestination, const TextureCopyDesc& desc)
	{
		if (IsShutdown())
			return;

		CopyTextureToTextureCore(pSource, pDestination, desc);
	}
	void CommandList::SetTextureMemoryBarrier(const Texture* pTexture, const CommandListTextureMemoryBarrierDesc& desc)
	{
		if (IsShutdown())
			return;

		SetTextureMemoryBarrierCore(pTexture, desc);
	}
	void CommandList::SetBufferMemoryBarrier(const GraphicsBuffer* pBuffer, const BufferBarrierDesc& desc)
	{
		if (IsShutdown())
			return;

		SetBufferMemoryBarrierCore(pBuffer, desc);
	}
	void CommandList::CommitResources(const Array<ResourceTable*>& tables)
	{
		if (IsShutdown())
			return;

		/**
		* Validate bound pipeline
		*/
		DEV_ASSERT(mBoundPipeline != nullptr, "CommandList", "Cannot commit resources before binding a pipeline!");

		/**
		* Validate resource set count
		*/
		DEV_ASSERT(mBoundPipeline->GetResourceLayout().ResourceLayouts.GetSize() == tables.GetSize(), "CommandList", "Committed resource count does not match the given pipeline layout!");

		/**
		* Commit
		*/
		CommitResourcesCore(tables);
	}
}
