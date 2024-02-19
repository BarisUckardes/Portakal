#pragma once
#include <Runtime/Graphics/Pipeline/RasterizerState/PolygonMode.h>
#include <Runtime/Graphics/Pipeline/RasterizerState/FaceCullMode.h>

namespace Portakal
{
    struct RUNTIME_API RasterizerStateDesc
    {
        Bool8 bDepthBiasEnabled;
        Float32 DepthBiasClamp;
        Float32 DepthBiasFactor;
        Float32 DepthBiasSlope;
        PolygonMode FillMode;
        FaceCullMode CullFlags;
        Bool8 bFrontCounterClockwise;
    };
}
