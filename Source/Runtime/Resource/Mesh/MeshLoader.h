#pragma once
#include <Runtime/Containers/String.h>
#include <Runtime/Resource/Mesh/MeshLoadResult.h>
#include <Runtime/Memory/MemoryView.h>

namespace Portakal
{
	class RUNTIME_API MeshLoader final
	{
	public:
		MeshLoader() = delete;
		~MeshLoader() = delete;

		static bool LoadMesh(const String& path,MeshLoadResult& resultOut);
		static bool LoadMeshFromMemory(const MemoryView& memory, MeshLoadResult& resultOut);
	};
}
