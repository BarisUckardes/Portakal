#include "PlatformIcon.h"

#ifdef PORTAKAL_PLATFORM_WINDOWS
#include <Runtime/Win32/Win32Icon.h>
typedef Portakal::Win32Icon PlatformAbstraction;
#endif

namespace Portakal
{
	bool PlatformIcon::LoadIconFromPath(const String& path, const PlatformWindow* pTargetWindow)
	{
		return PlatformAbstraction::LoadIconFromPath(path, pTargetWindow);
	}
}

