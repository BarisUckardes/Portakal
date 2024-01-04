#include "KeyboardInputDevice.h"
#include <Runtime/Memory/Memory.h>

namespace Portakal
{
	KeyboardInputDevice::KeyboardInputDevice()
	{
		for(UInt16 i = 0;i<256;i++)
		{
			mLastState[i] = false;
			mKeys[i] = {};
		}
	}
	Bool8 KeyboardInputDevice::IsKeyDown(const KeyboardKeys key) const noexcept
	{
		return mKeys[(UInt16)key].bDown;
	}
	Bool8 KeyboardInputDevice::IsKeyUp(const KeyboardKeys key) const noexcept
	{
		return !mKeys[(UInt16)key].bDown;
	}
	Bool8 KeyboardInputDevice::IsKeyPressed(const KeyboardKeys key) const noexcept
	{
		return mKeys[(UInt16)key].bPressed;
	}
	Bool8 KeyboardInputDevice::IsKeyReleased(const KeyboardKeys key) const noexcept
	{
		return mKeys[(UInt16)key].bReleased;
	}
	void KeyboardInputDevice::UpdateKeyState(const Bool8* pKeys)
	{
		//Set states
		for (UInt16 i = 0; i < 256; i++)
		{
			const Bool8 bOldState = mLastState[i];
			const Bool8 bNewState = pKeys[i];

			KeyEntry& entry = mKeys[i];
			entry.bDown = bNewState;
			entry.bPressed = bNewState && !bOldState;
			entry.bReleased = !bNewState && bOldState;
		}

		//Cache last state
		Memory::Copy(mLastState, pKeys, 256);
	}
}
