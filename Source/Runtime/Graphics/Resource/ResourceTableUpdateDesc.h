#pragma once
#include <Runtime/Containers/Array.h>
#include <Runtime/Graphics/Resource/ResourceTableUpdateEntry.h>

namespace Portakal
{
    struct RUNTIME_API ResourceTableUpdateDesc
    {
        Array<ResourceTableUpdateEntry> Entries;
    };
}
