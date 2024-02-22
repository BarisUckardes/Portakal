#pragma once
#include <Runtime/Core/Core.h>
#include <Runtime/Memory/MemoryView.h>

namespace Portakal
{
	struct RUNTIME_API HostBufferUpdateDesc
	{
		MemoryView Buffer;
		unsigned long long OffsetInBytes;
	};
}
