#pragma once

namespace Portakal
{
	struct RUNTIME_API BufferBufferCopyDesc
	{
		UInt64 SourceOffsetInBytes;
		UInt64 DestinationOffsetInBytes;
		UInt64 SizeInBytes;
	};
}
