#pragma once
#include <Runtime/Core/Core.h>
#include "SceneComponentFieldType.reflected.h"

namespace Portakal
{
	PENUM();

	/// <summary>
	/// Available fields types a component can have
	/// </summary>
	enum class RUNTIME_API SceneComponentFieldType : Int64
	{
		EntityComponent,
		Resource
	};
}

