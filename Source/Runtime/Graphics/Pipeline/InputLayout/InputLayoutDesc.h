#pragma once
#include <Runtime/Graphics/Pipeline/InputLayout/MeshTopology.h>
#include <Runtime/Graphics/Pipeline/InputLayout/InputBinding.h>

namespace Portakal
{
    struct RUNTIME_API InputLayoutDesc
    {
        PrimitiveTopology Topology;
        Array <InputBinding> Bindings;
    };
}
