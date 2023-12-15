#pragma once
#include <Runtime/Containers/String.h>

namespace Portakal
{
	class RUNTIME_API PlatformCipboard final
	{
	public:
		static void SetClipboardText(const String& text);
		static String GetClipboardText();
	public:
		PlatformCipboard() = delete;
		~PlatformCipboard() = delete;

	};
}
