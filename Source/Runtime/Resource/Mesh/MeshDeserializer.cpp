#include "MeshDeserializer.h"
#include <Runtime/Resource/Mesh/MeshLoader.h>
#include <Runtime/Rendering/Builtin/BasicMeshVertex.h>

namespace Portakal
{
	ResourceSubObject* MeshDeserializer::Deserialize(const MemoryView& view, const String& metaData)
	{
		//Load mesh from memory
		MeshLoadResult result = {};
		if (!MeshLoader::LoadMeshFromMemory(view, result))
			return nullptr;

		//Create mesh
		MeshResource* pMesh = new MeshResource();

		//Set memory profile
		pMesh->SetMemoryProfile(nullptr, nullptr, true);

		//Allocate submeshes
		UInt32 subMeshIndex = 0;
		for (SubMeshResult submesh : result.Meshes)
		{
			//Allocate
			pMesh->AllocateSubMesh(submesh.Positions.GetSize(), sizeof(BasicMeshVertex), submesh.Indexes.GetSize(), sizeof(UInt32));

			//Update
			Array<BasicMeshVertex> vertexes;
			for (UInt32 i = 0; i < submesh.Positions.GetSize(); i++)
			{
				BasicMeshVertex vertex = {};
				vertex.Position = submesh.Positions[i];
				vertex.Normal = submesh.Normals[i];
				vertex.Tangent = submesh.Tangents[i];
				vertex.Bitangent = submesh.Bitangents[i];
				vertex.Uv = submesh.Uvs[0][i];
				vertexes.Add(vertex);
			}
			pMesh->UpdateSubMeshVertexes(subMeshIndex,{vertexes.GetData(),vertexes.GetSize()*sizeof(BasicMeshVertex)},0);
			pMesh->UpdateSubMeshIndexes(subMeshIndex, { submesh.Indexes.GetData(),submesh.Indexes.GetSize() * sizeof(UInt32) }, 0);

			//Increment index
			subMeshIndex++;
		}

		return pMesh;
	}
	ResourceSubObject* MeshDeserializer::DeserializeOptimized(const MemoryView& view, const String& metaData)
	{
		return nullptr;
	}
}
