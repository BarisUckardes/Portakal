#pragma once
#include <Runtime/Reflection/Reflection.h>

namespace Portakal
{
	class RUNTIME_API ReflectionManifest final
	{
	public:
		ReflectionManifest(const String& name, const Array<Type*>& types) :mTypes(types), mName(name)
		{

		}
		~ReflectionManifest();
	private:
		const Array<Type*> mTypes;
		const String mName;
	};
}
