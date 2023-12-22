#include "GraphicsInstance.h"

#include <Runtime/Vulkan/Instance/VulkanInstance.h>
#include <Runtime/D3D12/Instance/D3DInstance.h>
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
                pInstance = (GraphicsInstance*)new D3DInstance(desc);
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
