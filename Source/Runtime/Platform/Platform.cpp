#include "Platform.h"

#ifdef PORTAKAL_PLATFORM_WINDOWS

#endif
namespace Portakal
{
	PlatformType Platform::GetCurrentPlatform()
	{
#ifdef PORTAKAL_PLATFORM_WINDOWS
		return PlatformType::Windows;
#elif PORTAKAL_PLATFORM_LINUX
		return PlatformType::Linux;
#elif PORTAKAL_PLATFORM_MACOS
		return PlatformType::Mac;
#else
#error ("Invalid platform detected!")
#endif
	}
	bool Platform::InitializePlatformDependencies()
	{
		return true;
	}
}
