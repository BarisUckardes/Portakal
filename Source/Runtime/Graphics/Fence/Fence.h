#pragma once
#include <Runtime/Graphics/Device/GraphicsDeviceObject.h>

namespace Portakal
{
	class RUNTIME_API Fence : public GraphicsDeviceObject
	{
	public:
		Fence(GraphicsDevice* pDevice) : GraphicsDeviceObject(pDevice)
		{

		}
		~Fence() = default;

		virtual GraphicsDeviceObjectType GetObjectType() const noexcept override final
		{
			return GraphicsDeviceObjectType::Fence;
		}
	private:
	};
}
