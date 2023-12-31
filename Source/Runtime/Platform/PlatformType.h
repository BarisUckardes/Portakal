#pragma once
#include <Runtime/Core/Core.h>
#include <Runtime/Reflection/Reflection.h>
#include "PlatformType.reflected.h"

namespace Portakal
{
	PENUM();
	enum class RUNTIME_API PlatformType : int64
	{
		Windows = 112,
		Linux,
		Mac = 155,
		PS5,
		Switch
	};
}



















































































































































