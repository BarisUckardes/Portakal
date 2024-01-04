#include "PlatformHardware.h"

#ifdef PORTAKAL_PLATFORM_WINDOWS
#include <Runtime/Win32/Win32Hardware.h>
typedef Portakal::Win32Hardware PlatformAbstraction;
#endif

namespace Portakal
{
	UInt16 PlatformHardware::GetCpuThreadCount()
	{
		return PlatformAbstraction::GetCpuThreadCount();
	}
	UInt16 PlatformHardware::GetPageSize()
	{
		return PlatformAbstraction::GetPageSize();
	}
}
