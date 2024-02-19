#pragma once
#include <Runtime/Graphics/Shader/Shader.h>
#include <Runtime/Graphics/Descriptor/DescriptorSetLayout.h>
#include <Runtime/Containers/Array.h>
#include <Runtime/Memory/SharedHeap.h>

namespace Portakal
{
    struct RUNTIME_API ComputePipelineDesc
    {
        Array<SharedHeap<DescriptorSetLayout>> DescriptorSetLayouts;
        SharedHeap<Shader> pComputeShader;
    };
}
