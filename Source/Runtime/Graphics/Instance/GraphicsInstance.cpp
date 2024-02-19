#include "GraphicsInstance.h"
#include <Runtime/Vulkan/Instance/VulkanInstance.h>

namespace Portakal
{
	GraphicsInstance* GraphicsInstance::Create(const GraphicsInstanceDesc* pDesc)
	{
		GraphicsInstance* pInstance = nullptr;
		switch (pDesc->Backend)
		{
			case Portakal::GraphicsBackend::Vulkan:
			{
				pInstance = new VulkanInstance((VulkanInstanceDesc*)pDesc);
				break;
			}
			default:
				break;
		}

		return pInstance;
	}
	GraphicsInstance::~GraphicsInstance()
	{

	}
	GraphicsInstance::GraphicsInstance(const GraphicsInstanceDesc* pDesc) : mBackend(pDesc->Backend)
	{

	}
	void GraphicsInstance::SetAdapters(const Array<SharedHeap<GraphicsAdapter>>& adapters)
	{
		mAdapters = adapters;
	}
}
