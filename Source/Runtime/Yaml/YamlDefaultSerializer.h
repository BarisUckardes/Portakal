#pragma once
#include <Runtime/Reflection/Reflection.h>

namespace Portakal
{
	class RUNTIME_API YamlDefaultSerializer final
	{
	public:
		static String ToYaml(const void* pObject, const Type* pType);
		static void ToObject(const String& yamlString, void* pObject, const Type* pType);
	public:
		YamlDefaultSerializer() = delete;
		~YamlDefaultSerializer() = delete;
	};
}
