#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
	enum class RUNTIME_API CommandPoolType : Byte
	{
		Graphics,
		Compute,
		Transfer,
	};
}
