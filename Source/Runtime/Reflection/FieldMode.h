#pragma once
#include <Runtime/Core/Core.h>
#include "FieldMode.reflected.h"

namespace Portakal
{
	PENUM();
	enum class RUNTIME_API FieldMode : Int64
	{
		Normal,
		Object,
		Array
	};
}

