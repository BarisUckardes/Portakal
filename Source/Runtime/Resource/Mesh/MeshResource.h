#pragma once
#include <Runtime/Resource/ResourceSubObject.h>
#include <Runtime/Graphics/Command/CommandList.h>
#include <Runtime/Graphics/Device/GraphicsDevice.h>
#include <Runtime/Graphics/Fence/Fence.h>
#include <Runtime/Graphics/Buffer/GraphicsBuffer.h>
#include "MeshResource.reflected.h"

namespace Portakal
{

	/// <summary>
	/// A resource sub object that is specialized in mesh works
	/// </summary>
	PATTRIBUTE(ResourceAttribute, "mesh");
	PCLASS();
	class RUNTIME_API MeshResource : public ResourceSubObject
	{
		GENERATE_OBJECT;
	private:
		struct RUNTIME_API SubMeshResource
		{
			SharedHeap<GraphicsBuffer> pVertexBuffer;
			SharedHeap<GraphicsBuffer> pIndexBuffer;
			SharedHeap<GraphicsBuffer> pVertexStageBuffer;
			SharedHeap<GraphicsBuffer> pIndexStageBuffer;
		};
	public:
		MeshResource();
		~MeshResource() = default;

		FORCEINLINE UInt32 GetSubMeshCount() const noexcept
		{
			return mSubMeshes.GetSize();
		}
		FORCEINLINE UInt32 GetVertexCount(const UInt32 subMeshIndex) const noexcept
		{
			if (subMeshIndex >= mSubMeshes.GetSize())
				return 0;

			return mSubMeshes[subMeshIndex].pVertexBuffer->GetSubItemCount();
		}
		FORCEINLINE UInt32 GetIndexCount(const UInt32 subMeshIndex) const noexcept
		{
			if (subMeshIndex >= mSubMeshes.GetSize())
				return 0;

			return mSubMeshes[subMeshIndex].pIndexBuffer->GetSubItemCount();
		}
		FORCEINLINE UInt64 GetTotalVertexCount() const noexcept
		{
			return mTotalVertexCount;
		}
		FORCEINLINE UInt64 GetTotalIndexCount() const noexcept
		{
			return mTotalIndexCount;
		}
		FORCEINLINE SharedHeap<GraphicsBuffer> GetVertexBuffer(const UInt32 subMeshIndex) const noexcept
		{
			return mSubMeshes[subMeshIndex].pVertexBuffer;
		}
		FORCEINLINE SharedHeap<GraphicsBuffer> GetIndexBuffer(const UInt32 subMeshIndex) const noexcept
		{
			return mSubMeshes[subMeshIndex].pIndexBuffer;
		}
	public:
		void SetMemoryProfile(const SharedHeap<GraphicsMemory>& pHeapDevice, const SharedHeap<GraphicsMemory>& pHeapHost,bool bAllocateStagebuffersUpfront = true);
		void AllocateSubMesh(const UInt32 vertexCount,const UInt32 perVertexSize,const UInt32 indexCount,const UInt32 perIndexSize);
		void UpdateSubMeshVertexes(const UInt32 subMeshIndex,const MemoryView memory,const UInt32 offset);
		void UpdateSubMeshIndexes(const UInt32 subMeshIndex,const MemoryView memory,const UInt32 offset);
		void DeleteSubMesh(const UInt32 index);
	private:
		void ClearSubMesh(SubMeshResource& mesh);
		void Clear();
		void CreateInternalResources();
		virtual void OnShutdown() override;
	private:
		SharedHeap<GraphicsDevice> mDevice;
		SharedHeap<CommandPool> mCmdPool;
		SharedHeap<CommandList> mCmdList;
		SharedHeap<Fence> mFence;
		Array<SubMeshResource> mSubMeshes;
		SharedHeap<GraphicsMemory> mHeapDevice;
		SharedHeap<GraphicsMemory> mHeapHost;
		UInt64 mTotalVertexCount;
		UInt64 mTotalIndexCount;
		bool mAllocateStagebuffersUpfront;
	};
}



































































































































































































































































