#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
	enum class RUNTIME_API PresentMode : byte
	{
		Immediate,
		VsyncImmediate,
		VsyncQueued
	};
}