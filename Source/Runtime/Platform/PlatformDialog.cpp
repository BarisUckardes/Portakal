#include "PlatformDialog.h"

#ifdef PORTAKAL_PLATFORM_WINDOWS
#include <Runtime/Win32/Win32Dialog.h>
typedef Portakal::Win32Dialog PlatformAbstraction;
#endif

namespace Portakal
{
	String PlatformDialog::CreateOpenFileDialog(const String& filter)
	{
		return PlatformAbstraction::CreateOpenFileDialog(filter);
	}
	String PlatformDialog::CreateOpenFolderDialog()
	{
		return PlatformAbstraction::CreateOpenFolderDialog();
	}
}
