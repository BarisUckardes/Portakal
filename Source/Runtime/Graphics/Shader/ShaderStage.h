#pragma once
#include <Runtime/Core/Core.h>
#include "ShaderStage.reflected.h"

namespace Portakal
{
    PENUM();
    enum class RUNTIME_API ShaderStage : Int64
    {
        VertexStage = 1,
        FragmentStage = 2,
        ComputeStage = 4,
    };

    GENERATE_FLAGS(ShaderStage, Byte)
}

