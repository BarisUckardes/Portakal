#pragma once
#include <Runtime/Resource/ResourceSubObject.h>
#include <Runtime/Graphics/Command/CommandList.h>
#include <Runtime/Graphics/Device/GraphicsDevice.h>
#include <Runtime/Graphics/Fence/Fence.h>
#include <Runtime/Graphics/Buffer/GraphicsBuffer.h>
#include "MeshResource.reflected.h"

namespace Portakal
{
	PCLASS();
	class RUNTIME_API MeshResource : public ResourceSubObject
	{
		GENERATE_OBJECT;
	public:
		MeshResource(const SharedHeap<GraphicsDevice>& pDevice);
		MeshResource();
		~MeshResource() = default;

	public:
		void AllocateVertexes(const uint32 count,const uint32 elementSize,const SharedHeap<GraphicsMemoryHeap>& pDeviceHeap,const SharedHeap<GraphicsMemoryHeap>& pHostHeap,const bool bAllocateStagebufferUpfront);
		void AllocateIndexes(const uint32 count,const uint32 elementSize,const SharedHeap<GraphicsMemoryHeap>& pDeviceHeap,const SharedHeap<GraphicsMemoryHeap>& pHostHeap,const bool bAllocateStagebufferUpfront);
		void UpdateVertexes(const MemoryView memory,const uint32 offset);
		void UpdateIndexes(const MemoryView memory,const uint32 offset);
	private:
		void Clear();
		void CreateInternalResources();
		virtual void OnShutdown() override;
	private:
		SharedHeap<GraphicsDevice> mDevice;
		SharedHeap<CommandPool> mCmdPool;
		SharedHeap<CommandList> mCmdList;
		SharedHeap<Fence> mFence;
		SharedHeap<GraphicsBuffer> mVertexDeviceBuffer;
		SharedHeap<GraphicsBuffer> mIndexDeviceBuffer;
		SharedHeap<GraphicsBuffer> mVertexStageBuffer;
		SharedHeap<GraphicsBuffer> mIndexStageBuffer;
		SharedHeap<GraphicsMemoryHeap> mVertexHostHeap;
		SharedHeap<GraphicsMemoryHeap> mIndexHostHeap;
	};
}










































