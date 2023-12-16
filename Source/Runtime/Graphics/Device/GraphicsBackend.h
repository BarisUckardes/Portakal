#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
	enum class RUNTIME_API GraphicsBackend : byte
	{
		Vulkan,
		Directx12,
		GNMX,
		NVM
	};
}
