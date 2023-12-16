#include "PlatformInput.H"

#ifdef PORTAKAL_PLATFORM_WINDOWS
#include <Runtime/Win32/Win32Input.h>
typedef Portakal::Win32Input PlatformAbstraction;
#endif

namespace Portakal
{
	bool PlatformInput::Initialize()
	{
		return PlatformAbstraction::Initialize();
	}
	void PlatformInput::GetConnectedInputDevices(Array<SharedHeap<InputDevice>>& devicesOut)
	{
		PlatformAbstraction::GetConnectedDevices(devicesOut);
	}
}
