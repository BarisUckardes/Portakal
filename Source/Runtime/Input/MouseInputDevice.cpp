#include "MouseInputDevice.h"
#include <Runtime/Memory/Memory.h>

namespace Portakal
{
	MouseInputDevice::MouseInputDevice()
	{
		for (uint16 i = 0; i < 256; i++)
		{
			mLastState[i] = false;
			mButtons[i] = {};
		}
	}
	bool MouseInputDevice::IsButtonDown(const MouseButtons button) const noexcept
	{
		return mButtons[(uint16)button].bDown;
	}
	bool MouseInputDevice::IsButtonUp(const MouseButtons button) const noexcept
	{
		return !mButtons[(uint16)button].bDown;
	}
	bool MouseInputDevice::IsButtonPressed(const MouseButtons button) const noexcept
	{
		return mButtons[(uint16)button].bPressed;
	}
	bool MouseInputDevice::IsButtonReleased(const MouseButtons button) const noexcept
	{
		return mButtons[(uint16)button].bReleased;
	}
	bool MouseInputDevice::GetWheelDelta() const noexcept
	{
		return mWheelDelta;
	}
	void MouseInputDevice::UpdateButtons(const bool* pButtons)
	{
		//Set keys
		for (uint16 i = 0; i < 256; i++)
		{
			const bool bOldState = mLastState[i];
			const bool bNewState = pButtons[i];

			MouseEntry& entry = mButtons[i];
			entry.bDown = bNewState;
			entry.bPressed = bNewState && !bOldState;
			entry.bReleased = !bNewState && bOldState;
		}

		//Cache last state
		Memory::Copy(mLastState, pButtons, 256);
	}
	void MouseInputDevice::UpdateWheel(const float wheel)
	{
		mWheelDelta = wheel;
	}
}
