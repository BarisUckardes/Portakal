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
		UInt64 SourceOffsetInBytes;
		UInt64 DestinationOffsetInBytes;
		UInt64 SizeInBytes;
	};
}
