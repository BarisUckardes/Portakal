#pragma once
#include <Runtime/Containers/Array.h>
#include <Runtime/Graphics/Descriptor/DescriptorSetLayoutEntry.h>

namespace Portakal
{
    struct RUNTIME_API DescriptorSetLayoutDesc
    {
        Array<DescriptorSetLayoutEntry> Entries;
    };
}
