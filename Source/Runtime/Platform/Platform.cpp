#include "Platform.h"
#include <Runtime/Platform/PlatformInput.h>
#include <Runtime/Platform/PlatformPaths.h>
#include <Runtime/Platform/PlatformTime.h>

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
	Bool8 Platform::InitializePlatformDependencies(const String& executablePath)
	{
		//First set executable path
		PlatformPaths::_SetExecutablePath(executablePath);

		//Initialize input
		if (!PlatformInput::Initialize())
		{
			DEV_LOG("Platform", "Failed to initialize PlatformInput!");
			return false;
		}

		//Initialize time
		if (!PlatformTime::Initialize())
		{
			DEV_LOG("Platform", "Failed to initialize PlatformTime");
			return false;
		}

		DEV_LOG("Platform", "Dependencies initialized!");

		return true;
	}
}
