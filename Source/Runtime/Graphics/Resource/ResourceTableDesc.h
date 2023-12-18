#pragma once
#include <Runtime/Graphics/Resource/ResourceTablePool.h>
#include <Runtime/Graphics/Resource/ResourceTableLayout.h>

namespace Portakal
{
    struct RUNTIME_API ResourceTableDesc
    {
        const ResourceTablePool* pOwnerPool;
        const ResourceTableLayout* pTargetLayout;
    };
}
