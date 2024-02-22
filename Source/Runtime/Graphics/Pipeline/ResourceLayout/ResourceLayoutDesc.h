#pragma once
#include <Runtime/Containers/Array.h>

namespace Portakal
{
    class DescriptorSetLayout;

    struct RUNTIME_API ResourceLayoutDesc
    {
        Array<DescriptorSetLayout*> ResourceLayouts;
    };
}
