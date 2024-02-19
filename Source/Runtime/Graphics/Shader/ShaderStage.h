#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
	enum class RUNTIME_API ShaderStage : Byte
	{
		Vertex = 1,
		Fragment = 2,
		Geometry = 4,
		TesellationEval = 8,
		TesellationControl = 16,
		Compute = 32
	};
	GENERATE_FLAGS(ShaderStage,Byte)
}
