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

		FORCEINLINE const Array<Type*>& GetTypes() const noexcept
		{
			return mTypes;
		}
		FORCEINLINE String GetName() const noexcept
		{
			return mName;
		}
	private:
		const Array<Type*> mTypes;
		const String mName;
	};
}
