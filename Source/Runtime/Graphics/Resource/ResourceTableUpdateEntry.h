#pragma once
#include <Runtime/Core/Core.h>
#include <Runtime/Memory/SharedHeap.h>
#include <Runtime/Graphics/GraphicsDevice/GraphicsDeviceObject.h>
#include <Runtime/Graphics/Resource/GraphicsResourceType.h>

namespace Portakal
{
    struct RUNTIME_API ResourceTableUpdateEntry
    {
        SharedHeap<GraphicsDeviceObject> pResource;
        GraphicsResourceType Type;
        uint32 Count;
        uint32 ArrayElement;
        uint64 BufferOffsetInBytes;
        uint32 Binding;
    };
}
