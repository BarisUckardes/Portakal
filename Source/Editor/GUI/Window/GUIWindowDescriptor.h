#pragma once

#include <Runtime/Containers/String.h>
#include <Runtime/Math/Vector2.h>
#include <Runtime/Containers/Guid.h>

#include <Editor/GUI/GUIDirection.h>

namespace Portakal
{
	struct EDITOR_API GUIWindowDescriptor
	{
		String Name;
		Guid ID;
		Vector2UI Size;
		Vector2I Position;
		GUIDirection DockState;
	};

}
