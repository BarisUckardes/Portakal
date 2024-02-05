#pragma once
#include <Runtime/Graphics/Memory/GraphicsMemoryHeap.h>

namespace Portakal
{
	class RUNTIME_API GraphicsMemoryObject : public GraphicsDeviceObject
	{
	public:
		GraphicsMemoryObject(const SharedHeap<GraphicsMemoryHeap>& pHeap);
		~GraphicsMemoryObject() = default;

		FORCEINLINE UInt64 GetMemorySize() const noexcept
		{
			return mSize;
		}
		FORCEINLINE UInt64 GetMemoryHandle() const noexcept
		{
			return mMemory;
		}
		FORCEINLINE UInt64 GetAlignedMemoryHandle() const noexcept
		{
			return mAlignedMemory;
		}
		FORCEINLINE SharedHeap<GraphicsMemoryHeap> GetGraphicsHeap() const noexcept
		{
			return mHeap;
		}

	protected:
		void Free();
		void SetMemoryProperties(const UInt64 offset,const UInt64 alignedOffset);
		virtual void OnShutdown() override;
	private:
		SharedHeap<GraphicsMemoryHeap> mHeap;
		UInt64 mMemory;
		UInt64 mAlignedMemory;
		UInt64 mSize;
	};
}
