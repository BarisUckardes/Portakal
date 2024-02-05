#pragma once
#include <Runtime/Math/Vector3.h>
#include <Runtime/Math/Vector2.h>
#include <Runtime/Math/Vector4.h>
#include <Runtime/Containers/Array.h>

namespace Portakal
{
	/// <summary>
	/// A loaded sub mesh result
	/// </summary>
	struct RUNTIME_API SubMeshResult
	{
		Array<Vector3F> Positions;
		Array<Vector3F> Normals;
		Array<Vector3F> Tangents;
		Array<Vector3F> Bitangents;
		Array<Array<Vector4F>> Colors;
		Array<Array<Vector2F>> Uvs;
		Array<UInt32> Indexes;
	};
}
