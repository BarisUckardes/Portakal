#pragma once
#include <Editor/GUI/Window/GUIWindowDescriptor.h>
#include <Runtime/Containers/Array.h>
#include "GUIWindowSettings.reflected.h"

namespace Portakal
{
	PCLASS();
	struct EDITOR_API GUIWindowSettings final
	{
		PFIELD();
		Array<GUIWindowDescriptor> Settings;
	};
}



































