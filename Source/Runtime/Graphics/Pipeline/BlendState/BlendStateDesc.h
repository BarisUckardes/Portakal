#pragma once
#include <Runtime/Graphics/Common/LogicOperation.h>
#include <Runtime/Graphics/Pipeline/BlendState/BlendStateAttachment.h>
#include <Runtime/Containers/Array.h>

namespace Portakal
{
    struct RUNTIME_API BlendStateDesc
    {
        Bool8 bLogicOperationEnabled;
        LogicOperation LogicOperation;
        Array<BlendStateAttachment> Attachments;
    };
}
