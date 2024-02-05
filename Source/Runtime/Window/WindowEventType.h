#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
	/// <summary>
	/// Represents the available types of PlatformWindow events
	/// </summary>
	enum class RUNTIME_API WindowEventType : Byte
	{
		None,

		WindowClosed,
		WindowMoved,
		WindowResized,

		DragDrop,

		KeyboardDown,
		KeyboardUp,
		Char,

		MouseButtonDown,
		MouseButtonUp,
		MouseMoved,
		MouseScrolled,

		GamepadButtonDown,
		GamepadButtonUp,
		GamepadTriggerMove,
		GamepadThumbMove
	};
}