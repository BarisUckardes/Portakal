#pragma once
#include <Runtime/Core/Core.h>
#include <Runtime/Graphics/Resource/GraphicsResourceType.h>
#include <Runtime/Graphics/Shader/ShaderStage.h>

namespace Portakal
{
    struct RUNTIME_API ResourceLayoutEntry
    {
        GraphicsResourceType Type;
        ShaderStage Stages;
        uint32 Binding;
    };
}
