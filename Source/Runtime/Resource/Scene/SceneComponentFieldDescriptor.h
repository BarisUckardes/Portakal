#pragma once
#include <Runtime/Reflection/Reflection.h>
#include <Runtime/Resource/Scene/SceneComponentFieldType.h>
#include "SceneComponentFieldDescriptor.reflected.h"

namespace Portakal
{
	PCLASS();
	struct RUNTIME_API SceneComponentFieldDescriptor
	{
		PFIELD();
		String FieldName;
		PFIELD();
		FieldMode Mode;
		PFIELD();
		String FieldValue;
	};
}

