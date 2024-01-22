#pragma once
#include <Runtime/Graphics/Device/GraphicsDevice.h>
#include <Runtime/Object/API.h>
#include <Runtime/Containers/HashMap.h>

namespace Portakal
{
	class RUNTIME_API GraphicsAPI : public API<GraphicsAPI>
	{
		friend class GraphicsDevice;
		friend class GraphicsAdapter;
	public:
		static SharedHeap<GraphicsDevice> GetDefaultDevice();
	private:
		static void _SetDevice(const SharedHeap<GraphicsDevice>& pDevice);
		static void _RemoveDevice();
	public:
		GraphicsAPI() = default;
		~GraphicsAPI() = default;
	private:
		SharedHeap<GraphicsDevice> mDevice;
	};
}
