#pragma once
#include <Runtime/Containers/String.h>
#include <Runtime/Graphics/Shader/ShaderStage.h>
#include <Runtime/Memory/MemoryView.h>

namespace Portakal
{
    struct RUNTIME_API ShaderDesc
    {
        ShaderStage Stage;
        String EntryPoint;
        MemoryView ByteCode;
    };
}
