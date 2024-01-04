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
        UInt32 Count;
        UInt32 ArrayElement;
        UInt64 BufferOffsetInBytes;
        UInt32 Binding;
    };
}
