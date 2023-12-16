#pragma once
#include <Runtime/Input/InputDevice.h>
#include <Runtime/Containers/Array.h>
#define DIRECTINPUT_VERSION 0x0800 // DirectX 8 header.
#include <dinput.h>

namespace Portakal
{
	class RUNTIME_API DirectInputSubsystem final
	{
	public:
		static bool Initialize();
		static void GetInputDevices(Array<SharedHeap<InputDevice>>& devicesOut);
	private:
		static inline IDirectInput8* sInput;
	public:
		DirectInputSubsystem() = delete;
		~DirectInputSubsystem() = delete;
	};
}
