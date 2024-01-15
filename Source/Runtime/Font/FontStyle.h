#pragma once

#include <Runtime/Core/Core.h>

namespace Portakal
{
	enum class RUNTIME_API FontStyle : Byte
	{
		Normal, // The default style
		Italic, // Slanted
		Underline, // The line below the text
		Strikeout // The line through the middle of the text
	};
}
