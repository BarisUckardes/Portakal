#include "Win32Clipboard.h"
#include <Runtime/Containers/Array.h>
#include <Windows.h>

namespace Portakal
{
	void Win32Clipboard::SetClipboardText(const String& text)
	{
		/*
		* Open clipboard for access
		*/
		OpenClipboard(NULL);

		/*
		* Clear the clipboard
		*/
		EmptyClipboard();

		/*
		* Get text to global memory
		*/
		const HGLOBAL globalMemory = GlobalAlloc(GMEM_MOVEABLE, text.GetSize() + 1);
		Memory::Copy(GlobalLock(globalMemory), text.GetSource(), text.GetSize() + 1);
		GlobalUnlock(globalMemory);

		/*
		* Set clip board data
		*/
		SetClipboardData(CF_TEXT, globalMemory);

		/*
		* Close clipboard acess
		*/
		CloseClipboard();

		/*
		* Free the memory
		*/
		GlobalFree(globalMemory);
	}
	String Win32Clipboard::GetClipboardText()
	{
		/*
		* Open clipboard for access
		*/
		OpenClipboard(NULL);

		/*
		* Get text
		*/
		const HANDLE handle = GetClipboardData(CF_TEXT);

		/*
		* Lock the data and write to string
		*/
		GlobalLock(handle);
		const String value = (Char*)handle;
		GlobalUnlock(handle);


		return value;
	}
}
