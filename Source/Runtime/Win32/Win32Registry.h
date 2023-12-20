#pragma once
#include <Runtime/Containers/String.h>

namespace Portakal
{
    class RUNTIME_API Win32Registry
    {
    public:
        static void CreateKey(const String& position);
        static void SetValue(const String& position, const String& valueName, const String& value);
    public:
        Win32Registry() = delete;
        ~Win32Registry() = delete;
    };
}
