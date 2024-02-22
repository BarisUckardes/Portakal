#pragma once
#include <Runtime/Core/Core.h>
#include <Runtime/Memory/SharedHeap.h>
#include <Runtime/Graphics/Buffer/GraphicsBufferUsage.h>
#include <Runtime/Graphics/Memory/GraphicsMemory.h>

namespace Portakal
{
	/**
	 * @struct GraphicsBufferDesc
	 * 
	 * @brief All the necessary information to create a graphics related buffer.
	 */
	struct RUNTIME_API GraphicsBufferDesc
	{
		GraphicsBufferUsage Usage;
		UInt32 SubItemCount;
		UInt32 SubItemSizeInBytes;
		SharedHeap<GraphicsMemory> pHeap;
	};
}
