#include "GraphicsMemoryObject.h"

namespace Portakal
{
	GraphicsMemoryObject::GraphicsMemoryObject(const SharedHeap<GraphicsMemoryHeap>& pHeap) : mHeap(pHeap),mMemory(uint64_max),mSize(0)
	{

	}
	void GraphicsMemoryObject::OnShutdown()
	{
		Free();
	}
	void GraphicsMemoryObject::Allocate(const uint64 size)
	{
		//Validate
		if (mHeap.IsShutdown())
		{
			Free();
			return;
		}

		//Allocate
		mMemory = mHeap->Allocate(size);
		mSize = size;
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
	void GraphicsMemoryObject::SetAlignedMemory(const MemoryHandle handle)
	{
		mAlignedMemory = handle;
	}
}
