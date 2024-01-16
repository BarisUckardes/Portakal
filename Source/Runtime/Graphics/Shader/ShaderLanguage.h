#pragma once
#include <Runtime/Core/Core.h>
#include "ShaderLanguage.reflected.h"

namespace Portakal
{
    PENUM();
    enum class RUNTIME_API ShaderLanguage : Int64
    {
        Unknown,
        GLSL,
        HLSL,
        MSL
    };
}

