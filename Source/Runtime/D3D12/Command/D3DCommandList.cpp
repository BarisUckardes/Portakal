#include "D3DCommandList.h"

namespace Portakal
{
	D3DCommandList::D3DCommandList(const CommandListDesc& desc, D3DDevice* pDevice) : CommandList(desc)
	{
	}
	void D3DCommandList::BeginRecordingCore()
	{
	}
	void D3DCommandList::EndRecordingCore()
	{
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