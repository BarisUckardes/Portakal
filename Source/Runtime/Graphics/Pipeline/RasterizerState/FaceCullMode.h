#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
	enum class RUNTIME_API FaceCullMode : Byte
	{
		None = 1,
		Front = 2,
		Back = 4
	};

	GENERATE_FLAGS(FaceCullMode, Byte)
}