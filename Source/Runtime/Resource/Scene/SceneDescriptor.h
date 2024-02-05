#pragma once
#include <Runtime/World/Scene.h>
#include <Runtime/Resource/Scene/SceneEntityDescriptor.h>
#include "SceneDescriptor.reflected.h"

namespace Portakal
{
	PCLASS();

	/// <summary>
	/// Scene descriptor
	/// </summary>
	struct RUNTIME_API SceneDescriptor
	{
		PFIELD();
		Array<SceneEntityDescriptor> Entities;
		PFIELD();
		Array<Guid> Resources;
		PFIELD();
		Array<String> Aspects;
	};
}

