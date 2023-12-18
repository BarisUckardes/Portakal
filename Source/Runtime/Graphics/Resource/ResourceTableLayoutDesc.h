#pragma once
#include <Runtime/Containers/Array.h>
#include <Runtime/Graphics/Resource/ResourceLayoutEntry.h>

namespace Portakal
{
    struct RUNTIME_API ResourceTableLayoutDesc
    {
        Array<ResourceLayoutEntry> Entries;
    };
}
