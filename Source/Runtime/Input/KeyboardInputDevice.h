#pragma once
#include <Runtime/Input/InputDevice.h>
#include <Runtime/Input/KeyboardKeys.h>

namespace Portakal
{
	class RUNTIME_API KeyboardInputDevice : public InputDevice
	{
	private:
		struct KeyEntry
		{
			Bool8 bDown;
			Bool8 bPressed;
			Bool8 bReleased;
		};
	public:
		KeyboardInputDevice();
		~KeyboardInputDevice() = default;

		Bool8 IsKeyDown(const KeyboardKeys key) const noexcept;
		Bool8 IsKeyUp(const KeyboardKeys key) const noexcept;
		Bool8 IsKeyPressed(const KeyboardKeys key) const noexcept;
		Bool8 IsKeyReleased(const KeyboardKeys key) const noexcept;
		virtual InputDeviceType GetDeviceType() const noexcept final { return InputDeviceType::Keyboard; }
	protected:
		virtual void UpdateKeyState(const Bool8* pKeys);
	private:
		Bool8 mLastState[256];
		KeyEntry mKeys[256];
	};
}
