#pragma once
#include <Editor/Resource/IResourceSerializer.h>
#include "ShaderSerializer.reflected.h"

namespace Portakal
{
	PATTRIBUTE(CustomResourceSerializer,"shader",STRARRAY(".pshader"));
	PCLASS();
	class EDITOR_API ShaderSerializer : public IResourceSerializer
	{
		GENERATE_OBJECT;
	public:
		ShaderSerializer() = default;
		~ShaderSerializer() = default;

	private:
		// Inherited via IResourceSerializer
		void OnShutdown() override;
		void Serialize(DomainFile* pFile,const Object* pObject, MemoryOwnedView** ppView) override;
		void SerializeOptimized(DomainFile* pFile,const Object* pObject, MemoryOwnedView** ppView) override;
	};
}

