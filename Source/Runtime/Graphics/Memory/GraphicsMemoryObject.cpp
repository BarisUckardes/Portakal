#include "GraphicsMemoryObject.h"

namespace Portakal
{
	GraphicsMemoryObject::GraphicsMemoryObject(const SharedHeap<GraphicsMemoryHeap>& pHeap) : mHeap(pHeap),mMemory(uint64_max),mAlignedMemory(uint64_max), mSize(0)
	{

	}
	void GraphicsMemoryObject::OnShutdown()
	{
		Free();
	}
	void GraphicsMemoryObject::Free()
	{
		//Reset size
		mSize = 0;

		//Validate
		if (mHeap.IsShutdown())
			return;

		//Free memory
		mHeap->Free(mMemory);
		mMemory = uint64_max;
		mAlignedMemory = uint64_max;
	}
	void GraphicsMemoryObject::SetMemoryProperties(const MemoryHandle handle, const MemoryHandle alignedHandle)
	{
		mMemory = handle;
		mAlignedMemory = alignedHandle;
	}
}
