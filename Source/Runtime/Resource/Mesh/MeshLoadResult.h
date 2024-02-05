#pragma once
#include <Runtime/Resource/Mesh/SubMeshResult.h>

namespace Portakal
{
	/// <summary>
	/// Result of the mesh loader
	/// </summary>
	struct RUNTIME_API MeshLoadResult
	{
		Array<SubMeshResult> Meshes;
	};
}

