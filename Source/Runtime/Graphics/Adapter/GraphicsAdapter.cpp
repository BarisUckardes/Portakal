#include "GraphicsAdapter.h"

namespace Portakal
{
    SharedHeap<GraphicsDevice> GraphicsAdapter::CreateDevice()
    {
        //Create device
        SharedHeap<GraphicsDevice> pDevice = CreateDeviceCore();

        //TODO: Try register to api
        
        //Register
        mDevices.Add(pDevice);

        return pDevice;
    }
}
