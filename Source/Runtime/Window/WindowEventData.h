#pragma once
#include <Runtime/Core/Core.h>
#include <Runtime/Math/Vector2.h>
#include <Runtime/Window/WindowEventType.h>
#include <Runtime/Input/KeyboardKeys.h>
#include <Runtime/Input/MouseButtons.h>
#include <Runtime/Containers/String.h>
#include <Runtime/Containers/Array.h>

namespace Portakal
{
	/// <summary>
	/// Event data that PlatformWindow broadcasts
	/// </summary>
	struct RUNTIME_API WindowEventData
	{
		WindowEventType Type;

		Vector2US WindowSize;
		Vector2I WindowPosition;

		MouseButtons MouseButton;
		Vector2I MousePosition;
		float MouseWheelDelta;

		KeyboardKeys KeyboardKey;
		Char KeyboardChar;

		Byte WindowIndex;

		Array<String> DropItems;
	};
}