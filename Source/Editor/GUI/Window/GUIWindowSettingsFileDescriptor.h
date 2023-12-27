#pragma once

#include <Editor/GUI/Window/GUIWindowDescriptor.h>
#include <Runtime/Containers/Array.h>

namespace Portakal
{
	struct EDITOR_API GUIWindowSettingsFileDescriptor
	{
		Array<GUIWindowDescriptor> Settings;
	};
}