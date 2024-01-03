#pragma once
#include <Runtime/Memory/SharedHeap.h>

namespace Portakal
{
	class DomainFile;
	class RUNTIME_API DomainFolder : public Object
	{
		friend class DomainAPI;
	public:
		FORCEINLINE String GetPath() const noexcept
		{
			return mPath;
		}
		FORCEINLINE const Array<SharedHeap<DomainFile>>& GetFiles() const noexcept
		{
			return mFiles;
		}
		FORCEINLINE DomainFolder* GetOwnerFolder() const noexcept
		{
			return mOwnerFolder;
		}
		FORCEINLINE bool IsRootFolder() const noexcept
		{
			return mOwnerFolder == nullptr;
		}
	private:
		DomainFolder(DomainFolder* pOwnerFolder,const String& path);
		~DomainFolder() = default;

		virtual void OnShutdown() override;
	private:
		Array<SharedHeap<DomainFolder>> mFolders;
		Array<SharedHeap<DomainFile>> mFiles;
		DomainFolder* mOwnerFolder;
		String mPath;
	};
}
