#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
	enum class RUNTIME_API GraphicsQueueType : Byte
	{
		Graphics,
		Compute,
		Transfer,
	};
}
