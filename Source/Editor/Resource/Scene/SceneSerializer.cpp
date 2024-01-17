#include "SceneSerializer.h"
#include <Runtime/Yaml/Yaml.h>
namespace Portakal
{
	void SceneSerializer::Serialize(DomainFile* pFile,const Object* pObject, MemoryOwnedView** ppView)
	{
		const SceneResource* pScene = (const SceneResource*)pObject;
		SceneDescriptor descriptor = {};
		pScene->GenerateDescriptor(descriptor);
		
		const String yamlContent = Yaml::ToYaml<SceneDescriptor>(&descriptor);

		*ppView = new MemoryOwnedView(yamlContent.GetSource(),yamlContent.GetSize());
	}
	void SceneSerializer::SerializeOptimized(DomainFile* pFile,const Object* pObject, MemoryOwnedView** ppView)
	{

	}
}
