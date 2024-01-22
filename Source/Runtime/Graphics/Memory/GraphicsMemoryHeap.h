#pragma once
#include <Runtime/Graphics/Device/GraphicsDeviceObject.h>
#include <Runtime/Graphics/Memory/GraphicsMemoryHeapDesc.h>
#include <Runtime/Containers/LinkedList.h>

namespace Portakal
{
	typedef UInt64 MemoryHandle;
	class RUNTIME_API GraphicsMemoryHeap : public GraphicsDeviceObject
	{
	private:
		struct SubAllocationBlock
		{
			Bool8 bOwned;
			UInt64 SizeInBytes;
		};
	public:
		GraphicsMemoryHeap(const GraphicsMemoryHeapDesc& desc);
		~GraphicsMemoryHeap() = default;

		FORCEINLINE UInt64 GetHeapSize() const noexcept
		{
			return mSize;
		}
		FORCEINLINE UInt64 GetOccupiedSize() const noexcept
		{
			return mOccupiedSize;
		}
		FORCEINLINE GraphicsMemoryType GetMemoryType() const noexcept
		{
			return mType;
		}
		virtual GraphicsDeviceObjectType GetObjectType() const noexcept override final
		{
			return GraphicsDeviceObjectType::MemoryHeap;
		}

		MemoryHandle Allocate(const UInt64 sizeInBytes);
		void Free(const MemoryHandle handle);
	protected:
		virtual MemoryHandle AllocateCore(const UInt64 offsetInBytes) = 0;
	private:
		const UInt64 mSize;
		const GraphicsMemoryType mType;
		UInt64 mOccupiedSize;
		LinkedList<SubAllocationBlock> mBlocks;
	};
}
