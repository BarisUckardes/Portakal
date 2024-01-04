#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
	enum class RUNTIME_API PresentMode : Byte
	{
		Immediate,
		VsyncImmediate,
		VsyncQueued
	};
}