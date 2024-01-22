#pragma once
#include <Runtime/Graphics/Device/GraphicsDevice.h>
#include <Runtime/Graphics/Command/CommandList.h>
#include <Runtime/Graphics/Command/CommandPool.h>
#include <Runtime/Resource/Texture/TextureResource.h>
#include <Runtime/Resource/ResourceSubObject.h>

namespace Portakal
{
	class RUNTIME_API MaterialResource : public ResourceSubObject
	{
	public:
		MaterialResource();
		~MaterialResource() = default;

		void SetMemoryProfile(const SharedHeap<ResourceTablePool>& pPool);
	private:
		SharedHeap<GraphicsDevice> mDevice;
		SharedHeap<ResourceTablePool> mTablePool;
	};
}
