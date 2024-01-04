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
        UInt32 CompareMask;
        UInt32 WriteMask;
        UInt32 Reference;
    };
}
