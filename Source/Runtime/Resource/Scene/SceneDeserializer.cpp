#include "SceneDeserializer.h"

namespace Portakal
{
	ResourceSubObject* SceneDeserializer::Deserialize(const MemoryView& view,const String& metaData)
	{
		SceneResource* pScene = new SceneResource();

		//TODO: Get scene descriptor and populate the scene

		return pScene;
	}
	ResourceSubObject* SceneDeserializer::DeserializeOptimized(const MemoryView& view,const String& metaData)
	{
		return nullptr;
	}
}
