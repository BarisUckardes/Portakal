#include "D3DAdapter.h"
#include <Runtime/D3D12/Device/D3DDevice.h>

namespace Portakal
{
	GraphicsDevice* D3DAdapter::CreateDeviceCore()
	{
		return new D3DDevice({ GraphicsBackend::DirectX12,this });
	}
	void D3DAdapter::OnShutdown()
	{
	}
}