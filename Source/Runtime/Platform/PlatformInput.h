#pragma once
#include <Runtime/Input/InputDevice.h>
#include <Runtime/Memory/SharedHeap.h>
#include <Runtime/Containers/Array.h>

namespace Portakal
{
	class RUNTIME_API PlatformInput final
	{
	public:
		static Bool8 Initialize();
		static void GetConnectedInputDevices(Array<SharedHeap<InputDevice>>& devicesOut);
	public:
		PlatformInput() = delete;
		~PlatformInput() = delete;
	};
}
