#pragma once
#include <Runtime/Containers/String.h>
#include <Runtime/Console/ConsoleColor.h>


namespace Portakal
{
	class RUNTIME_API Win32Console final
	{
		constexpr static inline ConsoleColor DefaultBackgroundColor = ConsoleColor::Black;
		constexpr static inline ConsoleColor DefaultTextColor = ConsoleColor::White;
	public:
		static void Write(const String& text);
		static void WriteLine(const String& text);
		static void SetTextColor(const ConsoleColor color);
		static void SetBackgroundColor(const ConsoleColor color);
		static void Clear();
	public:
		Win32Console() = delete;
		~Win32Console() = delete;
	};
}
