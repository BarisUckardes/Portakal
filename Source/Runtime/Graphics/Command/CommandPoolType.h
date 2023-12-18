#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
	enum class RUNTIME_API CommandPoolType : byte
	{
		Graphics,
		Compute,
		Transfer,
	};
}
