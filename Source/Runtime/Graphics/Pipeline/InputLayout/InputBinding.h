#pragma once
#include <Runtime/Graphics/Pipeline/InputLayout/InputBindingStepRate.h>
#include <Runtime/Graphics/Pipeline/InputLayout/InputElement.h>
#include <Runtime/Containers/Array.h>

namespace Portakal
{
    struct RUNTIME_API InputBinding
    {
        InputBindingStepRate StepRate;
        Array<InputElement> Elements;
    };
}
