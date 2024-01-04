#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
	enum class RUNTIME_API ApplicationModuleState : Byte
	{
		OK,
		NeedsInitialization,
		NeedsFinalization
	};
}
