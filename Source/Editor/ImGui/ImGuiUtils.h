#pragma once
#include <Runtime/Input/KeyboardKeys.h>
#include <Runtime/Input/MouseButtons.h>
#include <imgui.h>

namespace Portakal
{
	class EDITOR_API ImGuiUtils
	{
	public:
		static ImGuiKey GetKeyboardKey(const KeyboardKeys key);
		static ImGuiMouseButton GetMouseButton(const MouseButtons button);

	public:
		ImGuiUtils() = delete;
		~ImGuiUtils() = delete;
	};
}
