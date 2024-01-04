#include "Win32MessageBoxUtils.h"
#include <Windows.h>

namespace Portakal
{
    unsigned int Win32MessageBoxUtils::GetFlags(const MessageFlags flags)
    {
        UInt32 result = (const UInt32)MessageFlags::None;

        if (flags & MessageFlags::Help)
            result |= MB_HELP;
        if (flags & MessageFlags::IconAtRisk)
            result |= MB_ICONASTERISK;
        if (flags & MessageFlags::IconExclamation)
            result |= MB_ICONEXCLAMATION;
        if (flags & MessageFlags::IconInformation)
            result |= MB_ICONINFORMATION;
        if (flags & MessageFlags::IconQuestion)
            result |= MB_ICONQUESTION;
        if (flags & MessageFlags::IconStop)
            result |= MB_ICONSTOP;
        if (flags & MessageFlags::IconWarning)
            result |= MB_ICONWARNING;
        if (flags & MessageFlags::OK)
            result |= MB_OK;

        return result;
    }
}