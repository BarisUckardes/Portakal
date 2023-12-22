#include "DirectXAdapter.h"
#ifdef PORTAKAL_PLATFORM_WINDOWS
#include <Runtime/DirectX12/Device/DirectXDevice.h>

namespace Portakal
{
	GraphicsDevice* DirectXAdapter::CreateDeviceCore()
	{
		return new DirectXDevice({ this });
	}
	void DirectXAdapter::OnShutdown()
	{
	}
}
#endif