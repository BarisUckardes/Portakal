#pragma once
#include <Runtime/Containers/Array.h>
#include <Runtime/Memory/SharedHeap.h>

namespace Portakal
{
    class InputDevice;
    class RUNTIME_API Win32Input
    {
    public:
        static bool Initialize();
        static void GetConnectedDevices(Array<SharedHeap<InputDevice>>& devices);
    public:
        Win32Input() = delete;
        ~Win32Input() = delete;
    };
}

