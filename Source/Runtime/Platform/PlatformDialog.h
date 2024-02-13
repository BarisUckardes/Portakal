#pragma once
#include <Runtime/Containers/String.h>

namespace Portakal
{
	/// <summary>
	/// Dialog platform implementation
	/// </summary>
	class RUNTIME_API PlatformDialog final
	{
	public:
		static String CreateOpenFileDialog(const String& filter = "");
		static String CreateOpenFolderDialog();
	public:
		PlatformDialog() = delete;
		~PlatformDialog() = delete;
	};
}
