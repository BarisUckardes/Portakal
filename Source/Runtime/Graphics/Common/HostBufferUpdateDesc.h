#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
	struct RUNTIME_API HostBufferUpdateDesc
	{
		Byte* pBuffer;
		UInt64 SizeInBytes;
		UInt64 OffsetInBytes;
	};
}
