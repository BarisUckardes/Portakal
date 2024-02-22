#pragma once
#include <Runtime/Containers/Array.h>
#include <Runtime/Graphics/Descriptor/DescriptorSetUpdateEntry.h>

namespace Portakal
{
    struct RUNTIME_API DescriptorSetUpdateDesc
    {
        Array<DescriptorSetUpdateEntry> Entries;
    };
}
