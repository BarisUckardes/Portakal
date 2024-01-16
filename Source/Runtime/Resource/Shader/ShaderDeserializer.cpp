#include "ShaderDeserializer.h"
#include <Runtime/Resource/Shader/ShaderResource.h>

namespace Portakal
{
	ResourceSubObject* ShaderDeserializer::Deserialize(const MemoryView& view,const String& metaData)
	{
		ShaderResource* pShader = new ShaderResource();

		//To YAML
		//To descriptor object
		//Compile ShaderResource

		return pShader;
	}
	ResourceSubObject* ShaderDeserializer::DeserializeOptimized(const MemoryView& view,const String& metaData)
	{
		return nullptr;
	}
}
