#pragma once
#include <Runtime/Core/Core.h>
#include "GUIDirection.reflected.h"

namespace Portakal
{
	PENUM();
	enum class EDITOR_API GUIDirection : Int64
	{
		None = -1,
		Left = 0,
		Right = 1,
		Up = 2,
		Down
	};
}


