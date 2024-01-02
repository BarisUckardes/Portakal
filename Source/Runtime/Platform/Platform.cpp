#include "Platform.h"
#include <Runtime/Platform/PlatformInput.h>
#include <Runtime/Platform/PlatformPaths.h>

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
	bool Platform::InitializePlatformDependencies(const String& executablePath)
	{
		//First set executable path
		PlatformPaths::_SetExecutablePath(executablePath);

		//Initialize
		bool bState = PlatformInput::Initialize();

		if (bState)
			DEV_LOG("Platform", "Dependencies initialized!");

		return bState;
	}
}
