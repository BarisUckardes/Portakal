#pragma once
#include <Runtime/Core/Core.h>
#include "SamplerFiltering.reflected.h"

namespace Portakal
{
    PENUM();
    enum class RUNTIME_API SamplerFiltering : Int64
    {
        None,
        Linear,
        Nearest
    };

    GENERATE_FLAGS(SamplerFiltering, Byte);
}

