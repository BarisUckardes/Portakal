#pragma once
#include <Runtime/Memory/SharedHeap.h>
#include <Runtime/Input/InputDeviceType.h>

namespace Portakal
{
	class RUNTIME_API InputDevice : public Object
	{
	public:
		InputDevice() = default;
		~InputDevice() = default;

		virtual InputDeviceType GetDeviceType() const noexcept = 0;
	protected:
		virtual void UpdateState() = 0;
	};
}
