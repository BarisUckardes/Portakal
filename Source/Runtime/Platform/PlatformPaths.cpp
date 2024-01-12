#include "PlatformPaths.h"

#ifdef PORTAKAL_PLATFORM_WINDOWS
#include <Runtime/Win32/Win32Paths.h>
typedef Portakal::Win32Paths PlatformAbstraction;
#endif

namespace Portakal
{
	String PlatformPaths::GetProgramsPath()
	{
		return PlatformAbstraction::GetProgramsPath();
	}
	String PlatformPaths::GetPersistentDataPath()
	{
		return PlatformAbstraction::GetPersistentDataPath();
	}
	void PlatformPaths::_SetExecutablePath(const String& path)
	{
		sExecutablePath = path;
	}
}
