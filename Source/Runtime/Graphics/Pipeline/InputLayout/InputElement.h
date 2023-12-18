#pragma once
#include <Runtime/Graphics/Texture/TextureFormat.h>
#include <Runtime/Graphics/Pipeline/InputLayout/InputElementSemantic.h>

namespace Portakal
{
    struct RUNTIME_API InputElement
    {
        TextureFormat Format;
        InputElementSemantic Semantic;
    };
}
