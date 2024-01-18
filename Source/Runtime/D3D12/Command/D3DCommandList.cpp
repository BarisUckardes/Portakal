#include "D3DCommandList.h"

#include <Runtime/D3D12/Command/D3DCommandPool.h>

namespace Portakal
{
	D3DCommandList::D3DCommandList(const CommandListDesc& desc, D3DDevice* pDevice) : CommandList(desc)
	{
		DEV_ASSERT(SUCCEEDED(pDevice->GetD3DDevice()->CreateCommandList(0, ((D3DCommandPool*)(desc.pPool.GetHeap()))->GetCommandPoolType(), ((D3DCommandPool*)(desc.pPool.GetHeap()))->GetAllocator().Get(),
				   nullptr, IID_PPV_ARGS(&mCommandList))), "D3DCommandList", "Failed to create command list");
	}
	void D3DCommandList::BeginRecordingCore()
	{
		DEV_ASSERT(SUCCEEDED(mCommandList->Reset(mCommandPool.Get(), nullptr)), "D3DCommandList", "Failed to reset command pool");

		D3D12_RESOURCE_BARRIER barrier;
		barrier.Type = D3D12_RESOURCE_BARRIER_TYPE_TRANSITION;
		barrier.Flags = D3D12_RESOURCE_BARRIER_FLAG_NONE;
		barrier.Transition = { nullptr, D3D12_RESOURCE_BARRIER_ALL_SUBRESOURCES, D3D12_RESOURCE_STATE_COMMON, D3D12_RESOURCE_STATE_COMMON };
		barrier.UAV = { nullptr };
		mCommandList->ResourceBarrier(1, &barrier);
	}
	void D3DCommandList::EndRecordingCore()
	{
		DEV_ASSERT(SUCCEEDED(mCommandList->Close()), "D3DCommandList", "Failed to close command list");
	}
	void D3DCommandList::SetVertexBufferCore(const GraphicsBuffer* pBuffer)
	{
	}
	void D3DCommandList::SetIndexBufferCore(const GraphicsBuffer* pBuffer, const CommandListIndexBufferType type)
	{
	}
	void D3DCommandList::DrawIndexedCore(const UInt32 indexCount, const UInt32 indexOffset, const UInt32 vertexOffset, const UInt32 instanceCount, const UInt32 instanceOffset)
	{
	}
	void D3DCommandList::DispatchComputeCore(const UInt32 groupX, const UInt32 groupY, const UInt32 groupZ)
	{
	}
	void D3DCommandList::SetPipelineCore(const Pipeline* pPipeline)
	{
	}
	void D3DCommandList::SetViewportsCore(const ViewportDesc* pViewports, const Byte count)
	{
	}
	void D3DCommandList::SetScissorsCore(const ScissorDesc* pScissors, const Byte count)
	{
	}
	void D3DCommandList::CopyBufferToTextureCore(const GraphicsBuffer* pBuffer, const Texture* Texture, const BufferTextureCopyDesc& desc)
	{
	}
	void D3DCommandList::CopyBufferToBufferCore(const GraphicsBuffer* pSourceBuffer, const GraphicsBuffer* pDestinationBuffer, const BufferBufferCopyDesc& desc)
	{
	}
	void D3DCommandList::CopyTextureToTextureCore(const Texture* pSourceTexture, const Texture* pDestinationTexture, const TextureCopyDesc& desc)
	{
	}
	void D3DCommandList::SetTextureMemoryBarrierCore(const Texture* Texture, const CommandListTextureMemoryBarrierDesc& desc)
	{
	}
	void D3DCommandList::SetBufferMemoryBarrierCore(const GraphicsBuffer* pBuffer, const BufferBarrierDesc& desc)
	{
	}
	void D3DCommandList::CommitResourcesCore(ResourceTable** ppTables, const UInt32 count)
	{
	}
	void D3DCommandList::BeginRenderPassCore(const RenderPass* pRenderPass, const Color4F& clearColor, const Byte subFramebufferIndex)
	{

	}
	void D3DCommandList::EndRenderPassCore()
	{
	}
	void D3DCommandList::OnShutdown()
	{
	}
	void D3DCommandList::ClearTextureCore(const Texture* pTexture, const Color4F clearColor)
	{
	}
}