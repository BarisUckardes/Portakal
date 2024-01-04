#include "DirectInputKeyboard.h"
#include <Runtime/DirectInput/DirectInputKeys.h>

namespace Portakal
{
	DirectInputKeyboard::DirectInputKeyboard(IDirectInputDevice8* pDevice) : DirectInputDevice(InputDeviceType::Keyboard, pDevice)
	{


	}
	void DirectInputKeyboard::OnShutdown()
	{
	}
	void DirectInputKeyboard::UpdateState()
	{
		//Get device state
		Bool8 cachedStates[256];
		if (FAILED(GetDirectInputDevice()->GetDeviceState(sizeof(cachedStates), cachedStates)))
		{
			DEV_LOG("DirectInputKeyboard", "Failed to get device state");
			return;
		}

		//Catch keys
		Bool8 states[256];
		for (UInt16 i = 0; i < 256; i++)
		{
			const KeyboardKeys key = DirectInputKeys::GetKey(i);
			states[(UInt16)key] = cachedStates[i];
		}

		//Update states
		UpdateKeyState(states);
	}
}
