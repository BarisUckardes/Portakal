#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
	struct RUNTIME_API MonitorDisplayMode
	{
		Uint16 Width;
		Uint16 Height;
		Uint16 RefreshRate;
		Byte BitsPerPixel;
	};
}
