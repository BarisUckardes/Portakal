#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
	enum class RUNTIME_API GraphicsBackend : public byte
	{
		Vulkan,
		Directx12,
		GNMX,
		NVM
	};
}
