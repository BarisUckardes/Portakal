#include "MouseInputDevice.h"
#include <Runtime/Memory/Memory.h>

namespace Portakal
{
	MouseInputDevice::MouseInputDevice()
	{
		for (UInt16 i = 0; i < 256; i++)
		{
			mLastState[i] = false;
			mButtons[i] = {};
		}
	}
	Bool8 MouseInputDevice::IsButtonDown(const MouseButtons button) const noexcept
	{
		return mButtons[(UInt16)button].bDown;
	}
	Bool8 MouseInputDevice::IsButtonUp(const MouseButtons button) const noexcept
	{
		return !mButtons[(UInt16)button].bDown;
	}
	Bool8 MouseInputDevice::IsButtonPressed(const MouseButtons button) const noexcept
	{
		return mButtons[(UInt16)button].bPressed;
	}
	Bool8 MouseInputDevice::IsButtonReleased(const MouseButtons button) const noexcept
	{
		return mButtons[(UInt16)button].bReleased;
	}
	Bool8 MouseInputDevice::GetWheelDelta() const noexcept
	{
		return mWheelDelta;
	}
	void MouseInputDevice::UpdateButtons(const Bool8* pButtons)
	{
		//Set keys
		for (UInt16 i = 0; i < 256; i++)
		{
			const Bool8 bOldState = mLastState[i];
			const Bool8 bNewState = pButtons[i];

			MouseEntry& entry = mButtons[i];
			entry.bDown = bNewState;
			entry.bPressed = bNewState && !bOldState;
			entry.bReleased = !bNewState && bOldState;
		}

		//Cache last state
		Memory::Copy(mLastState, pButtons, 256);
	}
	void MouseInputDevice::UpdateWheel(const Float32 wheel)
	{
		mWheelDelta = wheel;
	}
}
