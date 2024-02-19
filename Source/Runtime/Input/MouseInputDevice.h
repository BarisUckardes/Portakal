#pragma once
#include <Runtime/Input/InputDevice.h>
#include <Runtime/Input/MouseButtons.h>

namespace Portakal
{
	class RUNTIME_API MouseInputDevice : public InputDevice
	{
		struct MouseEntry
		{
			Bool8 bDown;
			Bool8 bPressed;
			Bool8 bReleased;
		};
	public:
		MouseInputDevice();
		~MouseInputDevice() = default;


		Bool8 IsButtonDown(const MouseButtons button) const noexcept;
		Bool8 IsButtonUp(const MouseButtons button) const noexcept;
		Bool8 IsButtonPressed(const MouseButtons button) const noexcept;
		Bool8 IsButtonReleased(const MouseButtons button) const noexcept;
		Bool8 GetWheelDelta() const noexcept;
		virtual InputDeviceType GetDeviceType() const noexcept final
		{
			return InputDeviceType::Mouse;
		}
	protected:
		void UpdateButtons(const Bool8* pButtons);
		void UpdateWheel(const Float32 wheel);
	private:
		MouseEntry mButtons[256];
		Bool8 mLastState[256];
		Float32 mWheelDelta;

	};
}
