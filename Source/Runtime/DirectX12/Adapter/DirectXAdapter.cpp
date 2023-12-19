#include "DirectXAdapter.h"

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
