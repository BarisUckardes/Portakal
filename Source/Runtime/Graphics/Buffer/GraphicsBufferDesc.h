#pragma once
#include <Runtime/Core/Core.h>
#include <Runtime/Graphics/Buffer/GraphicsBufferUsage.h>
#include <Runtime/Graphics/Memory/GraphicsMemory.h>
#include <Runtime/Memory/SharedHeap.h>

namespace Portakal
{
	struct RUNTIME_API GraphicsBufferDesc
	{
		GraphicsBufferUsage Usage;
		UInt32 SubItemCount;
		UInt32 SubItemSizeInBytes;
		SharedHeap<GraphicsMemory> pMemory;
	};
}
