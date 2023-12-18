#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
    enum class RUNTIME_API ShaderStage : unsigned char
    {
        VertexStage = 1,
        FragmentStage = 2,
        ComputeStage = 4,
    };

    GENERATE_FLAGS(ShaderStage, unsigned char)
}
