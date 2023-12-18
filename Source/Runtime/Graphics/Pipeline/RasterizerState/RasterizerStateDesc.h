#pragma once
#include <Runtime/Graphics/Common/PolygonMode.h>
#include <Runtime/Graphics/Common/FaceCullMode.h>

namespace Portakal
{
    struct RUNTIME_API RasterizerStateDesc
    {
        bool DepthBiasEnabled;
        float DepthBiasClamp;
        float DepthBiasFactor;
        float DepthBiasSlope;
        PolygonMode FillMode;
        FaceCullMode CullFlags;
        bool IsFrontCounterClockwise;
    };
}
