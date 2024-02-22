#include "GraphicsAdapter.h"
#include <Runtime/Graphics/GraphicsAPI.h>

namespace Portakal
{
    SharedHeap<GraphicsDevice> GraphicsAdapter::CreateDevice(GraphicsDeviceDesc* pDesc)
    {
        DEV_ASSERT(GraphicsAPI::GetDefaultDevice().IsShutdown(), "GraphicsAdapter", "Cannot create device while there is already an instance of it");

        //Create device
        pDesc->pAdapter = this;
        SharedHeap<GraphicsDevice> pDevice = CreateDeviceCore(pDesc);

        //Try register to api
        GraphicsAPI::_SetDevice(pDevice);

        //Register
        mDevices.Add(pDevice);

        return pDevice;
    }
}
