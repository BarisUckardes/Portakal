#pragma once
#include <Runtime/Core/Core.h>
#include <Runtime/Math/Vector2.h>
#include <Runtime/Window/WindowEventType.h>
#include <Runtime/Input/KeyboardKeys.h>
#include <Runtime/Input/MouseButtons.h>

namespace Portakal
{
	struct RUNTIME_API WindowEventData
	{
		WindowEventData() : Handled(false), Type(WindowEventType::None)
		{

		}
		WindowEventType Type;

		Vector2UI WindowSize;
		Vector2I WindowPosition;

		MouseButtons MouseButton;
		Vector2I MousePosition;
		float MouseWheelDelta;

		KeyboardKeys KeyboardKey;
		char KeyboardChar;

		bool Handled;
		byte WindowIndex;
	};
}