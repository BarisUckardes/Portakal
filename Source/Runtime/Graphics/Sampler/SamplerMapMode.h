#pragma once
#include <Runtime/Core/Core.h>
#include "SamplerMapMode.reflected.h"

namespace Portakal
{
	PENUM();
	enum class RUNTIME_API SamplerMapMode : Int64
	{
		None,
		Linear,
		Nearest
	};

	GENERATE_FLAGS(SamplerMapMode, Byte);
}

