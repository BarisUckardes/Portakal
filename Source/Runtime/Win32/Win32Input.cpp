#include "Win32Input.h"
#include <Runtime/DirectInput/DirectInputSubsystem.h>

namespace Portakal
{
	Bool8 Win32Input::Initialize()
	{
		return DirectInputSubsystem::Initialize();
	}
	void Win32Input::GetConnectedDevices(Array<SharedHeap<InputDevice>>& devices)
	{
		DirectInputSubsystem::GetInputDevices(devices);
	}
}
