#pragma once
#include <Runtime/Containers/Array.h>
#include <Runtime/Graphics/Descriptor/DescriptorSetPoolEntry.h>

namespace Portakal
{
    struct RUNTIME_API DescriptorSetPoolDesc
    {
        Array<DescriptorSetPoolEntry> Entries;
        UInt64 MaxTables;
    };
}
