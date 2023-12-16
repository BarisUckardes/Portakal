#pragma once
#include <Runtime/Containers/Array.h>
#include <Runtime/Containers/String.h>

namespace Portakal
{
	class DomainFile;

	/**
	 * @class DomainFolder
	 * @brief The Folder descriptor in the Editor's Content Browser.
	 */
	class EDITOR_API DomainFolder final
	{
	public:
		DomainFolder(const String& pAbsolutePath, DomainFolder* pParentFolder = nullptr);
		~DomainFolder();

		DomainFolder* GetParentFolder() const { return mParentFolder; }
		const Array<DomainFolder*>& GetChildFolders() const noexcept { return mChildFolders; }
		const Array<DomainFile*>& GetFiles() const noexcept { return mFiles; }
		const String& GetFolderName() const noexcept { return mFolderName; }
		const String& GetAbsolutePath() const noexcept { return mAbsolutePath; }
		bool IsRootFolder() const noexcept { return mParentFolder == nullptr; }
		bool IsValid() const noexcept { return mIsValid; }

		void SetFolderName(const String& pFolderName);
		void AddFolder(DomainFolder* pFolder);
		void RemoveFolder(DomainFolder* pFolder);
		void AddFile(DomainFile* pFile);
		void RemoveFile(DomainFile* pFile);
		void MoveFolderTo(DomainFolder* pNewParentFolder);
		void CopyFolderTo(DomainFolder* pNewParentFolder);

	private:
		DomainFolder* mParentFolder;
		Array<DomainFolder*> mChildFolders;
		Array<DomainFile*> mFiles;
		String mFolderName;
		String mAbsolutePath;
		bool mIsValid;
	};
}
