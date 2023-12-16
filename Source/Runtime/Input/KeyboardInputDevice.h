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
			bool bDown;
			bool bPressed;
			bool bReleased;
		};
	public:
		KeyboardInputDevice();
		~KeyboardInputDevice() = default;

		bool IsKeyDown(const KeyboardKeys key) const noexcept;
		bool IsKeyUp(const KeyboardKeys key) const noexcept;
		bool IsKeyPressed(const KeyboardKeys key) const noexcept;
		bool IsKeyReleased(const KeyboardKeys key) const noexcept;
		virtual InputDeviceType GetDeviceType() const noexcept final { return InputDeviceType::Keyboard; }
	protected:
		virtual void UpdateKeyState(const bool* pKeys);
	private:
		bool mLastState[256];
		KeyEntry mKeys[256];
	};
}
