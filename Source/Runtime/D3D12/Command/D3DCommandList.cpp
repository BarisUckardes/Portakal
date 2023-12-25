#include "D3DCommandList.h"

#include <Runtime/D3D12/Command/D3DCommandPool.h>

namespace Portakal
{
	D3DCommandList::D3DCommandList(const CommandListDesc& desc, D3DDevice* pDevice) : CommandList(desc)
	{
		DEV_ASSERT(SUCCEEDED(pDevice->GetDevice()->CreateCommandList(0, ((D3DCommandPool*)(desc.pPool.GetHeap()))->GetCmdListTypeType(), ((D3DCommandPool*)(desc.pPool.GetHeap()))->GetAllocator().Get(),
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
	void D3DCommandList::DrawIndexedCore(const uint32 indexCount, const uint32 indexOffset, const uint32 vertexOffset, const uint32 instanceCount, const uint32 instanceOffset)
	{
	}
	void D3DCommandList::DispatchComputeCore(const uint32 groupX, const uint32 groupY, const uint32 groupZ)
	{
	}
	void D3DCommandList::SetPipelineCore(const Pipeline* pPipeline)
	{
	}
	void D3DCommandList::SetViewportsCore(const ViewportDesc* pViewports, const byte count)
	{
	}
	void D3DCommandList::SetScissorsCore(const ScissorDesc* pScissors, const byte count)
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
	void D3DCommandList::CommitResourcesCore(const Array<ResourceTable*>& resources)
	{
	}
	void D3DCommandList::BeginRenderPassCore(const RenderPass* pRenderPass, const Color4F& clearColor, const byte subFramebufferIndex)
	{

	}
	void D3DCommandList::EndRenderPassCore()
	{
	}
	void D3DCommandList::OnShutdown()
	{
	}
}