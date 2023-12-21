#include "Win32Message.h"
#include <Windows.h>
#include <Runtime/Win32/Win32MessageBoxUtils.h>
namespace Portakal
{
	void Win32Message::Show(const String& title, const String& message, const MessageFlags flags)
	{
		MessageBox(NULL, *message, *title, (UINT)Win32MessageBoxUtils::GetFlags(flags));
	}
}
