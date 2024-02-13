#pragma once
#include <Runtime/Containers/String.h>
#include <Runtime/Yaml/YamlDefaultSerializer.h>
#include <Runtime/Memory/SharedHeap.h>

namespace Portakal
{
	class RUNTIME_API Yaml final
	{
	public:

		/// <summary>
		/// Converts target yaml string into object
		/// </summary>
		/// <typeparam name="T"></typeparam>
		/// <param name="yaml"></param>
		/// <param name="pObject"></param>
		template<typename T>
		static void ToObject(const String& yaml, void* pObject)
		{
			YamlDefaultSerializer::ToObject(yaml, pObject, typeof(T));
		}

		/// <summary>
		/// Converts target object into yaml string
		/// </summary>
		/// <typeparam name="T"></typeparam>
		/// <param name="pObject"></param>
		/// <returns></returns>
		template<typename T>
		static String ToYaml(const void* pObject)
		{
			return YamlDefaultSerializer::ToYaml(pObject,typeof(T));
		}

		static String ToYaml(Type* pType,const void* pObject)
		{
			return YamlDefaultSerializer::ToYaml(pObject,pType);
		}

		static Bool8 IsYaml(const String& yaml)
		{
			return YamlDefaultSerializer::IsYaml(yaml);
		}
	public:
		Yaml() = delete;
		~Yaml() = delete;
	};
}
