#pragma once
#include <Runtime/Reflection/Reflection.h>

namespace Portakal
{
	class ReflectionManifest;
	class RUNTIME_API ReflectionAPI
	{
	public:
		static Array<Assembly*> GetAssemblies();
		static Array<Type*> GetSubTypes(const Type* pTargetType);
		static Type* GetType(const String& name);
	private:
		ReflectionAPI() = delete;
		~ReflectionAPI() = delete;
	};
}