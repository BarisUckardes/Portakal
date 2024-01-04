#pragma once
#include <Runtime/Graphics/Common/CompareOperation.h>
#include <Runtime/Graphics/Pipeline/DepthStencilState/StencilFaceDesc.h>

namespace Portakal
{
    struct RUNTIME_API DepthStencilStateDesc
    {
        Bool8 bDepthTestEnabled;
        Bool8 bDepthWriteEnabled;
        Bool8 bStencilTestEnabled;
        CompareOperation DepthTestOperation;
        StencilFaceDesc StencilFrontFace;
        StencilFaceDesc StencilBackFace;
    };
}
