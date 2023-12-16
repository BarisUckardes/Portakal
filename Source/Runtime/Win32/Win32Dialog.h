#pragma once
#include <Runtime/Containers/String.h>

namespace Portakal
{
	class RUNTIME_API Win32Dialog final
	{
	public:
		static String CreateOpenFileDialog(const String& filter);
		static String CreateOpenFolderDialog();
	public:
		Win32Dialog() = delete;
		~Win32Dialog() = delete;
	};
}