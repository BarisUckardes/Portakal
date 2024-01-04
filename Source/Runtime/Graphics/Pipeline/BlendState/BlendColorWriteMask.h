#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
    enum class RUNTIME_API BlendColorWriteMask : Byte
    {
        R = 1,
        G = 2,
        B = 4,
        A = 8,
        All = R | G | B | A
    };

    GENERATE_FLAGS(BlendColorWriteMask,Byte)
}
