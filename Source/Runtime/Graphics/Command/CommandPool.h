#pragma once
#include <Runtime/Graphics/Device/GraphicsDeviceObject.h>
#include <Runtime/Graphics/Command/CommandPoolDesc.h>

namespace Portakal
{
	class RUNTIME_API CommandPool : public GraphicsDeviceObject
	{
	public:
		CommandPool(const CommandPoolDesc& desc,GraphicsDevice* pDevice);
		~CommandPool() = default;

		FORCEINLINE CommandPoolType GetCommandType() const noexcept
		{
			return mType;
		}
		virtual GraphicsDeviceObjectType GetObjectType() const noexcept override final
		{
			return GraphicsDeviceObjectType::CommandPool;
		}
	private:
		const CommandPoolType mType;
	};
}
