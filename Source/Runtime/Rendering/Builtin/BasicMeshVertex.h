#pragma once
#include <Runtime/Math/Vector3.h>
#include <Runtime/Math/Vector2.h>

namespace Portakal
{
	struct RUNTIME_API BasicMeshVertex
	{
		Vector3F Position;
		Vector3F Normal;
		Vector3F Tangent;
		Vector3F Bitangent;
		Vector2F Uv;
	};
}
