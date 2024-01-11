#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
	enum class RUNTIME_API ThreadJobState : Byte
	{
		Idle,
		Working,
		Finished
	};
}
