#pragma once
#include <Runtime/Graphics/Device/GraphicsDeviceObject.h>

namespace Portakal
{
	class RUNTIME_API Semaphore : public GraphicsDeviceObject
	{
	public:
		Semaphore() = default;
		~Semaphore() = default;

		virtual GraphicsDeviceObjectType GetObjectType() const noexcept override final
		{
			return GraphicsDeviceObjectType::Semaphore;
		}
	};
}
