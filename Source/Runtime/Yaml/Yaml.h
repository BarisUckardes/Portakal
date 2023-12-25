#pragma once
#include <Runtime/Containers/String.h>

namespace Portakal
{
	class RUNTIME_API Yaml final
	{
	public:
		template<typename T>
		static void ToObject(const String& yaml, void* pObject)
		{

		}

		template<typename T>
		static String ToYaml(const void* pObject)
		{

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
