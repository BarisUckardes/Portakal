#pragma once
#include <Runtime/Core/Core.h>
#include <Runtime/Graphics/Descriptor/DescriptorResourceType.h>
#include <Runtime/Graphics/Shader/ShaderStage.h>

namespace Portakal
{
    struct RUNTIME_API DescriptorSetLayoutEntry
    {
        DescriptorResourceType Type;
        ShaderStage Stages;
        UInt32 Binding;
    };
}
