#pragma once
#include <Runtime/Core/Core.h>
#include <Runtime/Memory/SharedHeap.h>
#include <Runtime/Graphics/Buffer/GraphicsBufferUsage.h>
#include <Runtime/Graphics/Memory/GraphicsMemoryHeap.h>

namespace Portakal
{
	/**
	 * @struct GraphicsBufferDescriptor
	 * 
	 * @brief All the necessary information to create a graphics related buffer.
	 */
	struct RUNTIME_API GraphicsBufferDesc
	{
		GraphicsBufferUsage Usage;
		uint32 SubItemCount;
		uint32 SubItemSizeInBytes;
		SharedHeap<GraphicsMemoryHeap> pHeap;
	};
}
