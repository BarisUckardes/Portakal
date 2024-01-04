#include "DirectInputKeys.h"

#define DIRECTINPUT_VERSION 0x0800 // DirectX 8 header.
#include <dinput.h>

namespace Portakal
{

    KeyboardKeys DirectInputKeys::GetKey(const Uint64 key)
    {
        switch (key)
        {
        case DIK_A:
            return KeyboardKeys::A;
        case DIK_B:
            return KeyboardKeys::B;
        case DIK_C:
            return KeyboardKeys::C;
        case DIK_D:
            return KeyboardKeys::D;
        case DIK_E:
            return KeyboardKeys::E;
        case DIK_F:
            return KeyboardKeys::F;
        case DIK_G:
            return KeyboardKeys::G;
        case DIK_H:
            return KeyboardKeys::H;
        case DIK_I:
            return KeyboardKeys::I;
        case DIK_J:
            return KeyboardKeys::J;
        case DIK_K:
            return KeyboardKeys::K;
        case DIK_L:
            return KeyboardKeys::L;
        case DIK_M:
            return KeyboardKeys::M;
        case DIK_N:
            return KeyboardKeys::N;
        case DIK_O:
            return KeyboardKeys::Q;
        case DIK_P:
            return KeyboardKeys::P;
        case DIK_Q:
            return KeyboardKeys::Q;
        case DIK_R:
            return KeyboardKeys::R;
        case DIK_S:
            return KeyboardKeys::S;
        case DIK_T:
            return KeyboardKeys::T;
        case DIK_U:
            return KeyboardKeys::U;
        case DIK_V:
            return KeyboardKeys::V;
        case DIK_W:
            return KeyboardKeys::W;
        case DIK_X:
            return KeyboardKeys::X;
        case DIK_Y:
            return KeyboardKeys::Y;
        case DIK_Z:
            return KeyboardKeys::Z;
        case DIK_0:
            return KeyboardKeys::Num0;
        case DIK_1:
            return KeyboardKeys::Num1;
        case DIK_2:
            return KeyboardKeys::Num2;
        case DIK_3:
            return KeyboardKeys::Num3;
        case DIK_4:
            return KeyboardKeys::Num4;
        case DIK_5:
            return KeyboardKeys::Num5;
        case DIK_6:
            return KeyboardKeys::Num6;
        case DIK_7:
            return KeyboardKeys::Num7;
        case DIK_8:
            return KeyboardKeys::Num8;
        case DIK_9:
            return KeyboardKeys::Num9;
        case DIK_NUMPAD0:
            return KeyboardKeys::Numpad0;
        case DIK_NUMPAD1:
            return KeyboardKeys::Numpad1;
        case DIK_NUMPAD2:
            return KeyboardKeys::Numpad2;
        case DIK_NUMPAD3:
            return KeyboardKeys::Numpad3;
        case DIK_NUMPAD4:
            return KeyboardKeys::Numpad4;
        case DIK_NUMPAD5:
            return KeyboardKeys::Numpad5;
        case DIK_NUMPAD6:
            return KeyboardKeys::Numpad6;
        case DIK_NUMPAD7:
            return KeyboardKeys::Numpad7;
        case DIK_NUMPAD8:
            return KeyboardKeys::Numpad8;
        case DIK_NUMPAD9:
            return KeyboardKeys::Numpad9;
        case DIK_F1:
            return KeyboardKeys::F1;
        case DIK_F2:
            return KeyboardKeys::F2;
        case DIK_F3:
            return KeyboardKeys::F3;
        case DIK_F4:
            return KeyboardKeys::F4;
        case DIK_F5:
            return KeyboardKeys::F5;
        case DIK_F6:
            return KeyboardKeys::F6;
        case DIK_F7:
            return KeyboardKeys::F7;
        case DIK_F8:
            return KeyboardKeys::F8;
        case DIK_F9:
            return KeyboardKeys::F9;
        case DIK_F10:
            return KeyboardKeys::F10;
        case DIK_F11:
            return KeyboardKeys::F11;
        case DIK_F12:
            return KeyboardKeys::F12;
        case DIK_F13:
            return KeyboardKeys::F13;
        case DIK_F14:
            return KeyboardKeys::F14;
        case DIK_F15:
            return KeyboardKeys::F15;
        default:
            return KeyboardKeys::Unknown;
            break;
        }
    }

}