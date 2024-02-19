#include "CommandList.h"

namespace Portakal
{
	CommandList::~CommandList()
	{
	}
	CommandList::CommandList(const CommandListDesc& desc, GraphicsDevice* pDevice) :
		GraphicsDeviceObject(pDevice),mCmdPool(desc.pCmdPool),mRecording(false),
		mBoundPipeline(nullptr),mBoundRenderPass(nullptr)
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
		ClearCachedState();
	}
	void CommandList::SetVertexBuffers(GraphicsBuffer** ppBuffers, const Byte count)
	{
		SetVertexBuffersCore(ppBuffers,count);
	}
	void CommandList::SetIndexBuffer(GraphicsBuffer* pBuffer, const IndexBufferType type)
	{
		SetIndexBufferCore(pBuffer, type);
	}
	void CommandList::DrawIndexed(const UInt32 indexCount, const UInt32 indexOffset, const UInt32 vertexOffset, const UInt32 instanceOffset, const UInt32 instanceCount)
	{
		DrawIndexedCore(indexCount, indexOffset, vertexOffset, instanceOffset, instanceCount);
	}
	void CommandList::DispatchCompute(const UInt32 x, const UInt32 y, const UInt32 z)
	{
		DispatchComputeCore(x, y, z);
	}
	void CommandList::SetPipeline(Pipeline* pPipeline)
	{
		SetPipelineCore(pPipeline);
		mBoundPipeline = pPipeline;
	}
	void CommandList::BeginRenderPass(RenderPass* pPass, const ClearValue* pClearColorValues, const Byte clearColorValueCount, const double clearDepth, const double clearStencil)
	{
		BeginRenderPassCore(pPass, pClearColorValues,clearColorValueCount,clearDepth,clearStencil);
		mBoundRenderPass = pPass;
	}
	void CommandList::EndRenderPass()
	{
		EndRenderPassCore();
		mBoundRenderPass = nullptr;
	}
	void CommandList::SetViewports(ViewportDesc* pViewports, const Byte count)
	{
		SetViewportsCore(pViewports, count);
	}
	void CommandList::SetScissors(ScissorDesc* pScissors, const Byte count)
	{
		SetScissorsCore(pScissors, count);
	}
	void CommandList::CopyBufferToBuffer(const GraphicsBuffer* pSourceBuffer, const GraphicsBuffer* pDestinationBuffer, const BufferBufferCopyDesc& desc)
	{
		CopyBufferToBufferCore(pSourceBuffer, pDestinationBuffer, desc);
	}
	void CommandList::CopyBufferToTexture(const GraphicsBuffer* pSourceBuffer, const Texture* pDestinationTexture, const BufferTextureCopyDesc& desc)
	{
		CopyBufferToTextureCore(pSourceBuffer, pDestinationTexture, desc);
	}
	void CommandList::CopyTextureToTexture(const Texture* pSourceTexture, const Texture* pDestinationTexture, const TextureCopyDesc& desc)
	{
		CopyTextureToTextureCore(pSourceTexture, pDestinationTexture, desc);
	}
	void CommandList::SetTextureMemoryBarrier(const Texture* pTexture, const TextureMemoryBarrierDesc& desc)
	{
		SetTextureMemoryBarrierCore(pTexture, desc);
	}
	void CommandList::SetBufferMemoryBarrier(const GraphicsBuffer* pBuffer, const BufferMemoryBarrierDesc& desc)
	{
		SetBufferMemoryBarrierCore(pBuffer, desc);
	}
	void CommandList::CommitResourceSets(DescriptorSet** ppSets, const Byte count)
	{
		CommitResourceSetsCore(ppSets, count);
	}
	void CommandList::ClearCachedState()
	{
		mBoundPipeline = nullptr;
		mBoundRenderPass = nullptr;
	}
}
