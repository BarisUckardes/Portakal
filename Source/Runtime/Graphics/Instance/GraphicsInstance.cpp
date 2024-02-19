#include "GraphicsInstance.h"

#ifdef PORTAKAL_PLATFORM_WINDOWS
#include <Runtime/Vulkan/Instance/VulkanInstance.h>
#endif

namespace Portakal
{
    SharedHeap<GraphicsInstance> GraphicsInstance::Create(const GraphicsInstanceDesc& desc)
    {
        //Create
        SharedHeap<GraphicsInstance> pInstance;
        switch (desc.Backend)
        {
            case Portakal::GraphicsBackend::Vulkan:
            {
                pInstance = (GraphicsInstance*)new VulkanInstance(desc);
                break;
            }
            case Portakal::GraphicsBackend::DirectX12:
            {
                break;
            }
            case Portakal::GraphicsBackend::GNMX:
                break;
            case Portakal::GraphicsBackend::NVM:
                break;
            default:
                break;
        }

        return pInstance;
    }
    void GraphicsInstance::SetAdapters(const Array<SharedHeap<GraphicsAdapter>>& adapters)
    {
        mAdapters = adapters;
    }
}
