#include "PlatformClipboard.h"

#ifdef PORTAKAL_PLATFORM_WINDOWS
#include <Runtime/Win32/Win32Clipboard.h>
typedef Portakal::Win32Clipboard PlatformAbstraction;
#endif

namespace Portakal
{
	void PlatformClipboard::SetClipboardText(const String& text)
	{
		PlatformAbstraction::SetClipboardText(text);
	}
	String PlatformClipboard::GetClipboardText()
	{
		return PlatformAbstraction::GetClipboardText();
	}
}
