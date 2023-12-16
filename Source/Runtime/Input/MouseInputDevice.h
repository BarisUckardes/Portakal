#pragma once
#include <Runtime/Input/InputDevice.h>
#include <Runtime/Input/MouseButtons.h>

namespace Portakal
{
	class RUNTIME_API MouseInputDevice : public InputDevice
	{
		struct MouseEntry
		{
			bool bDown;
			bool bPressed;
			bool bReleased;
		};
	public:
		MouseInputDevice();
		~MouseInputDevice() = default;


		bool IsButtonDown(const MouseButtons button) const noexcept;
		bool IsButtonUp(const MouseButtons button) const noexcept;
		bool IsButtonPressed(const MouseButtons button) const noexcept;
		bool IsButtonReleased(const MouseButtons button) const noexcept;
		bool GetWheelDelta() const noexcept;
		virtual InputDeviceType GetDeviceType() const noexcept final
		{
			return InputDeviceType::Mouse;
		}
	protected:
		void UpdateButtons(const bool* pButtons);
		void UpdateWheel(const float wheel);
	private:
		MouseEntry mButtons[256];
		bool mLastState[256];
		float mWheelDelta;

	};
}
