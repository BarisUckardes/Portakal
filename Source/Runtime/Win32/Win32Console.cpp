#include "Win32Console.h"
#include <Runtime/Containers/Array.h>
#include <Windows.h>
#include <cstdlib>

namespace Portakal
{
	ConsoleColor gLastBackgroundColor = ConsoleColor::Black;
	ConsoleColor gLastTextColor = ConsoleColor::White;

	void Win32Console::Write(const String& text)
	{
		/*
		* Get std handle
		*/
		const HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
		if (handle == NULL || handle == INVALID_HANDLE_VALUE)
			return;

		/*
		* Write to console
		*/
		DWORD writtenBytes = 0;
		WriteConsoleA(handle, *text, text.GetSize(), &writtenBytes, NULL);
	}
	void Win32Console::WriteLine(const String& text)
	{
		/*
		* Get std handle
		*/
		const HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
		if (handle == NULL || handle == INVALID_HANDLE_VALUE)
			return;

		/*
		* Write to console
		*/
		DWORD writtenBytes = 0;
		WriteConsoleA(handle, *text, text.GetSize(), &writtenBytes, NULL);
		writtenBytes = 0;
		WriteConsoleA(handle, "\n",sizeof("\n"), &writtenBytes, NULL);
	}
	void Win32Console::SetTextColor(const ConsoleColor color)
	{
		/*
		* Get std handle
		*/
		const HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
		if (handle == NULL || handle == INVALID_HANDLE_VALUE)
			return;

		SetConsoleTextAttribute(handle, (byte)color + (byte)gLastBackgroundColor + 16);
	}
	void Win32Console::SetBackgroundColor(const ConsoleColor color)
	{
		/*
		* Get std handle
		*/
		const HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
		if (handle == NULL || handle == INVALID_HANDLE_VALUE)
			return;

		SetConsoleTextAttribute(handle,(byte)gLastBackgroundColor + (byte)color*16);
	}
	void Win32Console::Clear()
	{
		system("cls");
	}
}
