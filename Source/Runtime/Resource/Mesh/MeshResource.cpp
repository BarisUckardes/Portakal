#include "MeshResource.h"

namespace Portakal
{
	MeshResource::MeshResource(const SharedHeap<GraphicsDevice>& pDevice)
	{
		mDevice = pDevice;
		CreateInternalResources();
	}
	MeshResource::MeshResource()
	{
		mDevice = nullptr;
		CreateInternalResources();
	}
	void MeshResource::AllocateVertexes(const uint32 count, const uint32 elementSize, const SharedHeap<GraphicsMemoryHeap>& pDeviceHeap, const SharedHeap<GraphicsMemoryHeap>& pHostHeap, const bool bAllocateStagebufferUpfront)
	{
		//Check if shutdown
		if (IsShutdown())
			return;

		//Check device
		if (mDevice.IsShutdown())
			return;

		//Create device buffer
		GraphicsBufferDesc deviceBufferDesc = {};
		deviceBufferDesc.SubItemCount = count;
		deviceBufferDesc.SubItemSizeInBytes = elementSize;
		deviceBufferDesc.Usage = GraphicsBufferUsage::VertexBuffer | GraphicsBufferUsage::TransferDestination;
		deviceBufferDesc.pHeap = pDeviceHeap;
		mVertexDeviceBuffer = mDevice->CreateBuffer(deviceBufferDesc);

		//Create stage buffer if required
		if (bAllocateStagebufferUpfront)
		{
			GraphicsBufferDesc desc = {};
			desc.SubItemCount = count;
			desc.SubItemSizeInBytes = elementSize;
			desc.Usage = GraphicsBufferUsage::VertexBuffer | GraphicsBufferUsage::TransferSource;
			desc.pHeap = pHostHeap;
			mVertexStageBuffer = mDevice->CreateBuffer(desc);
		}

		//Set properties
		mVertexHostHeap = pHostHeap;
	}
	void MeshResource::AllocateIndexes(const uint32 count, const uint32 elementSize, const SharedHeap<GraphicsMemoryHeap>& pDeviceHeap, const SharedHeap<GraphicsMemoryHeap>& pHostHeap, const bool bAllocateStagebufferUpfront)
	{
		//Check if shutdown
		if (IsShutdown())
			return;

		//Check device
		if (mDevice.IsShutdown())
			return;

		//Create device buffer
		GraphicsBufferDesc deviceBufferDesc = {};
		deviceBufferDesc.SubItemCount = count;
		deviceBufferDesc.SubItemSizeInBytes = elementSize;
		deviceBufferDesc.Usage = GraphicsBufferUsage::IndexBuffer | GraphicsBufferUsage::TransferDestination;
		deviceBufferDesc.pHeap = pDeviceHeap;
		mIndexDeviceBuffer = mDevice->CreateBuffer(deviceBufferDesc);

		//Create stage buffer if required
		if (bAllocateStagebufferUpfront)
		{
			GraphicsBufferDesc desc = {};
			desc.SubItemCount = count;
			desc.SubItemSizeInBytes = elementSize;
			desc.Usage = GraphicsBufferUsage::IndexBuffer | GraphicsBufferUsage::TransferSource;
			desc.pHeap = pHostHeap;
			mIndexStageBuffer = mDevice->CreateBuffer(desc);
		}

		//Set properties
		mIndexHostHeap = pHostHeap;
	}
	void MeshResource::UpdateVertexes(const MemoryView memory, const uint32 offset)
	{
		//Check if shutdown
		if (IsShutdown())
			return;

		//Check device
		if (mDevice.IsShutdown())
			return;

		//Check if stage buffer creation is required
		if (mVertexStageBuffer.IsShutdown())
		{
			GraphicsBufferDesc desc = {};
			desc.SubItemCount = mVertexDeviceBuffer->GetSubItemCount();
			desc.SubItemSizeInBytes = mVertexDeviceBuffer->GetSubItemSize();
			desc.Usage = GraphicsBufferUsage::VertexBuffer | GraphicsBufferUsage::TransferSource;
			desc.pHeap = mVertexHostHeap;
			mVertexStageBuffer = mDevice->CreateBuffer(desc);
		}

		//Update host buffer
		GraphicsBufferHostUpdateDesc hostUpdateDesc = {};
		hostUpdateDesc.OffsetInBytes = 0;
		hostUpdateDesc.View = memory;
		mDevice->UpdateHostBuffer(mVertexStageBuffer.GetHeap(),hostUpdateDesc);

		//Update vertex buffer
		mCmdList->BeginRecording();

		BufferBufferCopyDesc deviceCopyDesc = {};
		deviceCopyDesc.DestinationOffsetInBytes = offset;
		deviceCopyDesc.SourceOffsetInBytes = 0;
		deviceCopyDesc.SizeInBytes = memory.GetSize();
		mCmdList->CopyBufferToBuffer(mVertexStageBuffer.GetHeap(), mVertexDeviceBuffer.GetHeap(), deviceCopyDesc);

		mCmdList->EndRecording();

		mDevice->SubmitCommandLists(mCmdList.GetHeapAddress(), 1, GraphicsQueueType::Graphics, mFence.GetHeap());
		mDevice->WaitFences(mFence.GetHeapAddress(), 1);
	}
	void MeshResource::UpdateIndexes(const MemoryView memory, const uint32 offset)
	{
		//Check if shutdown
		if (IsShutdown())
			return;

		//Check device
		if (mDevice.IsShutdown())
			return;

		//Check if stage buffer creation is required
		if (mIndexStageBuffer.IsShutdown())
		{
			GraphicsBufferDesc desc = {};
			desc.SubItemCount = mIndexDeviceBuffer->GetSubItemCount();
			desc.SubItemSizeInBytes = mIndexDeviceBuffer->GetSubItemSize();
			desc.Usage = GraphicsBufferUsage::IndexBuffer | GraphicsBufferUsage::TransferSource;
			desc.pHeap = mIndexHostHeap;
			mIndexStageBuffer = mDevice->CreateBuffer(desc);
		}

		//Update host buffer
		GraphicsBufferHostUpdateDesc hostUpdateDesc = {};
		hostUpdateDesc.OffsetInBytes = 0;
		hostUpdateDesc.View = memory;
		mDevice->UpdateHostBuffer(mIndexStageBuffer.GetHeap(), hostUpdateDesc);

		//Update vertex buffer
		mCmdList->BeginRecording();

		BufferBufferCopyDesc deviceCopyDesc = {};
		deviceCopyDesc.DestinationOffsetInBytes = offset;
		deviceCopyDesc.SourceOffsetInBytes = 0;
		deviceCopyDesc.SizeInBytes = memory.GetSize();
		mCmdList->CopyBufferToBuffer(mIndexStageBuffer.GetHeap(), mIndexDeviceBuffer.GetHeap(), deviceCopyDesc);

		mCmdList->EndRecording();

		mDevice->SubmitCommandLists(mCmdList.GetHeapAddress(), 1, GraphicsQueueType::Graphics, mFence.GetHeap());
		mDevice->WaitFences(mFence.GetHeapAddress(), 1);
	}
	void MeshResource::Clear()
	{
		mVertexStageBuffer.Shutdown();
		mIndexStageBuffer.Shutdown();
		mVertexDeviceBuffer.Shutdown();
		mIndexDeviceBuffer.Shutdown();
	}
	void MeshResource::CreateInternalResources()
	{
		CommandPoolDesc cmdPoolDesc = {};
		cmdPoolDesc.Type = CommandPoolType::Graphics;
		mCmdPool = mDevice->CreateCommandPool(cmdPoolDesc);

		CommandListDesc cmdListDesc = {};
		cmdListDesc.pPool = mCmdPool;
		mDevice->CreateCommandList(cmdListDesc);

		mFence = mDevice->CreateFence();
	}
	void MeshResource::OnShutdown()
	{
		Clear();
	}
}