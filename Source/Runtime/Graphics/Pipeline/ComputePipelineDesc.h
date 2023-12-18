#pragma once
#include <Runtime/Containers/Array.h>
#include <Runtime/Graphics/Shader/Shader.h>

namespace Portakal
    class ResourceLayout;

    struct PORTAKAL_API ComputePipelineDesc
    {
        Array<ResourceLayout*> ResourceLayouts;
        SharedHeap<Shader> ComputeShader;
    };
}
