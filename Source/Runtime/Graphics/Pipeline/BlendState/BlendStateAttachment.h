#pragma once
#include <Runtime/Graphics/Pipeline/BlendState/BlendFactor.h>
#include <Runtime/Graphics/Pipeline/BlendState/BlendOperation.h>
#include <Runtime/Graphics/Pipeline/BlendState/BlendColorWriteMask.h>

namespace Portakal
{
    struct RUNTIME_API BlendStateAttachment
    {
        bool Enabled;
        BlendFactor SourceColorFactor;
        BlendFactor DestinationColorFactor;
        BlendOperation ColorOperation;
        BlendFactor SourceAlphaFactor;
        BlendFactor DestinationAlphaFactor;
        BlendOperation AlphaOperation;
        BlendColorWriteMask WriteMask;
    };
}