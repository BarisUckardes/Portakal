#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
    enum class RUNTIME_API MessageFlags : UInt16
    {
        None = 1 << 0,
        Help = 1 << 1,
        OK = 1 << 2,
        IconExclamation = 1 << 3,
        IconWarning = 1 << 4,
        IconInformation = 1 << 5,
        IconAtRisk = 1 << 6,
        IconQuestion = 1 << 7,
        IconStop = 1 << 8
    };

    GENERATE_FLAGS(MessageFlags, UInt16)
}

