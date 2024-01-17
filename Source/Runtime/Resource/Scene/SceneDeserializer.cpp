#include "SceneDeserializer.h"
#include <Runtime/Yaml/Yaml.h>
#include <Runtime/Reflection/ReflectionAPI.h>

namespace Portakal
{
	ResourceSubObject* SceneDeserializer::Deserialize(const MemoryView& view,const String& metaData)
	{
		SceneResource* pScene = new SceneResource();

		//TODO: Get scene descriptor and populate the scene
		const String yamlContent((char*)view.GetMemory(), view.GetSize());
		SceneDescriptor descriptor = {};
		Yaml::ToObject<SceneDescriptor>(yamlContent, &descriptor);

		//Create aspects
		for (const String& aspectName : descriptor.Aspects)
		{
			const Type* pType = ReflectionAPI::GetType(aspectName);
			if (pType == nullptr)
				continue;

			//Create
			pScene->GetScene()->CreateAspect(pType);
		}
		return pScene;
	}
	ResourceSubObject* SceneDeserializer::DeserializeOptimized(const MemoryView& view,const String& metaData)
	{
		return nullptr;
	}
}
