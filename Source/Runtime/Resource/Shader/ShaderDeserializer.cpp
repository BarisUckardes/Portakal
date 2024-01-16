#include "ShaderDeserializer.h"
#include <Runtime/Resource/Shader/ShaderResource.h>

namespace Portakal
{
	ResourceSubObject* ShaderDeserializer::Deserialize(const MemoryView& view)
	{
		ShaderResource* pShader = new ShaderResource();

		//To YAML
		//To descriptor object
		//Compile ShaderResource

		return pShader;
	}
	ResourceSubObject* ShaderDeserializer::DeserializeOptimized(const MemoryView& view)
	{
		return nullptr;
	}
}
