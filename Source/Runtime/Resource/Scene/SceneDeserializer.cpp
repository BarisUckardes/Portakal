#include "SceneDeserializer.h"

namespace Portakal
{
	ResourceSubObject* SceneDeserializer::Deserialize(const MemoryView& view)
	{
		SceneResource* pScene = new SceneResource();

		//TODO: Get scene descriptor and populate the scene

		return pScene;
	}
	ResourceSubObject* SceneDeserializer::DeserializeOptimized(const MemoryView& view)
	{
		return nullptr;
	}
}
