#pragma once
#include <Runtime/Graphics/Device/GraphicsDeviceObject.h>
#include <Runtime/Graphics/Queue/GraphicsQueueDesc.h>

namespace Portakal
{
	class RUNTIME_API GraphicsQueue : public GraphicsDeviceObject
	{
	public:
		GraphicsQueue(const GraphicsQueueDesc& desc);
		~GraphicsQueue() = default;

		FORCEINLINE GraphicsQueueType GetQueueType() const noexcept
		{
			return mType;
		}
		virtual GraphicsDeviceObjectType GetObjectType() const noexcept override final
		{
			return GraphicsDeviceObjectType::Queue;
		}
	private:
		const GraphicsQueueType mType;
	};
}
