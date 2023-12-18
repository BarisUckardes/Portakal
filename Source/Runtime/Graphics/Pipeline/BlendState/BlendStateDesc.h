#pragma once
#include <Runtime/Containers/Array.h>
#include <Runtime/Graphics/Common/LogicOperation.h>
#include <Runtime/Graphics/Pipeline/BlendState/BlendStateAttachment.h>

namespace Portakal
{
    struct RUNTIME_API BlendStateDesc
    {
        bool bLogicOperationEnabled = false;
        LogicOperation LogicOperation = LogicOperation::And;
        Array<BlendStateAttachment> Attachments;
    };
}
