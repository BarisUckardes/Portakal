#pragma once
#include <Runtime/Core/Core.h>
#include <Runtime/Graphics/Memory/GraphicsMemoryType.h>

namespace Portakal
{
	struct RUNTIME_API GraphicsMemoryHeapDesc
	{
		GraphicsMemoryType Type;
		uint64 SizeInBytes;
	};
}
