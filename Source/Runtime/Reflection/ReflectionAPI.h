#pragma once
#include <Runtime/Reflection/Reflection.h>
#include <Runtime/Platform/PlatformLibrary.h>
#include <Runtime/Object/API.h>

namespace Portakal
{
	typedef ReflectionManifest* (*GetManifestProc)();

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
		static const Assembly* GetMainAssembly();
		static Array<const Assembly*> GetAssemblies();
	private:
		ReflectionAPI();
		~ReflectionAPI();

		void Invalidate();
		Entry CreateEntry(const SharedHeap<PlatformLibrary>& pLibrary,const bool bMain);
		void DeleteEntry(const Entry& entry,const bool bMain);
		void Normalize(Assembly* pAssembly);
	private:
		Array<Entry> mEntries;
		Entry mMainEntry;
	};
}
