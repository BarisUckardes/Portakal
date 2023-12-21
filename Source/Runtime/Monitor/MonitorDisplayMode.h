#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
	struct RUNTIME_API MonitorDisplayMode
	{
		uint16 Width;
		uint16 Height;
		uint16 RefreshRate;
		byte BitsPerPixel;
	};
}
