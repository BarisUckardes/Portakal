#pragma once
#include <Runtime/Graphics/Device/GraphicsDeviceObject.h>

namespace Portakal
{
	class RUNTIME_API Swapchain : public GraphicsDeviceObject
	{
	public:

		virtual GraphicsDeviceObjectType GetObjectType() const noexcept override final { return GraphicsDeviceObjectType::Swapchain; }
	private:
	};
}
