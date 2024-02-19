#pragma once
#include <Runtime/Containers/Array.h>
#include <Runtime/Memory/SharedHeap.h>
#include <Runtime/Graphics/Descriptor/DescriptorSetLayout.h>

namespace Portakal
{
    struct RUNTIME_API ResourceLayoutDesc
    {
        Array<SharedHeap<DescriptorSetLayout>> ResourceLayouts;
    };
}
