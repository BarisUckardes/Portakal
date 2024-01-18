#pragma once
#include <Runtime/Math/Vector3.h>
#include <Runtime/Math/Vector2.h>
#include <Runtime/Containers/Array.h>

namespace Portakal
{
	struct RUNTIME_API MeshLoadResult
	{
		Array<Vector3F> Positions;
		Array<Vector3F> Normals;
		Array<Vector2F> Uvs;
	};
}

