#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
	enum class RUNTIME_API ApplicationModuleState : byte
	{
		OK,
		NeedsInitialization,
		NeedsFinalization
	};
}
