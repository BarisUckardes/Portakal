#include "GraphicsInstance.h"

#include <Runtime/Vulkan/Instance/VulkanInstance.h>
#include <Runtime/DirectX12/Instance/DirectXInstance.h>
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
                pInstance = (GraphicsInstance*)new DirectXInstance(desc);
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
