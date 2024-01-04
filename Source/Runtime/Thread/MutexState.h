#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
	enum class RUNTIME_API MutexState : Byte
	{
		Signalled,
		Timeout,
		Invalid
	};
}
