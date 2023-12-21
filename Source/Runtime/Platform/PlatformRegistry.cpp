#include "PlatformRegistry.h"

#ifdef PORTAKAL_PLATFORM_WINDOWS
#include <Runtime/Win32/Win32Registry.h>
typedef Portakal::Win32Registry PlatformAbstraction;
#endif

namespace Portakal
{
	void PlatformRegistry::CreateKey(const String& position)
	{
		PlatformAbstraction::CreateKey(position);
	}
	void PlatformRegistry::SetValue(const String& position, const String& valueName, const String& value)
	{
		PlatformAbstraction::SetValue(position, valueName, value);
	}
}
