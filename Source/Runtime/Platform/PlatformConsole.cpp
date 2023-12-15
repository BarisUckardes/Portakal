#include "PlatformConsole.h"

#ifdef PORTAKAL_PLATFORM_WINDOWS
#include <Runtime/Win32/Win32Console.h>
typedef Portakal::Win32Console PlatformAbstraction;
#endif

namespace Portakal
{
    void PlatformConsole::Write(const String& text)
    {
        PlatformAbstraction::Write(text);
    }

    void PlatformConsole::WriteLine(const String& text)
    {
        PlatformAbstraction::WriteLine(text);
    }

    void PlatformConsole::SetTextColor(const ConsoleColor color)
    {
        PlatformAbstraction::SetTextColor(color);
    }

    void PlatformConsole::SetBackgroundColor(const ConsoleColor color)
    {
        PlatformAbstraction::SetBackgroundColor(color);
    }

    void PlatformConsole::SetDefaultTextColor()
    {
        PlatformAbstraction::SetTextColor(DefaultTextColor);
    }

    void PlatformConsole::SetDefaultBackgroundColor()
    {
        PlatformAbstraction::SetBackgroundColor(DefaultBackgroundColor);
    }

    void PlatformConsole::Clear()
    {
        PlatformAbstraction::Clear();
    }
}
