#include "MemoryOwnedView.h"
#include <Runtime/Memory/Memory.h>

namespace Portakal
{
	MemoryOwnedView::MemoryOwnedView(void* pMemory, const uint64 sizeInBytes) : mSize(sizeInBytes)
	{
		mMemory = new byte[sizeInBytes];
		Memory::Copy(mMemory, pMemory, sizeInBytes);
	}

	MemoryOwnedView::MemoryOwnedView(void* pMemoryStart, void* pMemoryEnd)
	{
		const uint64 sizeInBytes = ((byte*)pMemoryEnd - (byte*)pMemoryStart);
		mMemory = new byte[sizeInBytes];
		Memory::Copy(mMemory, pMemoryStart, sizeInBytes);
		mSize = sizeInBytes;
	}

	MemoryOwnedView::~MemoryOwnedView()
	{
		delete mMemory;
		mMemory = nullptr;
	}
}
