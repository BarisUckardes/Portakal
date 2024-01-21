#pragma once
#include <Runtime/Core/Core.h>
#include "SamplerBorderColor.reflected.h"

namespace Portakal
{
    PENUM();
    enum class RUNTIME_API SamplerBorderColor : Int64
    {
        TransparentBlack,
        OpaqueBlack,
        OpaqueWhite
    };

    GENERATE_FLAGS(SamplerBorderColor, Byte);
}

