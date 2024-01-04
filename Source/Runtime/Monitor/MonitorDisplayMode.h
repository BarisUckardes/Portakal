#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
	struct RUNTIME_API MonitorDisplayMode
	{
		UInt16 Width;
		UInt16 Height;
		UInt16 RefreshRate;
		Byte BitsPerPixel;
	};
}
