#pragma once
#include <Runtime/Graphics/Device/GraphicsDeviceObject.h>
#include <Runtime/Graphics/Memory/GraphicsMemoryHeapDesc.h>
#include <Runtime/Containers/LinkedList.h>

namespace Portakal
{
	typedef uint64 MemoryHandle;
	class RUNTIME_API GraphicsMemoryHeap : public GraphicsDeviceObject
	{
	private:
		struct SubAllocationBlock
		{
			bool bOwned;
			uint64 SizeInBytes;
		};
	public:
		GraphicsMemoryHeap(const GraphicsMemoryHeapDesc& desc);
		~GraphicsMemoryHeap() = default;

		FORCEINLINE uint64 GetHeapSize() const noexcept
		{
			return mSize;
		}
		FORCEINLINE GraphicsMemoryType GetMemoryType() const noexcept
		{
			return mType;
		}
		virtual GraphicsDeviceObjectType GetObjectType() const noexcept override final
		{
			return GraphicsDeviceObjectType::MemoryHeap;
		}
		MemoryHandle Allocate(const uint64 sizeInBytes);
		void Free(const MemoryHandle handle);
	protected:
		virtual MemoryHandle AllocateCore(const uint64 offsetInBytes) = 0;
	private:
		const uint64 mSize;
		const GraphicsMemoryType mType;
		uint64 mOccupiedSize;
		LinkedList<SubAllocationBlock> mBlocks;
	};
}
