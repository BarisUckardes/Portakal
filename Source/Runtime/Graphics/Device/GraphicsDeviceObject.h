#pragma once
#include <Runtime/Object/Object.h>
#include <Runtime/Memory/SharedHeap.h>
#include <Runtime/Graphics/Device/GraphicsDeviceObjectType.h>

namespace Portakal
{
	class GraphicsDevice;
	class RUNTIME_API GraphicsDeviceObject : public Object
	{
		friend class GraphicsDevice;
	public:
		GraphicsDeviceObject(GraphicsDevice* pDevice) : mOwnerDevice(pDevice)
		{

		}
		~GraphicsDeviceObject() = default;


		FORCEINLINE GraphicsDevice* GetOwnerDevice() const noexcept
		{
			return mOwnerDevice;
		}
		FORCEINLINE virtual GraphicsDeviceObjectType GetObjectType() const noexcept = 0;
		virtual void OnShutdown() = 0;
	private:
		void _SetOwnerDevice(GraphicsDevice* pOwnerDevice)
		{
			mOwnerDevice = pOwnerDevice;
		}
	private:
		GraphicsDevice* mOwnerDevice;
	};
}
