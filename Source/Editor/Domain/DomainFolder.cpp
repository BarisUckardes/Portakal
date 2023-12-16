#include "DomainFolder.h"

#include <Editor/Domain/DomainFile.h>

#include <Runtime/Platform/PlatformDirectory.h>
#include <Runtime/Platform/PlatformFile.h>
#include <Runtime/Platform/PlatformMessage.h>

namespace Portakal
{
	DomainFolder::DomainFolder(const String& pAbsolutePath, DomainFolder* pParentFolder) : mParentFolder(pParentFolder), mAbsolutePath(pAbsolutePath), mIsValid(false)
	{
		// Check if the path is valid
		if (!PlatformDirectory::DoesExist(pAbsolutePath))
		{
			PlatformMessage::ShowMessageBox("DomainFolder", "The path is missing: " + pAbsolutePath);
			return;
		}
		else
			mIsValid = true;

		// Get all the descriptor files in this folder
		Array<String> files;
		PlatformDirectory::GetFileNamesViaExtension(pAbsolutePath + "\\", ".rfd", files);
		for (const String& file : files)
		{
			const String& filePath = file;
			DomainFile* domainFile = new DomainFile(filePath, this);

			if (domainFile->IsValid())
				mFiles.Add(domainFile);
			else
				delete domainFile;
		}

		// Get all the folders in this folder
		Array<String> folders;
		PlatformDirectory::GetFolderNames(pAbsolutePath + "\\", folders);
		for (const String& folder : folders)
		{
			const String& folderPath = folder;

			DomainFolder* domainFolder = new DomainFolder(folderPath, this);

			if (domainFolder->IsValid())
				mChildFolders.Add(domainFolder);
			else
				delete domainFolder;
		}
	}

	DomainFolder::~DomainFolder()
	{
		for (DomainFile* file : mFiles)
			delete file;

		for (DomainFolder* folder : mChildFolders)
			delete folder;
	}
}
