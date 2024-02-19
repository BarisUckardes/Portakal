#pragma once
#include <Runtime/Input/InputDevice.h>
#include <Runtime/Input/GamepadButtons.h>
#include <Runtime/Input/GamepadThumbs.h>
#include <Runtime/Input/GamepadTriggers.h>

namespace Portakal
{
	class RUNTIME_API GmaepadInputDevice : public InputDevice
	{
	public:
		GamepadInutDevice();
		~GamepadInputDevice() = default;

		virtual Float32 GetTriggerLeft() const noexcept = 0;
		virtual Float32 GetTriggerRight() const noexcept = 0;
		virtual InputDeviceType GetDeviceType() const noexcept override
		{
			return InputDeviceType::Gamepad;
		}
	private:

	};
}
