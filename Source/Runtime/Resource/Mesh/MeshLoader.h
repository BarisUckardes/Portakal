#pragma once
#include <Runtime/Containers/String.h>
#include <Runtime/Resource/Mesh/MeshLoadResult.h>

namespace Portakal
{
	class RUNTIME_API MeshLoader final
	{
	public:
		MeshLoader() = delete;
		~MeshLoader() = delete;

		static void LoadMesh(const String& path,MeshLoadResult& resultOut);
	};
}
