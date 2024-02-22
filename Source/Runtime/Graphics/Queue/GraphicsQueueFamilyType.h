#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
	enum class RUNTIME_API GraphicsQueueFamilyType : Byte
	{
		Graphics,
		Compute,
		Transfer,
		Present
	};
}
