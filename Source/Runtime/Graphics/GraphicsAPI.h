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
		static Array<SharedHeap<GraphicsDevice>> GetDevices();
	private:
		static void _RegisterDevice(const SharedHeap<GraphicsDevice>& pDevice);
		static void _RemoveDevice(GraphicsDevice* pDevice);
	public:
		GraphicsAPI() = default;
		~GraphicsAPI() = default;
	private:
		HashMap<GraphicsDevice*, SharedHeap<GraphicsDevice>> mMap;
		Array<SharedHeap<GraphicsDevice>> mDevices;
	};
}
