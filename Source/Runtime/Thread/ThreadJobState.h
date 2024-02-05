#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
	/// <summary>
	/// States that a thread job can have
	/// </summary>
	enum class RUNTIME_API ThreadJobState : Byte
	{
		Idle,
		Working,
		Finished
	};
}
