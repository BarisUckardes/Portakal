#include "PlatformMessage.h"

#ifdef PORTAKAL_PLATFORM_WINDOWS
#include <Runtime/Win32/Win32Message.h>
typedef Portakal::Win32Message PlatformAbstraction;
#endif

namespace Portakal
{
	void PlatformMessage::Show(const String& title, const String& message, const MessageFlags flags)
	{
		PlatformAbstraction::Show(title, message, flags);
	}
}
