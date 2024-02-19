#pragma once
#include <Runtime/Graphics/Device/GraphicsDeviceObject.h>
#include <Runtime/Graphics/Memory/GraphicsMemoryDesc.h>
#include <Runtime/Containers/Array.h>

namespace Portakal
{
	class RUNTIME_API GraphicsMemory : public GraphicsDeviceObject
	{
	private:
		struct SubAllocationBlock
		{
			bool bOwned;
			UInt64 SizeInBytes;
		};
		struct CompactReport
		{
			UInt32 Min;
			UInt32 Max;
		};
	public:
		~GraphicsMemory() = default;

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

		UInt64 Allocate(const UInt64 sizeInBytes);
		void Free(const UInt64 offsetInBytes);
	protected:
		GraphicsMemory(const GraphicsMemoryDesc& desc,GraphicsDevice* pDevice);
	private:
		CompactReport GetCompactReport(const UInt32 index);
		void Compact(const CompactReport& report);
	private:
		const UInt64 mSize;
		const GraphicsMemoryType mType;
		UInt64 mOccupiedSize;
		Array<SubAllocationBlock> mBlocks;
	};
}
