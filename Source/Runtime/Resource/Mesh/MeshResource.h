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

		FORCEINLINE UInt32 GetVertexCount() const noexcept
		{
			return mVertexCount;
		}
		FORCEINLINE UInt32 GetIndexCount() const noexcept
		{
			return mIndexCount;
		}
		FORCEINLINE SharedHeap<GraphicsBuffer> GetVertexBuffer() const noexcept
		{
			return mVertexDeviceBuffer;
		}
		FORCEINLINE SharedHeap<GraphicsBuffer> GetIndexBuffer() const noexcept
		{
			return mIndexDeviceBuffer;
		}
	public:
		void AllocateVertexes(const UInt32 count,const UInt32 elementSize,const SharedHeap<GraphicsMemoryHeap>& pDeviceHeap,const SharedHeap<GraphicsMemoryHeap>& pHostHeap,const Bool8 bAllocateStagebufferUpfront);
		void AllocateIndexes(const UInt32 count,const UInt32 elementSize,const SharedHeap<GraphicsMemoryHeap>& pDeviceHeap,const SharedHeap<GraphicsMemoryHeap>& pHostHeap,const Bool8 bAllocateStagebufferUpfront);
		void UpdateVertexes(const MemoryView memory,const UInt32 offset);
		void UpdateIndexes(const MemoryView memory,const UInt32 offset);
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
		UInt32 mVertexCount;
		UInt32 mIndexCount;
	};
}









































































































































































































































