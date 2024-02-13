#pragma once
#include <Runtime/Containers/String.h>
#include <Runtime/Console/ConsoleColor.h>

namespace Portakal
{
	/// <summary>
	/// Console works platform implementation
	/// </summary>
	class RUNTIME_API PlatformConsole final
	{
		constexpr static inline ConsoleColor DefaultBackgroundColor = ConsoleColor::Black;
		constexpr static inline ConsoleColor DefaultTextColor = ConsoleColor::White;
	public:
		static void Write(const String& text);
		static void WriteLine(const String& text);
		static void SetTextColor(const ConsoleColor color);
		static void SetBackgroundColor(const ConsoleColor color);
		static void SetDefaultTextColor();
		static void SetDefaultBackgroundColor();
		static void Clear();
	public:
		PlatformConsole() = delete;
		~PlatformConsole() = delete;
	};
}
