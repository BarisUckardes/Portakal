#include "MaterialResource.h"
#include <Runtime/Graphics/GraphicsAPI.h>

namespace Portakal
{
	MaterialResource::MaterialResource()
	{
		mDevice = GraphicsAPI::GetDefaultDevice();
	}

	void MaterialResource::SetMemoryProfile(const SharedHeap<GraphicsMemoryHeap>& pHeapDevice, const SharedHeap<GraphicsMemoryHeap>& pHeapHost, const SharedHeap<ResourceTablePool>& pPool)
	{
		mHeapDevice = pHeapDevice;
		mHeapHost = pHeapHost;
		mTablePool = pPool;
	}
	void MaterialResource::SetShaderProfile(const Array<SharedHeap<ShaderResource>>& shaders)
	{
		mShaders = shaders;

	}
}
