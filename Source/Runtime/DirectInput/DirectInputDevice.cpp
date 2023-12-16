#include "DirectInputDevice.h"

namespace Portakal
{
	DirectInputDevice::DirectInputDevice(const InputDeviceType type, IDirectInputDevice8* pDevice) : mDevice(nullptr)
	{
		switch (type)
		{
		case Portakal::InputDeviceType::Keyboard:
		{
			if (FAILED(pDevice->SetDataFormat(&c_dfDIKeyboard)))
			{
				DEV_LOG("DirectInputDevice", "Failed to set the keyboard data format");
				return;
			}

			break;
		}
		case Portakal::InputDeviceType::Mouse:
		{
			if (FAILED(pDevice->SetDataFormat(&c_dfDIMouse)))
			{
				DEV_LOG("DirectInputDevice", "Failed to set the mouse data format");
				return;
			}

			break;
		}
		case Portakal::InputDeviceType::Joystick:
		{
			if (FAILED(pDevice->SetDataFormat(&c_dfDIKeyboard)))
			{
				DEV_LOG("DirectInputDevice", "Failed to set the keyboard data format");
				return;
			}

			break;
		}
		case Portakal::InputDeviceType::Gamepad:
		{
			if (FAILED(pDevice->SetDataFormat(&c_dfDIKeyboard)))
			{
				DEV_LOG("DirectInputDevice", "Failed to set the keyboard data format");
				return;
			}

			break;
		}
		default:
			break;
		}

		//Acquire
		if(FAILED(pDevice->Acquire()))
		{
			DEV_LOG("DirectInputDevice", "Failed to acquire device");
			return;
		}

		mDevice = pDevice;
	}
	DirectInputDevice::~DirectInputDevice()
	{
		if (mDevice != nullptr)
			if (FAILED(mDevice->Unacquire()))
				DEV_LOG("DirectInputDevice", "Failed to unacquire device");
	}
}
