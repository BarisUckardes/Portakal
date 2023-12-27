#pragma once

#include <Runtime/Containers/String.h>
#include <Runtime/Math/Vector/Vectors.h>
#include <Runtime/Containers/Guid.h>

#include <Editor/GUI/GUIDirection.h>

namespace Roveldo
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
