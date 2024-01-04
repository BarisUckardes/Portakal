#pragma once
#include <Runtime/Core/Core.h>
#include <Runtime/Memory/SharedHeap.h>
#include <Runtime/Graphics/Device/GraphicsDeviceObject.h>
#include <Runtime/Graphics/Resource/GraphicsResourceType.h>

namespace Portakal
{
    struct RUNTIME_API ResourceTableUpdateEntry
    {
        SharedHeap<GraphicsDeviceObject> pResource;
        GraphicsResourceType Type;
        Uint32 Count;
        Uint32 ArrayElement;
        Uint64 BufferOffsetInBytes;
        Uint32 Binding;
    };
}
