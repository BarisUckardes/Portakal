#include "PlatformHardware.h"

#ifdef PORTAKAL_PLATFORM_WINDOWS
#include <Runtime/Win32/Win32Hardware.h>
typedef Portakal::Win32Hardware PlatformAbstraction;
#endif

namespace Portakal
{
	uint16 PlatformHardware::GetCpuThreadCount()
	{
		return PlatformAbstraction::GetCpuThreadCount();
	}
	uint16 PlatformHardware::GetPageSize()
	{
		return PlatformAbstraction::GetPageSize();
	}
}
