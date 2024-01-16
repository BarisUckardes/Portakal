#pragma once
#include <Runtime/Containers/String.h>
#include <Runtime/Graphics/Shader/ShaderStage.h>
#include <Runtime/Graphics/Shader/ShaderLanguage.h>
#include <Runtime/Memory/MemoryView.h>

namespace Portakal
{
    struct RUNTIME_API ShaderDesc
    {
        ShaderStage Stage;
        ShaderLanguage Language;
        String EntryPoint;
        MemoryView ByteCode;
    };
}
