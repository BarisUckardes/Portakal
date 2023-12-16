#pragma once

#include <Runtime/Object/ManagerAPI.h>
#include <Runtime/Containers/Array.h>
#include <Runtime/Containers/Guid.h>
#include <Runtime/Containers/String.h>

#include <Editor/Domain/DomainFolder.h>
#include <Editor/Domain/DomainFile.h>

namespace Portakal
{
	class EDITOR_API DomainAPI : public ManagerAPI<DomainAPI>
	{
		friend class DomainModule;

	public:
		FORCEINLINE static DomainFolder* GetRootFolder()
		{
			DomainAPI* api = GetUnderlyingAPI();

			if (api == nullptr)
				return nullptr;

			return api->mRootFolder;
		}

		FORCEINLINE static DomainFile* GetFileFromID(const Guid& id)
		{
			DomainAPI* api = GetUnderlyingAPI();

			if (api == nullptr)
				return nullptr;

			// Check if the file id matches the files in the root folder
			for (DomainFile* file : api->mRootFolder->GetFiles())
			{
				if (file->GetResourceID() == id)
					return file;
			}

			// Check all the subfolders recursively
			for (DomainFolder* folder : api->mRootFolder->GetChildFolders())
			{
				DomainFile* file = api->_GetFileFromIDRecursive(folder, id);

				// If the file is found, return it. Else continue.
				if (file != nullptr)
					return file;
				else continue;
			}

			return nullptr;
		}

	private:
		DomainFile* _GetFileFromIDRecursive(DomainFolder* folder, const Guid& id)
		{
			// Check if the file id matches the files in the folder
			for (DomainFile* file : folder->GetFiles())
			{
				if (file->GetResourceID() == id)
					return file;
			}

			// Check all the subfolders recursively
			for (DomainFolder* childFolder : folder->GetChildFolders())
			{
				DomainFile* file = _GetFileFromIDRecursive(childFolder, id);

				if (file != nullptr)
					return file;
				else continue;
			}

			return nullptr;
		}

	public:
		DomainAPI(const String& folderPath) : mFolderPath(folderPath) {}
		~DomainAPI() = default;

		FORCEINLINE const String& GetFolderPath() const noexcept { return mFolderPath; }

	private:
		DomainFolder* mRootFolder;
		const String mFolderPath;

	};
}
