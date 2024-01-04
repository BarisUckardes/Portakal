#pragma once
#include <Runtime/Containers/Guid.h>
#include <Runtime/Math/Vector2.h>
#include "GUIWindowDescriptor.reflected.h"

namespace Portakal
{
	PCLASS();
	class EDITOR_API GUIWindowDescriptor
	{
	public:
		GUIWindowDescriptor() = default;
		~GUIWindowDescriptor() = default;

		PFIELD();
		String Name;
		PFIELD();
		Guid ID;
		PFIELD();
		Vector2US mSize;
		PFIELD();
		Vector2US mPosition;
	};
}


























