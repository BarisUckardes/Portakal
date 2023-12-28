#include "GraphicsAPI.h"

namespace Portakal
{
	SharedHeap<GraphicsDevice> GraphicsAPI::GetDefaultDevice()
	{
		GraphicsAPI* pAPI = GetUnderlyingAPI();
		if (pAPI == nullptr)
			return nullptr;

		return pAPI->mDevices.IsEmpty() ? nullptr : pAPI->mDevices.GetFirst();
	}
	Array<SharedHeap<GraphicsDevice>> GraphicsAPI::GetDevices()
	{
		GraphicsAPI* pAPI = GetUnderlyingAPI();
		if (pAPI == nullptr)
			return {};

		return pAPI->mDevices;
	}
	void GraphicsAPI::_RegisterDevice(const SharedHeap<GraphicsDevice>& pDevice)
	{
		GraphicsAPI* pAPI = GetUnderlyingAPI();
		if (pAPI == nullptr)
			return;

		pAPI->mDevices.Add(pDevice);
		pAPI->mMap.Insert(pDevice.GetHeap(), pDevice);
	}
	void GraphicsAPI::_RemoveDevice(GraphicsDevice* pDevice)
	{
		GraphicsAPI* pAPI = GetUnderlyingAPI();
		if (pAPI == nullptr)
			return;

		const int index = pAPI->mMap.FindIndex(pDevice);
		if (index == -1)
			return;

		pAPI->mMap.Remove(pDevice);
		pAPI->mDevices.RemoveAt(index);
	}
}
