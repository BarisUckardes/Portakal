#include "GraphicsInstance.h"

#ifdef PORTAKAL_PLATFORM_WINDOWS
#include <Runtime/Vulkan/Instance/VulkanInstance.h>
#include <Runtime/D3D12/Instance/D3DInstance.h>
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
#ifdef PORTAKAL_PLATFORM_WINDOWS
                pInstance = (GraphicsInstance*)new D3DInstance(desc);
#endif
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
