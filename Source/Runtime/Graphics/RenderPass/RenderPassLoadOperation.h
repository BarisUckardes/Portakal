#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
	enum class RUNTIME_API RenderPassLoadOperation : Byte
	{
		Ignore,
		Load,
		Clear
	};
}
