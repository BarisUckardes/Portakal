#include "MeshLoader.h"
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

namespace Portakal
{
	void MeshLoader::LoadMesh(const String& path, MeshLoadResult& resultOut)
	{
		//Get importer
		Assimp::Importer importer;

		//Read
		const aiScene* pScene = importer.ReadFile(*path, 
			aiProcess_CalcTangentSpace |
			aiProcess_Triangulate |
			aiProcess_JoinIdenticalVertices |
			aiProcess_GenNormals | 
			aiProcess_FlipUVs | 
			aiProcess_SortByPType
			);

		if (pScene == nullptr)
		{
			DEV_LOG("MeshLoader", "Failed to import");
			return;
		}

		//Get positions
		for (UInt32 meshIndex = 0; meshIndex < pScene->mNumMeshes; meshIndex++)
		{
			SubMeshResult subMesh = {};
			aiMesh* pMesh = pScene->mMeshes[meshIndex];

			//Get position
			if (pMesh->HasPositions())
			{
				for (UInt32 posIndex = 0; posIndex < pMesh->mNumVertices; posIndex++)
				{
					const aiVector3D pos = pMesh->mVertices[posIndex];
					subMesh.Positions.Add({ pos.x,pos.y,pos.z });
				}
			}

			//Get normals
			if (pMesh->HasNormals())
			{
				for (UInt32 normalIndex = 0; normalIndex < pMesh->mNumVertices; normalIndex++)
				{
					const aiVector3D normal = pMesh->mNormals[normalIndex];
					subMesh.Normals.Add({ normal.x,normal.y,normal.z });
				}
			}

			//Get tangents
			if (pMesh->HasTangentsAndBitangents())
			{
				for (UInt32 tangentIndex = 0; tangentIndex < pMesh->mNumVertices; tangentIndex++)
				{
					const aiVector3D tangent = pMesh->mTangents[tangentIndex];
					const aiVector3D bitangent = pMesh->mBitangents[tangentIndex];

					subMesh.Tangents.Add({ tangent.x,tangent.y,tangent.z });
					subMesh.Bitangents.Add({ bitangent.x,bitangent.y,bitangent.z });
				}
			}

			//Get uvs
			for (Byte uvSectionIndex = 0; uvSectionIndex < AI_MAX_NUMBER_OF_TEXTURECOORDS; uvSectionIndex++)
			{
				if (pMesh->HasTextureCoords(uvSectionIndex))
				{
					Array<Vector2F> uvs;
					for (UInt32 uvIndex = 0; uvIndex < pMesh->mNumVertices; uvIndex++)
					{
						const aiVector3D uv = pMesh->mTextureCoords[uvSectionIndex][uvIndex];
						uvs.Add({ uv.x,uv.y });
					}
					subMesh.Uvs.Add(uvs);
				}
			}

			//Get colors
			for (Byte colorSectionIndex = 0; colorSectionIndex < AI_MAX_NUMBER_OF_COLOR_SETS; colorSectionIndex++)
			{
				if (pMesh->HasVertexColors(colorSectionIndex))
				{
					Array<Vector4F> colors;
					for (UInt32 colorIndex = 0; colorIndex < pMesh->mNumVertices; colorIndex++)
					{
						const aiColor4D color = pMesh->mColors[colorSectionIndex][colorIndex];
						colors.Add({ color.r,color.g,color.b,color.a });
					}
					subMesh.Colors.Add(colors);
				}
			}

			//Get indexes
			for (UInt32 i = 0; i < pMesh->mNumFaces; i++)
			{
				const aiFace& face = pMesh->mFaces[i];
				subMesh.Indexes.Add(face.mIndices[0]);
				subMesh.Indexes.Add(face.mIndices[1]);
				subMesh.Indexes.Add(face.mIndices[2]);
			}

			resultOut.Meshes.Add(subMesh);
		}
	}
}
