#pragma once
#include <Runtime/Core/Core.h>
#include "ShaderStage.reflected.h"

namespace Portakal
{
    PENUM();
    enum class RUNTIME_API ShaderStage : Int64
    {
        Vertex = 1,
        Fragment = 2,
        Compute = 4,
        Geometry = 8,
        TesellationControl = 16,
        TesellationEval = 32,
    };

    GENERATE_FLAGS(ShaderStage, Byte)
}

