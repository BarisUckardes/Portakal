#pragma once
#include <Runtime/Core/Core.h>
#include <Runtime/Graphics/Resource/GraphicsResourceType.h>

namespace Portakal
{
    struct RUNTIME_API ResourceTablePoolEntry
    {
        GraphicsResourceType Type;
        UInt64 Count;
    };

}
