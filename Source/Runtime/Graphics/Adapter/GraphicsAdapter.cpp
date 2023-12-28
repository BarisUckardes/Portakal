#include "GraphicsAdapter.h"
#include <Runtime/Graphics/GraphicsAPI.h>

namespace Portakal
{
    SharedHeap<GraphicsDevice> GraphicsAdapter::CreateDevice()
    {
        //Create device
        SharedHeap<GraphicsDevice> pDevice = CreateDeviceCore();

        //Try register to api
        GraphicsAPI::_RegisterDevice(pDevice);

        //Register
        mDevices.Add(pDevice);

        return pDevice;
    }
}
