#pragma once
#include <Runtime/Graphics/Device/GraphicsDeviceObject.h>
#include <Runtime/Graphics/Descriptor/DescriptorPoolDesc.h>

namespace Portakal
{
	class RUNTIME_API DescriptorPool : public GraphicsDeviceObject
	{
	public:
		~DescriptorPool();

		FORCEINLINE DescriptorMemoryType GetMemoryType() const noexcept
		{
			return mType;
		}
		FORCEINLINE UInt64 GetSetCount() const noexcept
		{
			return mSetCount;
		}
		FORCEINLINE const Array<DescriptorPoolSize>& GetSizes() const noexcept
		{
			return mSizes;
		}
		virtual GraphicsDeviceObjectType GetObjectType() const noexcept override final
		{
			return GraphicsDeviceObjectType::DescriptorPool;
		}
	protected:
		DescriptorPool(const DescriptorPoolDesc& desc,GraphicsDevice* pDevice);
	private:
		const UInt64 mSetCount;
		const DescriptorMemoryType mType;
		const Array<DescriptorPoolSize> mSizes;
	};
}
