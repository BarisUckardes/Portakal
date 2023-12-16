#pragma once
#include <Runtime/Object/Object.h>
#include <Runtime/Graphics/Device/GraphicsDeviceObjectType.h>

namespace Portakal
{
	class GraphicsDevice;
	class RUNTIME_API GraphicsDeviceObject : public Object
	{
	public:
		GraphicsDeviceObject() = default;
		~GraphicsDeviceObject() = default;


		FORCEINLINE SharedHeap<GraphicsDevice> GetOwnerDevice() const noexcept
		{
			return mOwnerDevice;
		}
		FORCEINLINE virtual GraphicsDeviceObjectType GetObjectType() const noexcept = 0;
	private:
		void _SetOwnerDevice(const SharedHeap<GraphicsDevice>& pOwnerDevice)
		{
			mOwnerDevice = pOwnerDevice;
		}
	private:
		SharedHeap<GraphicsDevice> mOwnerDevice;
	};
}
