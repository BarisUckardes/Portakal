#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
	enum class RUNTIME_API GraphicsBackend : byte
	{
		Vulkan,
		DirectX12,
		GNMX,
		NVM
	};
}
