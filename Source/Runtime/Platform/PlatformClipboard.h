#pragma once
#include <Runtime/Containers/String.h>

namespace Portakal
{
	/// <summary>
	/// Clipboard platform utilities
	/// </summary>
	class RUNTIME_API PlatformClipboard final
	{
	public:
		static void SetClipboardText(const String& text);
		static String GetClipboardText();
	public:
		PlatformClipboard() = delete;
		~PlatformClipboard() = delete;
	};
}
