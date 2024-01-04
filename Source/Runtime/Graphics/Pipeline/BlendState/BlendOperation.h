#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
    enum class RUNTIME_API BlendOperation : Byte
    {
        Add,
        Subtract,
        Max,
        Min,
        ReverseSubtract
    };
}
