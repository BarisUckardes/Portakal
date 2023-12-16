#pragma once
#include <Runtime/Input/MouseInputDevice.h>
#include <Runtime/DirectInput/DirectInputDevice.h>
#define DIRECTINPUT_VERSION 0x0800 // DirectX 8 header.
#include <dinput.h>

namespace Portakal
{
	class RUNTIME_API DirectInputMouse : public MouseInputDevice, public DirectInputDevice
	{
	public:
		DirectInputMouse(IDirectInputDevice8* pDevice);
		~DirectInputMouse() = default;
	private:

		// Inherited via MouseInputDevice
		void OnShutdown() override;
		void UpdateState() override;
	};
}
