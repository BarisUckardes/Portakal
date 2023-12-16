#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
	enum class RUNTIME_API GraphicsQueueType : byte
	{
		Graphics,
		Compute,
		Transfer,
		Present
	};
}
