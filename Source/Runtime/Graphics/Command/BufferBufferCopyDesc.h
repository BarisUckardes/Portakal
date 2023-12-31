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
		uint64 SourceOffsetInBytes;
		uint64 DestinationOffsetInBytes;
		uint64 SizeInBytes;
	};
}
