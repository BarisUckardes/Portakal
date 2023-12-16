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
		bool cachedStates[256];
		if (FAILED(GetDevice()->GetDeviceState(sizeof(cachedStates), cachedStates)))
		{
			DEV_LOG("DirectInputKeyboard", "Failed to get device state");
			return;
		}

		//Catch keys
		bool states[256];
		for (uint16 i = 0; i < 256; i++)
		{
			const KeyboardKeys key = DirectInputKeys::GetKey(i);
			states[(uint16)key] = cachedStates[i];
		}

		//Update states
		UpdateKeyState(states);
	}
}
