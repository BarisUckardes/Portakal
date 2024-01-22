#include "GraphicsAPI.h"

namespace Portakal
{
	SharedHeap<GraphicsDevice> GraphicsAPI::GetDefaultDevice()
	{
		GraphicsAPI* pAPI = GetUnderlyingAPI();
		if (pAPI == nullptr)
			return nullptr;

		return pAPI->mDevice;
	}
	
	void GraphicsAPI::_SetDevice(const SharedHeap<GraphicsDevice>& pDevice)
	{
		GraphicsAPI* pAPI = GetUnderlyingAPI();
		if (pAPI == nullptr)
			return;

		DEV_ASSERT(pAPI->mDevice.IsShutdown(), "GraphicsAPI", "Cannot have more than one graphics device!");

		pAPI->mDevice = pDevice;
	}
	void GraphicsAPI::_RemoveDevice()
	{
		GraphicsAPI* pAPI = GetUnderlyingAPI();
		if (pAPI == nullptr)
			return;

		pAPI->mDevice = nullptr;
	}
}
