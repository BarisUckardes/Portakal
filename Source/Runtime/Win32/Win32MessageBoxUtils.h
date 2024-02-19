#pragma once
#include <Runtime/Message/MessageFlags.h>

namespace Portakal
{
    class RUNTIME_API Win32MessageBoxUtils
    {
    public:
        static UInt32 GetFlags(const MessageFlags flags);
    public:
        Win32MessageBoxUtils() = delete;
        ~Win32MessageBoxUtils() = delete;
    };
}

