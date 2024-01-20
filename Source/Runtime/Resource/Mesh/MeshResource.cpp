#include "MeshResource.h"
#include <Runtime/Graphics/GraphicsAPI.h>

namespace Portakal
{
	MeshResource::MeshResource(const SharedHeap<GraphicsDevice>& pDevice) : mIndexCount(0),mVertexCount(0)
	{
		mDevice = pDevice;
		CreateInternalResources();
	}
	MeshResource::MeshResource()
	{
		mDevice = GraphicsAPI::GetDefaultDevice();
		CreateInternalResources();
	}
	void MeshResource::AllocateVertexes(const UInt32 count, const UInt32 elementSize, const SharedHeap<GraphicsMemoryHeap>& pDeviceHeap, const SharedHeap<GraphicsMemoryHeap>& pHostHeap, const Bool8 bAllocateStagebufferUpfront)
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
		mVertexCount = count;
	}
	void MeshResource::AllocateIndexes(const UInt32 count, const UInt32 elementSize, const SharedHeap<GraphicsMemoryHeap>& pDeviceHeap, const SharedHeap<GraphicsMemoryHeap>& pHostHeap, const Bool8 bAllocateStagebufferUpfront)
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
		mIndexCount = count;
	}
	void MeshResource::UpdateVertexes(const MemoryView memory, const UInt32 offset)
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
	void MeshResource::UpdateIndexes(const MemoryView memory, const UInt32 offset)
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
		mCmdList = mDevice->CreateCommandList(cmdListDesc);

		mFence = mDevice->CreateFence();
	}
	void MeshResource::OnShutdown()
	{
		Clear();
	}
}