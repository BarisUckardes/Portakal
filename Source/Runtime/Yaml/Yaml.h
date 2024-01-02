#pragma once
#include <Runtime/Containers/String.h>
#include <Runtime/Yaml/YamlDefaultSerializer.h>

namespace Portakal
{
	class RUNTIME_API Yaml final
	{
	public:
		template<typename T>
		static void ToObject(const String& yaml, void* pObject)
		{
			YamlDefaultSerializer::ToObject(yaml, pObject, typeof(T));
		}

		template<typename T>
		static String ToYaml(const void* pObject)
		{
			return YamlDefaultSerializer::ToYaml(pObject,typeof(T));
		}

		static bool IsYaml(const String& yaml)
		{
			return true;
		}
	public:
		Yaml() = delete;
		~Yaml() = delete;
	};
}
