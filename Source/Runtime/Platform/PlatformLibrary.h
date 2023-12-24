#pragma once
#include <Runtime/Memory/SharedHeap.h>

namespace Portakal
{
	typedef void* PlatformLibraryHandle;
	class RUNTIME_API PlatformLibrary : public Object
	{
	public:
		static SharedHeap<PlatformLibrary> Load(const String& path);
		static SharedHeap<PlatformLibrary> GetCurrent();
	public:
		PlatformLibrary(const String& path,const bool bMain) : mPath(path),mMain(bMain)
		{

		}
		~PlatformLibrary() = default;

		FORCEINLINE String GetPath() const noexcept
		{
			return mPath;
		}
		FORCEINLINE bool IsMain() const noexcept
		{
			return mMain;
		}

		virtual PlatformLibraryHandle GetSymbol(const String& name) = 0;
	private:
		const String mPath;
		const bool mMain;
	};
}
