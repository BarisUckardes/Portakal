#pragma once
#include <Runtime/Core/Core.h>
#include <Runtime/Graphics/Pipeline/DepthStencilState/StencilOperation.h>
#include <Runtime/Graphics/Common/CompareOperation.h>

namespace Portakal
{
    struct RUNTIME_API StencilFaceDesc
    {
        StencilOperation FailOperation;
        StencilOperation PassOperation;
        StencilOperation DepthFailOperation;
        CompareOperation CompareOperation;
        Uint32 CompareMask;
        Uint32 WriteMask;
        Uint32 Reference;
    };
}
