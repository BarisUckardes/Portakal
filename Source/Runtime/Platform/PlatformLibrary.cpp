#include "PlatformLibrary.h"

#ifdef PORTAKAL_PLATFORM_WINDOWS
#include <Runtime/Win32/Win32Library.h>
typedef Portakal::Win32Library PlatformAbstraction;
#endif

namespace Portakal
{

	SharedHeap<PlatformLibrary> PlatformLibrary::Load(const String& path)
	{
		return PlatformAbstraction::Load(path);
	}
	SharedHeap<PlatformLibrary> PlatformLibrary::GetCurrent()
	{
		static SharedHeap<PlatformLibrary> sCurrent = nullptr;
		if (sCurrent.IsShutdown())
			sCurrent = PlatformAbstraction::LoadCurrent();

		return sCurrent;
	}
}
