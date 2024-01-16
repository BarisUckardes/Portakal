#include "ImGuiUtils.h"
#include <Runtime/Reflection/Reflection.h>

#pragma warning(push)
#pragma warning(disable : 4715)

namespace Portakal
{
	ImGuiKey ImGuiUtils::GetKeyboardKey(const KeyboardKeys key)
	{
		switch (key)
		{
		case KeyboardKeys::Unknown:
			break;
		case KeyboardKeys::Space:
			return ImGuiKey_Space;
		case KeyboardKeys::Apostrophe:
			return ImGuiKey_Apostrophe;
		case KeyboardKeys::Comma:
			return ImGuiKey_Comma;
		case KeyboardKeys::Minus:
			return ImGuiKey_Minus;
		case KeyboardKeys::Period:
			return ImGuiKey_Period;
		case KeyboardKeys::Slash:
			return ImGuiKey_Slash;
		case KeyboardKeys::Num0:
			return ImGuiKey_0;
		case KeyboardKeys::Num1:
			return ImGuiKey_1;
		case KeyboardKeys::Num2:
			return ImGuiKey_2;
		case KeyboardKeys::Num3:
			return ImGuiKey_3;
		case KeyboardKeys::Num4:
			return ImGuiKey_4;
		case KeyboardKeys::Num5:
			return ImGuiKey_5;
		case KeyboardKeys::Num6:
			return ImGuiKey_6;
		case KeyboardKeys::Num7:
			return ImGuiKey_7;
		case KeyboardKeys::Num8:
			return ImGuiKey_8;
		case KeyboardKeys::Num9:
			return ImGuiKey_9;
		case KeyboardKeys::SemiColon:
			return ImGuiKey_Semicolon;
		case KeyboardKeys::Equal:
			return ImGuiKey_Equal;
		case KeyboardKeys::A:
			return ImGuiKey_A;
		case KeyboardKeys::B:
			return ImGuiKey_B;
		case KeyboardKeys::C:
			return ImGuiKey_C;
		case KeyboardKeys::D:
			return ImGuiKey_D;
		case KeyboardKeys::E:
			return ImGuiKey_E;
		case KeyboardKeys::F:
			return ImGuiKey_F;
		case KeyboardKeys::G:
			return ImGuiKey_G;
		case KeyboardKeys::H:
			return ImGuiKey_H;
		case KeyboardKeys::I:
			return ImGuiKey_I;
		case KeyboardKeys::J:
			return ImGuiKey_J;
		case KeyboardKeys::K:
			return ImGuiKey_K;
		case KeyboardKeys::L:
			return ImGuiKey_L;
		case KeyboardKeys::M:
			return ImGuiKey_M;
		case KeyboardKeys::N:
			return ImGuiKey_N;
		case KeyboardKeys::O:
			return ImGuiKey_O;
		case KeyboardKeys::P:
			return ImGuiKey_P;
		case KeyboardKeys::Q:
			return ImGuiKey_Q;
		case KeyboardKeys::R:
			return ImGuiKey_R;
		case KeyboardKeys::S:
			return ImGuiKey_S;
		case KeyboardKeys::T:
			return ImGuiKey_T;
		case KeyboardKeys::U:
			return ImGuiKey_U;
		case KeyboardKeys::V:
			return ImGuiKey_V;
		case KeyboardKeys::W:
			return ImGuiKey_W;
		case KeyboardKeys::X:
			return ImGuiKey_X;
		case KeyboardKeys::Y:
			return ImGuiKey_Y;
		case KeyboardKeys::Z:
			return ImGuiKey_Z;
		case KeyboardKeys::LeftBracket:
			return ImGuiKey_LeftBracket;
		case KeyboardKeys::Backslash:
			return ImGuiKey_Backslash;
		case KeyboardKeys::RightBracket:
			return ImGuiKey_RightBracket;
		case KeyboardKeys::GraveAccent:
			return ImGuiKey_GraveAccent;
		case KeyboardKeys::World1:
			return ImGuiKey_None;
		case KeyboardKeys::World2:
			return ImGuiKey_None;
		case KeyboardKeys::Escape:
			return ImGuiKey_Escape;
		case KeyboardKeys::Enter:
			return ImGuiKey_Enter;
		case KeyboardKeys::Tab:
			return ImGuiKey_Tab;
		case KeyboardKeys::Backspace:
			return ImGuiKey_Backspace;
		case KeyboardKeys::Insert:
			return ImGuiKey_Insert;
		case KeyboardKeys::Delete:
			return ImGuiKey_Delete;
		case KeyboardKeys::Right:
			return ImGuiKey_RightArrow;
		case KeyboardKeys::Left:
			return ImGuiKey_LeftArrow;
		case KeyboardKeys::Down:
			return ImGuiKey_DownArrow;
		case KeyboardKeys::Up:
			return ImGuiKey_UpArrow;
		case KeyboardKeys::PageUp:
			return ImGuiKey_PageUp;
		case KeyboardKeys::PageDown:
			return ImGuiKey_PageDown;
		case KeyboardKeys::Home:
			return ImGuiKey_Home;
		case KeyboardKeys::End:
			return ImGuiKey_End;
		case KeyboardKeys::CapsLock:
			return ImGuiKey_CapsLock;
		case KeyboardKeys::ScrollLock:
			return ImGuiKey_ScrollLock;
		case KeyboardKeys::NumLock:
			return ImGuiKey_NumLock;
		case KeyboardKeys::PrintScreen:
			return ImGuiKey_PrintScreen;
		case KeyboardKeys::Pause:
			return ImGuiKey_Pause;
		case KeyboardKeys::F1:
			return ImGuiKey_F1;
		case KeyboardKeys::F2:
			return ImGuiKey_F2;
		case KeyboardKeys::F3:
			return ImGuiKey_F3;
		case KeyboardKeys::F4:
			return ImGuiKey_F4;
		case KeyboardKeys::F5:
			return ImGuiKey_F5;
		case KeyboardKeys::F6:
			return ImGuiKey_F6;
		case KeyboardKeys::F7:
			return ImGuiKey_F7;
		case KeyboardKeys::F8:
			return ImGuiKey_F8;
		case KeyboardKeys::F9:
			return ImGuiKey_F9;
		case KeyboardKeys::F10:
			return ImGuiKey_F10;
		case KeyboardKeys::F11:
			return ImGuiKey_F11;
		case KeyboardKeys::F12:
			return ImGuiKey_F12;
		case KeyboardKeys::F13:
			return ImGuiKey_F13;
		case KeyboardKeys::F14:
			return ImGuiKey_F14;
		case KeyboardKeys::F15:
			return ImGuiKey_F15;
		case KeyboardKeys::F16:
			return ImGuiKey_F16;
		case KeyboardKeys::F17:
			return ImGuiKey_F17;
		case KeyboardKeys::F18:
			return ImGuiKey_F18;
		case KeyboardKeys::F19:
			return ImGuiKey_F19;
		case KeyboardKeys::F20:
			return ImGuiKey_F20;
		case KeyboardKeys::F21:
			return ImGuiKey_F21;
		case KeyboardKeys::F22:
			return ImGuiKey_F22;
		case KeyboardKeys::F23:
			return ImGuiKey_F23;
		case KeyboardKeys::F24:
			return ImGuiKey_F24;
		case KeyboardKeys::Kp0:
			return ImGuiKey_Keypad0;
		case KeyboardKeys::Kp1:
			return ImGuiKey_Keypad1;
		case KeyboardKeys::Kp2:
			return ImGuiKey_Keypad2;
		case KeyboardKeys::Kp3:
			return ImGuiKey_Keypad3;
		case KeyboardKeys::Kp4:
			return ImGuiKey_Keypad4;
		case KeyboardKeys::Kp5:
			return ImGuiKey_Keypad5;
		case KeyboardKeys::Kp6:
			return ImGuiKey_Keypad6;
		case KeyboardKeys::Kp7:
			return ImGuiKey_Keypad7;
		case KeyboardKeys::Kp8:
			return ImGuiKey_Keypad8;
		case KeyboardKeys::Kp9:
			return ImGuiKey_Keypad9;
		case KeyboardKeys::KpDecimal:
			return ImGuiKey_KeypadDecimal;
		case KeyboardKeys::KpDivide:
			return ImGuiKey_KeypadDivide;
		case KeyboardKeys::KpMultiply:
			return ImGuiKey_KeypadMultiply;
		case KeyboardKeys::KpSubtract:
			return ImGuiKey_KeypadSubtract;
		case KeyboardKeys::KpAdd:
			return ImGuiKey_KeypadAdd;
		case KeyboardKeys::KpEnter:
			return ImGuiKey_KeypadEnter;
		case KeyboardKeys::KpEqual:
			return ImGuiKey_KeypadEqual;
		case KeyboardKeys::LeftShift:
			return ImGuiKey_LeftShift;
		case KeyboardKeys::LeftControl:
			return ImGuiKey_LeftCtrl;
		case KeyboardKeys::LeftAlt:
			return ImGuiKey_LeftAlt;
		case KeyboardKeys::LeftSuper:
			return ImGuiKey_LeftSuper;
		case KeyboardKeys::RightShift:
			return ImGuiKey_RightShift;
		case KeyboardKeys::RightControl:
			return ImGuiKey_RightCtrl;
		case KeyboardKeys::RightAlt:
			return ImGuiKey_RightAlt;
		case KeyboardKeys::RightSuper:
			return ImGuiKey_RightSuper;
		case KeyboardKeys::Menu:
			return ImGuiKey_Menu;
		default:
			return ImGuiKey_None;
			break;
		}
	}

	ImGuiMouseButton ImGuiUtils::GetMouseButton(const MouseButtons button)
	{
		switch (button)
		{
		case MouseButtons::Right:
		default:
			return ImGuiMouseButton_Right;
		case MouseButtons::Left:
			return ImGuiMouseButton_Left;
		case MouseButtons::Middle:
			return ImGuiMouseButton_Middle;
		}
	}
	String ImGuiUtils::TextField(const String& name, const String input)
	{
		std::string temp(input.GetSource(), input.GetSize());
		ImGui::InputText(*name, &temp);
		return temp.c_str();
	}
	String ImGuiUtils::MultiTextField(const String& name, const String input)
	{
		std::string temp(input.GetSource(), input.GetSize());
		ImGui::InputTextMultiline(*name, &temp);
		return temp.c_str();
	}
}

#pragma warning(pop)