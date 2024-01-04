#pragma once
#include <Runtime/Graphics/Pipeline/RasterizerState/PolygonMode.h>
#include <Runtime/Graphics/Pipeline/RasterizerState/FaceCullMode.h>

namespace Portakal
{
    struct RUNTIME_API RasterizerStateDesc
    {
        Bool8 DepthBiasEnabled;
        float DepthBiasClamp;
        float DepthBiasFactor;
        float DepthBiasSlope;
        PolygonMode FillMode;
        FaceCullMode CullFlags;
        Bool8 IsFrontCounterClockwise;
    };
}
