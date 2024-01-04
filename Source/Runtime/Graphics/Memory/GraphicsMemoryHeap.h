#pragma once
#include <Runtime/Graphics/Device/GraphicsDeviceObject.h>
#include <Runtime/Graphics/Memory/GraphicsMemoryHeapDesc.h>
#include <Runtime/Containers/LinkedList.h>

namespace Portakal
{
	typedef Uint64 MemoryHandle;
	class RUNTIME_API GraphicsMemoryHeap : public GraphicsDeviceObject
	{
	private:
		struct SubAllocationBlock
		{
			Bool8 bOwned;
			Uint64 SizeInBytes;
		};
	public:
		GraphicsMemoryHeap(const GraphicsMemoryHeapDesc& desc);
		~GraphicsMemoryHeap() = default;

		FORCEINLINE Uint64 GetHeapSize() const noexcept
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
		MemoryHandle Allocate(const Uint64 sizeInBytes);
		void Free(const MemoryHandle handle);
	protected:
		virtual MemoryHandle AllocateCore(const Uint64 offsetInBytes) = 0;
	private:
		const Uint64 mSize;
		const GraphicsMemoryType mType;
		Uint64 mOccupiedSize;
		LinkedList<SubAllocationBlock> mBlocks;
	};
}
