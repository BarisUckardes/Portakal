#include "DirectInputMouse.h"

namespace Portakal
{
	DirectInputMouse::DirectInputMouse(IDirectInputDevice8* pDevice) : DirectInputDevice(InputDeviceType::Mouse,pDevice)
	{

	}
	void DirectInputMouse::OnShutdown()
	{

	}
	void DirectInputMouse::UpdateState()
	{
		//Get device state
		DIMOUSESTATE state = {};
		if (FAILED(GetDirectInputDevice()->GetDeviceState(sizeof(state), &state)))
		{
			DEV_LOG("DirectInputMouse", "Failed to get device state");
			return;
		}

		//Catch buttons
		Bool8 states[4];
		for (Uint16 i = 0; i < 4; i++)
			states[i] = state.rgbButtons[i] == 1;

		//Update buttons
		UpdateButtons(states);

		//Update wheels
		UpdateWheel(0);
	}
}
