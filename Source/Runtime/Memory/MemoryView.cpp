#include "MemoryView.h"
#include <Runtime/Memory/MemoryOwnedView.h>

namespace Portakal
{

	MemoryView::MemoryView(const MemoryView& other) : mMemory(other.mMemory), mSize(other.mSize)
	{

	}

	MemoryView::MemoryView(const MemoryOwnedView* pView) : mMemory(pView->GetMemory()), mSize(pView->GetSize())
	{

	}

	MemoryView::MemoryView() : mMemory(nullptr), mSize(0)
	{

	}
	MemoryView::~MemoryView()
	{

	}
}
