#pragma once
#include <Runtime/Graphics/Device/GraphicsDeviceObject.h>
#include <Runtime/Graphics/Descriptor/DescriptorSetLayoutDesc.h>
#include <Runtime/Containers/Array.h>

namespace Portakal
{
	class RUNTIME_API DescriptorSetLayout : public GraphicsDeviceObject
	{
	public:
		~DescriptorSetLayout();

		FORCEINLINE const Array<DescriptorSetLayoutEntry>& GetEntries() const noexcept
		{
			return mEntries;
		}

		virtual GraphicsDeviceObjectType GetObjectType() const noexcept override final
		{
			return GraphicsDeviceObjectType::DescriptorLayout;
		}
	protected:
		DescriptorSetLayout(const DescriptorSetLayoutDesc& desc, GraphicsDevice* pDevice);
	private:
		const Array<DescriptorSetLayoutEntry> mEntries;
	};
}
