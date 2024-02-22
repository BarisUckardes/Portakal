#include "MeshResource.h"
#include <Runtime/Graphics/GraphicsAPI.h>

namespace Portakal
{
	MeshResource::MeshResource() : mAllocateStagebuffersUpfront(true)
	{
		mDevice = GraphicsAPI::GetDefaultDevice();
		CreateInternalResources();
	}

	void MeshResource::SetMemoryProfile(const SharedHeap<GraphicsMemory>& pHeapDevice, const SharedHeap<GraphicsMemory>& pHeapHost, bool bAllocateStagebuffersUpfront)
	{
		//Clear current setup
		Clear();

		//Set current memory profile
		mHeapDevice = pHeapDevice;
		mHeapHost = pHeapHost;
		mAllocateStagebuffersUpfront = bAllocateStagebuffersUpfront;
	}

	void MeshResource::AllocateSubMesh(const UInt32 vertexCount, const UInt32 perVertexSize, const UInt32 indexCount, const UInt32 perIndexSize)
	{
		if (mDevice.IsShutdown())
			return;
		if (mHeapDevice.IsShutdown())
			return;
		if (mHeapHost.IsShutdown())
			return;

		SubMeshResource subMesh = {};

		//Allocate vertex buffer
		GraphicsBufferDesc vertexBufferDesc = {};
		vertexBufferDesc.SubItemCount = vertexCount;
		vertexBufferDesc.SubItemSizeInBytes = perVertexSize;
		vertexBufferDesc.Usage = GraphicsBufferUsage::VertexBuffer | GraphicsBufferUsage::TransferDestination;
		vertexBufferDesc.pHeap = mHeapDevice;
		subMesh.pVertexBuffer = mDevice->CreateBuffer(vertexBufferDesc);

		//Allocate vertex stage buffer
		if (mAllocateStagebuffersUpfront)
		{
			GraphicsBufferDesc desc = {};
			desc.SubItemCount = vertexCount;
			desc.SubItemSizeInBytes = perVertexSize;
			desc.Usage = GraphicsBufferUsage::VertexBuffer | GraphicsBufferUsage::TransferSource;
			desc.pHeap = mHeapHost;
			subMesh.pVertexStageBuffer = mDevice->CreateBuffer(desc);
		}

		//Allocate index buffer
		GraphicsBufferDesc indexBufferDesc = {};
		indexBufferDesc.SubItemCount = indexCount;
		indexBufferDesc.SubItemSizeInBytes = perIndexSize;
		indexBufferDesc.Usage = GraphicsBufferUsage::IndexBuffer | GraphicsBufferUsage::TransferDestination;
		indexBufferDesc.pHeap = mHeapDevice;
		subMesh.pIndexBuffer = mDevice->CreateBuffer(indexBufferDesc);

		//Allocate index stage buffer
		if (mAllocateStagebuffersUpfront)
		{
			GraphicsBufferDesc desc = {};
			desc.SubItemCount = indexCount;
			desc.SubItemSizeInBytes = perIndexSize;
			desc.Usage = GraphicsBufferUsage::IndexBuffer | GraphicsBufferUsage::TransferSource;
			desc.pHeap = mHeapHost;
			subMesh.pIndexStageBuffer = mDevice->CreateBuffer(desc);
		}

		//Register submesh
		mSubMeshes.Add(subMesh);

		//Increment
		mTotalVertexCount += vertexCount;
		mTotalIndexCount += indexCount;
	}
	void MeshResource::UpdateSubMeshVertexes(const UInt32 subMeshIndex, const MemoryView memory, const UInt32 offset)
	{
		if (mDevice.IsShutdown())
			return;
		if (subMeshIndex >= mSubMeshes.GetSize())
			return;

		//Get sub mesh
		SubMeshResource& subMesh = mSubMeshes[subMeshIndex];

		//Allocate stage buffer if needed
		if (!mAllocateStagebuffersUpfront)
		{
			GraphicsBufferDesc desc = {};
			desc.SubItemCount = subMesh.pVertexBuffer->GetSubItemCount();
			desc.SubItemSizeInBytes = subMesh.pVertexBuffer->GetSubItemSize();
			desc.Usage = GraphicsBufferUsage::VertexBuffer | GraphicsBufferUsage::TransferSource;
			desc.pHeap = mHeapHost;
			subMesh.pVertexStageBuffer = mDevice->CreateBuffer(desc);
		}

		//Update host buffer
		GraphicsBufferHostUpdateDesc hostUpdateDesc = {};
		hostUpdateDesc.OffsetInBytes = offset;
		hostUpdateDesc.View = memory;
		mDevice->UpdateHostBuffer(subMesh.pVertexStageBuffer.GetHeap(), hostUpdateDesc);

		//Update device buffer
		mCmdList->BeginRecording();
		BufferBufferCopyDesc deviceCopyDesc = {};
		deviceCopyDesc.DestinationOffsetInBytes = offset;
		deviceCopyDesc.SourceOffsetInBytes = offset;
		deviceCopyDesc.SizeInBytes = memory.GetSize();
		mCmdList->CopyBufferToBuffer(subMesh.pVertexStageBuffer.GetHeap(), subMesh.pVertexBuffer.GetHeap(), deviceCopyDesc);
		mCmdList->EndRecording();
		mDevice->SubmitCommandLists(mCmdList.GetHeapAddress(), 1,GraphicsAPI::GetDefaultGraphicsQueue().GetHeap(),nullptr,0,nullptr,nullptr,0,mFence.GetHeap());
		mDevice->WaitFences(mFence.GetHeapAddress(), 1);
		mDevice->ResetFences(mFence.GetHeapAddress(), 1);
	}
	void MeshResource::UpdateSubMeshIndexes(const UInt32 subMeshIndex, const MemoryView memory, const UInt32 offset)
	{
		if (mDevice.IsShutdown())
			return;
		if (subMeshIndex >= mSubMeshes.GetSize())
			return;

		//Get sub mesh
		SubMeshResource& subMesh = mSubMeshes[subMeshIndex];

		//Allocate stage buffer if needed
		if (!mAllocateStagebuffersUpfront)
		{
			GraphicsBufferDesc desc = {};
			desc.SubItemCount = subMesh.pVertexBuffer->GetSubItemCount();
			desc.SubItemSizeInBytes = subMesh.pVertexBuffer->GetSubItemSize();
			desc.Usage = GraphicsBufferUsage::IndexBuffer | GraphicsBufferUsage::TransferSource;
			desc.pHeap = mHeapHost;
			subMesh.pIndexStageBuffer = mDevice->CreateBuffer(desc);
		}

		//Update host buffer
		GraphicsBufferHostUpdateDesc hostUpdateDesc = {};
		hostUpdateDesc.OffsetInBytes = offset;
		hostUpdateDesc.View = memory;
		mDevice->UpdateHostBuffer(subMesh.pIndexStageBuffer.GetHeap(), hostUpdateDesc);

		//Update device buffer
		mCmdList->BeginRecording();
		BufferBufferCopyDesc deviceCopyDesc = {};
		deviceCopyDesc.DestinationOffsetInBytes = offset;
		deviceCopyDesc.SourceOffsetInBytes = offset;
		deviceCopyDesc.SizeInBytes = memory.GetSize();
		mCmdList->CopyBufferToBuffer(subMesh.pIndexStageBuffer.GetHeap(), subMesh.pIndexBuffer.GetHeap(), deviceCopyDesc);
		mCmdList->EndRecording();
		mDevice->SubmitCommandLists(mCmdList.GetHeapAddress(), 1, GraphicsAPI::GetDefaultGraphicsQueue().GetHeap(), nullptr, 0, nullptr, nullptr, 0, mFence.GetHeap());
		mDevice->WaitFences(mFence.GetHeapAddress(), 1);
		mDevice->ResetFences(mFence.GetHeapAddress(),1);
	}
	void MeshResource::DeleteSubMesh(const UInt32 index)
	{
		if (index >= mSubMeshes.GetSize())
			return;

		ClearSubMesh(mSubMeshes[index]);
		mSubMeshes.RemoveAt(index);
	}
	void MeshResource::ClearSubMesh(SubMeshResource& mesh)
	{
		//Decrement
		mTotalVertexCount -= mesh.pVertexBuffer->GetSubItemCount();
		mTotalIndexCount -= mesh.pIndexBuffer->GetSubItemCount();
		//Shutdown
		mesh.pVertexStageBuffer.Shutdown();
		mesh.pIndexStageBuffer.Shutdown();
		mesh.pVertexBuffer.Shutdown();
		mesh.pIndexBuffer.Shutdown();
	}
	void MeshResource::Clear()
	{
		for (SubMeshResource& mesh : mSubMeshes)
			ClearSubMesh(mesh);
		mSubMeshes.Clear();
	}
	void MeshResource::CreateInternalResources()
	{
		CommandPoolDesc cmdPoolDesc = {};
		cmdPoolDesc.Type = CommandPoolType::Graphics;
		mCmdPool = mDevice->CreateCommandPool(cmdPoolDesc);

		CommandListDesc cmdListDesc = {};
		cmdListDesc.pPool = mCmdPool;
		mCmdList = mDevice->CreateCommandList(cmdListDesc);

		mFence = mDevice->CreateFence(false);
	}
	void MeshResource::OnShutdown()
	{
		Clear();
	}
}