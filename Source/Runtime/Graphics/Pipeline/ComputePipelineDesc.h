#pragma once
#include <Runtime/Containers/Array.h>
#include <Runtime/Graphics/Shader/Shader.h>

namespace Portakal
{
    class ResourceLayout;

    struct RUNTIME_API ComputePipelineDesc
    {
        Array<ResourceLayout*> ResourceLayouts;
        SharedHeap<Shader> ComputeShader;
    };
}
