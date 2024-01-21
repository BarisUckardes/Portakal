#pragma once
#include <Runtime/Core/Core.h>
#include "SamplerAddressMode.reflected.h"

namespace Portakal
{
    PENUM();
    enum class RUNTIME_API SamplerAddressMode : Int64
    {
        Repeat,
        MirroredRepeat,
        ClampToEdge,
        ClampToBorder,
        MirrorClampToEdge
    };

    GENERATE_FLAGS(SamplerAddressMode, Byte);
}

