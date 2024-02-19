#pragma once
#include <Runtime/Graphics/Device/GraphicsDeviceObject.h>
#include <Runtime/Graphics/Descriptor/DescriptorSetDesc.h>
#include <Runtime/Memory/SharedHeap.h>

namespace Portakal
{
	class RUNTIME_API DescriptorSet : public GraphicsDeviceObject
	{
	public:
		~DescriptorSet();

		FORCEINLINE SharedHeap<DescriptorSetLayout> GetLayout() const noexcept
		{
			return mLayout;
		}
		FORCEINLINE SharedHeap<DescriptorPool> GetPool() const noexcept
		{
			return mPool;
		}

		virtual GraphicsDeviceObjectType GetObjectType() const noexcept override final
		{
			return GraphicsDeviceObjectType::DescriptorSet;
		}
	protected:
		DescriptorSet(const DescriptorSetDesc& desc, GraphicsDevice* pDevice);

	private:
		SharedHeap<DescriptorSetLayout> mLayout;
		SharedHeap<DescriptorPool> mPool;
	};
}
