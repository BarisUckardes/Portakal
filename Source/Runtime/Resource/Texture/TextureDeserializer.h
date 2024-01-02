#pragma once
#include <Runtime/Resource/IResourceDeserializer.h>
#include "TextureDeserializer.reflected.h"

namespace Portakal
{
	PCLASS();
	class RUNTIME_API TextureDeserializer : public IResourceDeserializer
	{
		GENERATE_OBJECT;
	public:
		TextureDeserializer() = default;
		~TextureDeserializer() = default;

	private:
		// Inherited via IResourceDeserializer
		ResourceSubObject* Deserialize(const MemoryView& view) override;
		ResourceSubObject* DeserializeOptimized(const MemoryView& view) override;
	};
}














