#pragma once
#include <Runtime/Core/Core.h>
#include <Runtime/Graphics/Descriptor/DescriptorResourceType.h>

namespace Portakal
{
    struct RUNTIME_API DescriptorSetPoolEntry
    {
        DescriptorResourceType Type;
        UInt64 Count;
    };

}
