#pragma once
#include <Runtime/Reflection/Reflection.h>
#include <Runtime/Resource/Scene/SceneComponentDescriptor.h>
#include "SceneEntityDescriptor.reflected.h"
#include <Runtime/Containers/Guid.h>

namespace Portakal
{
	PCLASS();
	struct RUNTIME_API SceneEntityDescriptor
	{
		PFIELD();
		String Name;
		PFIELD();
		Guid ID;
		PFIELD();
		Array<SceneComponentDescriptor> Components;
	};
}

