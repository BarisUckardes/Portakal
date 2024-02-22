#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
	struct RUNTIME_API BufferBufferCopyDesc
	{
		UInt64 SourceOffsetInBytes;
		UInt64 DestinationOffsetInBytes;
		UInt64 SizeInBytes;
	};
}
