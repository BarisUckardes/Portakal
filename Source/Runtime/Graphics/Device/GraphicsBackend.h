#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
	enum class RUNTIME_API GraphicsBackend : Byte
	{
		Vulkan,
		DirectX12,
		GNMX,
		NVM
	};
}
