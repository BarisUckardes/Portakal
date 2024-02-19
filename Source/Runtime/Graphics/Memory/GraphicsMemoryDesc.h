#pragma once
#include <Runtime/Graphics/Memory/GraphicsMemoryType.h>

namespace Portakal
{
	struct RUNTIME_API GraphicsMemoryDesc
	{
		GraphicsMemoryType Type;
		UInt64 SizeInBytes;
	};
}
