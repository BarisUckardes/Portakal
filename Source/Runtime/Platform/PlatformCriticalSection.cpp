#include "PlatformCriticalSection.h"

#ifdef PORTAKAL_PLATFORM_WINDOWS
#include <Runtime/Win32/Win32CriticalSection.h>
typedef Portakal::Win32CriticalSection PlatformAbstraction;
#endif

namespace Portakal
{
	SharedHeap<PlatformCriticalSection> PlatformCriticalSection::Create()
	{
		return new PlatformAbstraction();
	}
}
