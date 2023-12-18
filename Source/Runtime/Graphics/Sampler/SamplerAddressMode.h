#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
    enum class RUNTIME_API SamplerAddressMode : byte
    {
        Repeat,
        MirroredRepeat,
        ClampToEdge,
        ClampToBorder,
        MirrorClampToEdge
    };
}
