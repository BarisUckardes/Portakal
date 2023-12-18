#pragma once
#include <Runtime/Containers/Array.h>

namespace Portakal
{
    class ResourceTableLayout;

    struct RUNTIME_API ResourceLayoutDesc
    {
        Array<ResourceTableLayout*> ResourceLayouts;
    };
}
