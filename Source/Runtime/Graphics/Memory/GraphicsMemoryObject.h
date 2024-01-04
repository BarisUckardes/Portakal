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
		FORCEINLINE MemoryHandle GetMemoryHandle() const noexcept
		{
			return mMemory;
		}
		FORCEINLINE MemoryHandle GetAlignedMemoryHandle() const noexcept
		{
			return mAlignedMemory;
		}
		FORCEINLINE SharedHeap<GraphicsMemoryHeap> GetGraphicsHeap() const noexcept
		{
			return mHeap;
		}

	protected:
		void Allocate(const UInt64 size);
		void Free();
		void SetAlignedMemory(const MemoryHandle handle);
		virtual void OnShutdown() override;
	private:
		SharedHeap<GraphicsMemoryHeap> mHeap;
		MemoryHandle mMemory;
		MemoryHandle mAlignedMemory;
		UInt64 mSize;
	};
}
