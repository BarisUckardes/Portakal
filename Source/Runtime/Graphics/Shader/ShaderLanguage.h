#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
    enum class RUNTIME_API ShaderLanguage : Byte
    {
        Unknown,
        GLSL,
        HLSL,
        MSL
    };
}
