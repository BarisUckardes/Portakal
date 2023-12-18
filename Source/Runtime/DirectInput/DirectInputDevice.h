#pragma once
#include <Runtime/Input/InputDevice.h>
#define DIRECTINPUT_VERSION 0x0800 // DirectX 8 header.
#include <dinput.h>

namespace Portakal
{
	class RUNTIME_API DirectInputDevice
	{
	public:
		DirectInputDevice(const InputDeviceType type, IDirectInputDevice8* pDevice);
		~DirectInputDevice();
	protected:
		FORCEINLINE IDirectInputDevice8* GetDevice() const noexcept { return mDevice; }
	private:
		IDirectInputDevice8* mDevice;
	};
}
