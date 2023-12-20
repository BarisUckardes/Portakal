#include "Win32Icon.h"
#include <Windows.h>
#include <Runtime/Graphics/Texture/TextureLoader.h>

namespace Portakal
{
	bool Win32Icon::LoadIconFromPath(const String& path, const PlatformWindow* pTargetWindow)
	{
		LoadImageA(GetModuleHandle(NULL), *path, IMAGE_ICON, 256, 256, LR_DEFAULTCOLOR);
		return false;
	}
}
