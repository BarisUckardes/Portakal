#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
	enum class RUNTIME_API PipelineBindPoint : Byte
	{
		Graphics,
		Compute,
		Raytracing
	};
}
