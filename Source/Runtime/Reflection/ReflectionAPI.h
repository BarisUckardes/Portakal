#pragma once
#include <Runtime/Reflection/Reflection.h>
#include <Runtime/Platform/PlatformLibrary.h>
#include <Runtime/Object/API.h>

namespace Portakal
{
	class ReflectionManifest;
	class RUNTIME_API ReflectionAPI : public API<ReflectionAPI>
	{
		friend class ReflectionModule;
	private:
		struct Entry
		{
			ReflectionManifest* pManifest;
			SharedHeap<PlatformLibrary> pLibrary;
			Assembly* pAssembly;
		};
	public:
		static Assembly* LoadLibraryReflection(const SharedHeap<PlatformLibrary>& pLibrary);
	private:
		ReflectionAPI();
		~ReflectionAPI();

		void Refresh();
	private:
		Array<Entry> mEntries;
	};
}
