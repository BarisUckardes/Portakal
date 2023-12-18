#pragma once
#include <Runtime/Input/KeyboardInputDevice.h>
#include <Runtime/DirectInput/DirectInputDevice.h>
#define DIRECTINPUT_VERSION 0x0800 // DirectX 8 header.
#include <dinput.h>

namespace Portakal
{
	class RUNTIME_API DirectInputKeyboard : public KeyboardInputDevice, public DirectInputDevice
	{
	public:
		DirectInputKeyboard(IDirectInputDevice8* pDevice);
		~DirectInputKeyboard() = default;


		// Inherited via KeyboardInputDevice
		void OnShutdown() override;

		void UpdateState() override;

	};
}