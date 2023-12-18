#pragma once
#include <Runtime/Containers/Array.h>
#include <Runtime/Graphics/Resource/ResourceTablePoolEntry.h>

namespace Portakal
{
    struct RUNTIME_API ResourceTablePoolDesc
    {
        Array<ResourceTablePoolEntry> Entries;
        uint32 MaxTables;
    };
}
