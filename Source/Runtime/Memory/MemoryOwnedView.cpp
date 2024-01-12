#include "MemoryOwnedView.h"
#include <Runtime/Memory/Memory.h>

namespace Portakal
{
	MemoryOwnedView::MemoryOwnedView(void* pMemory, const UInt64 sizeInBytes) : mSize(sizeInBytes)
	{
		mMemory = pMemory;
	}

	MemoryOwnedView::MemoryOwnedView(void* pMemoryStart, void* pMemoryEnd)
	{
		const UInt64 sizeInBytes = ((Byte*)pMemoryEnd - (Byte*)pMemoryStart);
		mMemory = pMemoryStart;
		mSize = sizeInBytes;
	}

	MemoryOwnedView::~MemoryOwnedView()
	{
		delete mMemory;
		mMemory = nullptr;
	}
}
