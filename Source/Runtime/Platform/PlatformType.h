#pragma once
#include <Runtime/Core/Core.h>
#include <Runtime/Reflection/Reflection.h>

namespace Portakal
{
	PENUM();
	enum class RUNTIME_API PlatformType : byte
	{
		Windows = 112,
		Linux,
		Mac = 155,
		PS5,
		Switch
	};
}
