#pragma once
#include <Runtime/Reflection/Reflection.h>
#include <Runtime/Resource/Scene/SceneComponentFieldType.h>
#include "SceneComponentFieldDescriptor.reflected.h"

namespace Portakal
{
	PCLASS();

	/// <summary>
	/// Descriptor for component fields
	/// </summary>
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

