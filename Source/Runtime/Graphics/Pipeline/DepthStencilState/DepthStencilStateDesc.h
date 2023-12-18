#pragma once
#include <Runtime/Graphics/Common/CompareOperation.h>
#include <Runtime/Graphics/Pipeline/DepthStencilState/StencilFaceDesc.h>

namespace Portakal
{
    struct RUNTIME_API DepthStencilStateDesc
    {
        bool bDepthTestEnabled;
        bool bDepthWriteEnabled;
        bool bStencilTestEnabled;
        CompareOperation DepthTestOperation;
        StencilFaceDesc StencilFrontFace;
        StencilFaceDesc StencilBackFace;
    };
}
