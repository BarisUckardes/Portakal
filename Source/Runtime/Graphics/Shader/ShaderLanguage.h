#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
    enum class RUNTIME_API ShaderLanguage : byte
    {
        Unknown,
        GLSL,
        HLSL,
        MSL
    };
}
