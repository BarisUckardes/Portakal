#include "MemoryOwnedView.h"
#include <Runtime/Memory/Memory.h>

namespace Portakal
{
	MemoryOwnedView::MemoryOwnedView(void* pMemory, const UInt64 sizeInBytes) : mSize(sizeInBytes)
	{
		mMemory = new Byte[sizeInBytes];
		Memory::Copy(mMemory, pMemory, sizeInBytes);
	}

	MemoryOwnedView::MemoryOwnedView(void* pMemoryStart, void* pMemoryEnd)
	{
		const UInt64 sizeInBytes = ((Byte*)pMemoryEnd - (Byte*)pMemoryStart);
		mMemory = new Byte[sizeInBytes];
		Memory::Copy(mMemory, pMemoryStart, sizeInBytes);
		mSize = sizeInBytes;
	}

	MemoryOwnedView::~MemoryOwnedView()
	{
		delete mMemory;
		mMemory = nullptr;
	}
}
