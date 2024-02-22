#pragma once
#include <Runtime/Graphics/Descriptor/DescriptorSetPool.h>
#include <Runtime/Graphics/Descriptor/DescriptorSetLayout.h>

namespace Portakal
{
    struct RUNTIME_API DescriptorSetDesc
    {
        const DescriptorSetPool* pOwnerPool;
        const DescriptorSetLayout* pTargetLayout;
    };
}
