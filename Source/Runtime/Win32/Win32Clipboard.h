#pragma once
#include <Runtime/Containers/String.h>

namespace Portakal
{
    class RUNTIME_API Win32Clipboard
    {
    public:
        static void SetClipboardText(const String& text);
        static String GetClipboardText();

    public:
        Win32Clipboard() = delete;
        ~Win32Clipboard() = delete;
    };
}
