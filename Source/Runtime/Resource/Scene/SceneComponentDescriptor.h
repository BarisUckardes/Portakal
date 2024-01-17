#pragma once
#include <Runtime/Reflection/Reflection.h>
#include <Runtime/Resource/Scene/SceneComponentFieldDescriptor.h>
#include "SceneComponentDescriptor.reflected.h"

namespace Portakal
{
	PCLASS();
	struct RUNTIME_API SceneComponentDescriptor
	{
		PFIELD();
		String Name;
		PFIELD();
		Guid ID;
		PFIELD();
		String TypeName;
		PFIELD();
		Array<SceneComponentFieldDescriptor> Fields;
	};
}

