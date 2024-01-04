#include "PlatformHardware.h"

#ifdef PORTAKAL_PLATFORM_WINDOWS
#include <Runtime/Win32/Win32Hardware.h>
typedef Portakal::Win32Hardware PlatformAbstraction;
#endif

namespace Portakal
{
	Uint16 PlatformHardware::GetCpuThreadCount()
	{
		return PlatformAbstraction::GetCpuThreadCount();
	}
	Uint16 PlatformHardware::GetPageSize()
	{
		return PlatformAbstraction::GetPageSize();
	}
}
