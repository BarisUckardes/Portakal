#pragma once
#include <Runtime/Reflection/Type.h>

namespace Portakal
{
	/// <summary>
	/// Container of the reflection information per DLL
	/// </summary>
	class RUNTIME_API Assembly final
	{
		friend class Application;
	public:
		FORCEINLINE String GetName() const noexcept
		{
			return mName;
		}
		FORCEINLINE String GetPath() const noexcept
		{
			return mPath;
		}
		FORCEINLINE const Array<Type*>& GetTypes() const noexcept
		{
			return mTypes;
		}
	private:
		Assembly(const String& name, const String& path, const Array<Type*>& types) : mName(name), mPath(path), mTypes(types)
		{

		}
		~Assembly() = default;
	private:
		const String mName;
		const String mPath;
		const Array<Type*> mTypes;
	};
}
