#pragma once
#include <Runtime/Core/Core.h>
#include <Runtime/Memory/MemoryView.h>

namespace Portakal
{
	/**
	 * @struct GraphicsBufferHostUpdateDesc
	 * 
	 * @brief It stores an information, so engine can update the buffer in the 
	 * CPU that is being mapped correspondingly to the GPU.
	 * 
	 */
	struct RUNTIME_API GraphicsBufferHostUpdateDesc
	{
		MemoryView View;
		Uint64 OffsetInBytes;
	};
}
