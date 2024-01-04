#include "Win32Registry.h"
#include <Windows.h>

namespace Portakal
{
	void Win32Registry::CreateKey(const String& position)
	{
		HKEY key = NULL;
		DWORD disposition = 0;
		const LSTATUS status = RegCreateKeyEx(HKEY_LOCAL_MACHINE, *position, 0, NULL, 0, KEY_WRITE, NULL, &key, &disposition);
		if (key == NULL)
		{
			return;
		}

		RegCloseKey(key);
	}
	void Win32Registry::SetValue(const String& position, const String& valueName, const String& value)
	{
		HKEY key = NULL;
		const LRESULT openKeyResult = RegOpenKeyEx(HKEY_LOCAL_MACHINE, *position, 0, KEY_ALL_ACCESS, &key);
		if (key == NULL)
		{
			return;
		}

		const LRESULT setValueResult = RegSetValueEx(key, *valueName, 0, REG_SZ, (const Byte*)*value, value.GetSize());
		if (setValueResult != ERROR_SUCCESS)
		{
			return;
		}

		RegCloseKey(key);
	}
}
