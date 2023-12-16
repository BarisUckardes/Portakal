#include "KeyboardInputDevice.h"
#include <Runtime/Memory/Memory.h>

namespace Portakal
{
	KeyboardInputDevice::KeyboardInputDevice()
	{
		for(uint16 i = 0;i<256;i++)
		{
			mLastState[i] = false;
			mKeys[i] = {};
		}
	}
	bool KeyboardInputDevice::IsKeyDown(const KeyboardKeys key) const noexcept
	{
		return mKeys[(uint16)key].bDown;
	}
	bool KeyboardInputDevice::IsKeyUp(const KeyboardKeys key) const noexcept
	{
		return !mKeys[(uint16)key].bDown;
	}
	bool KeyboardInputDevice::IsKeyPressed(const KeyboardKeys key) const noexcept
	{
		return mKeys[(uint16)key].bPressed;
	}
	bool KeyboardInputDevice::IsKeyReleased(const KeyboardKeys key) const noexcept
	{
		return mKeys[(uint16)key].bReleased;
	}
	void KeyboardInputDevice::UpdateKeyState(const bool* pKeys)
	{
		//Set states
		for (uint16 i = 0; i < 256; i++)
		{
			const bool bOldState = mLastState[i];
			const bool bNewState = pKeys[i];

			KeyEntry& entry = mKeys[i];
			entry.bDown = bNewState;
			entry.bPressed = bNewState && !bOldState;
			entry.bReleased = !bNewState && bOldState;
		}

		//Cache last state
		Memory::Copy(mLastState, pKeys, 256);
	}
}
