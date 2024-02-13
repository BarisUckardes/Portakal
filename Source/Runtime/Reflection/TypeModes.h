#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
	/// <summary>
	/// Main type modes for the runtime reflection
	/// </summary>
	enum class RUNTIME_API TypeModes : Byte
	{
		Class,
		Struct,
		Enum
	};
}