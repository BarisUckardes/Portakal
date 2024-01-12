#pragma once
#include <Runtime/Containers/Guid.h>
#include <Runtime/Math/Vector2.h>
#include "GUIWindowDescriptor.reflected.h"
#include <Editor/GUI/GUIDirection.h>

namespace Portakal
{
	PCLASS();
	struct EDITOR_API GUIWindowDescriptor
	{
		PFIELD();
		String Name;
		PFIELD();
		Guid ID;
		PFIELD();
		Vector2US Size;
		PFIELD();
		Vector2US Position;
		PFIELD();
		GUIDirection DockDirection;
	};
}






































































