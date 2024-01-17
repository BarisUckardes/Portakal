#pragma once
#include <Runtime/Core/Core.h>
#include "SceneComponentFieldType.reflected.h"

namespace Portakal
{
	PENUM();
	enum class RUNTIME_API SceneComponentFieldType : Int64
	{
		EntityComponent,
		Resource
	};
}

