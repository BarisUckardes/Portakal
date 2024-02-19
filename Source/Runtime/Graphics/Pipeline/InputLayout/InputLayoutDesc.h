#pragma once
#include <Runtime/Graphics/Pipeline/InputLayout/MeshTopology.h>
#include <Runtime/Graphics/Pipeline/InputLayout/InputBinding.h>
#include <Runtime/Containers/Array.h>

namespace Portakal
{
    struct RUNTIME_API InputLayoutDesc
    {
        MeshTopology Topology;
        Array<InputBinding> Bindings;
    };
}
