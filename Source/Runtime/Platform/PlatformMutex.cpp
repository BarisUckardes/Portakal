#include "PlatformMutex.h"

#ifdef PORTAKAL_PLATFORM_WINDOWS
#include <Runtime/Win32/Win32Mutex.h>
typedef Portakal::Win32Mutex PlatformAbstraction;
#endif

namespace Portakal
{
	SharedHeap<PlatformMutex> PlatformMutex::Create()
	{
		return PlatformAbstraction::Create();
	}
}
