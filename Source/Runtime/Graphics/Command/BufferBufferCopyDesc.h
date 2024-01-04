#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
	/**
	 * @struct BufferBufferCopyDesc
	 * 
	 * @brief It is used to update a buffer from another buffer.
	 */
	struct RUNTIME_API BufferBufferCopyDesc
	{
		Uint64 SourceOffsetInBytes;
		Uint64 DestinationOffsetInBytes;
		Uint64 SizeInBytes;
	};
}
