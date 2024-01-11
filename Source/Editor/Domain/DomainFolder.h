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
		FORCEINLINE const Array<SharedHeap<DomainFolder>>& GetFolders() const noexcept
		{
			return mFolders;
		}
		FORCEINLINE DomainFolder* GetOwnerFolder() const noexcept
		{
			return mOwnerFolder;
		}
		FORCEINLINE Bool8 IsRootFolder() const noexcept
		{
			return mOwnerFolder == nullptr;
		}

		SharedHeap<DomainFolder> CreateFolder(const String& name);
		void Delete();
		void Invalidate();
	private:
		DomainFolder(DomainFolder* pOwnerFolder,const String& path);
		~DomainFolder() = default;

		void _OnSubFolderDeleted(const DomainFolder* pFolder);
		void _OnSubFileDeleted(const DomainFile* pFile);
		virtual void OnShutdown() override;
	private:
		Array<SharedHeap<DomainFolder>> mFolders;
		Array<SharedHeap<DomainFile>> mFiles;
		DomainFolder* mOwnerFolder;
		String mPath;
	};
}
