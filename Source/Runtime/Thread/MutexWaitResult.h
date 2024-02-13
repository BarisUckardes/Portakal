#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
	/// <summary>
	/// The states that a Mutex can have
	/// </summary>
	enum class RUNTIME_API MutexWaitResult : Byte
	{
		Signalled,
		Timeout,
		Invalid
	};
}
