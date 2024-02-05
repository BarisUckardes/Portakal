#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
	/// <summary>
	/// Represents the available window modes to set
	/// </summary>
	enum class RUNTIME_API WindowMode : Byte
	{
		Windowed,
		WindowedBorderless,
		Fullscreen
	};
}
