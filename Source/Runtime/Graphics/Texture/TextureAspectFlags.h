#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
	enum class RUNTIME_API TextureAspectFlags : Byte
	{
		Color = 1,
		Depth = 2,
		Stencil = 4
	};
	GENERATE_FLAGS(TextureAspectFlags, Byte);
}
