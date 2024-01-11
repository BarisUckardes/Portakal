#include "DomainFolder.h"
#include <Runtime/Platform/PlatformDirectory.h>
#include <Editor/Domain/DomainFile.h>

namespace Portakal
{
	SharedHeap<DomainFolder> DomainFolder::CreateFolder(const String& name)
	{
		//Check if folder already exists
		const String folderPath = mPath + "\\" + name;
		if (PlatformDirectory::Exists(folderPath))
		{
			DEV_LOG("DomainFolder", "This folder already exists!");
			return nullptr;
		}

		//Create physical aspect
		if (!PlatformDirectory::Create(folderPath))
		{
			DEV_LOG("DomainFolder", "Failed to create the folder");
			return nullptr;
		}

		//Create domain folder
		SharedHeap<DomainFolder> pFolder = new DomainFolder(this, folderPath);

		//Register
		mFolders.Add(pFolder);

		return pFolder;
	}
	void DomainFolder::Delete()
	{
		if (IsShutdown())
			return;

		//Delete the physical aspect of the folder
		if (!PlatformDirectory::Delete(mPath))
		{
			DEV_LOG("DomainFolder", "Failed to delete the folder!");
			return;
		}

		//Shutdown
		Shutdown();
	}
	DomainFolder::DomainFolder(DomainFolder* pOwnerFolder, const String& path) : mOwnerFolder(pOwnerFolder),mPath(path)
	{
		//Set name
		const String name = PlatformDirectory::GetName(path);
		SetName(name);
		DEV_LOG("DomainFolder", "Found folder: %s", *path);

		//Search for files

		//Search for folders
		Array<String> folders;
		PlatformDirectory::GetFolderNames(path + "\\", folders);
		for (const String& folderPath : folders)
			mFolders.Add(new DomainFolder(this, folderPath));
	}
	
	void DomainFolder::Invalidate()
	{
		//Get directories and check if there's missing or new folders
		Array<String> folders;
		if (!PlatformDirectory::GetFolderNames(mPath,folders))
		{
			DEV_LOG("DomainFolder", "Failed to get folder names!");
			return;
		}

		//Look for new folders
		for (const String& folder : folders)
		{
			bool bNewFolder = true;
			for (const SharedHeap<DomainFolder>& pFolder : mFolders)
			{
				if (pFolder->GetPath() == folder)
				{
					bNewFolder = false;
					break;
				}
			}

			if (bNewFolder)
			{
				SharedHeap<DomainFolder> pFolder = new DomainFolder(this, folder);
				mFolders.Add(pFolder);
			}
		}

		//Look for missing folders
		for (const SharedHeap<DomainFolder>& pFolder : mFolders)
		{
			const String path = pFolder->GetPath();

			bool bMissingFolder = true;
			for (const String& folder : folders)
			{
				if (path == folder)
				{
					bMissingFolder = false;
					break;
				}
			}

			if (bMissingFolder)
			{
				pFolder.Shutdown();
				mFolders.Remove(pFolder);
			}
		}

		//Get files and check if there's missing or new files
		Array<String> files;
		if (!PlatformDirectory::GetFileNamesViaExtension(mPath,".pfd", files))
		{
			DEV_LOG("DomainFolder", "Failed to get file names");
			return;
		}

		//Look for new files
		for (const String& file : files)
		{
			bool bNewFile = true;
			for (const SharedHeap<DomainFile>& pFile : mFiles)
			{
				if (pFile->GetDescriptorPath() == file)
				{
					bNewFile = false;
					break;
				}
			}

			if (bNewFile)
			{
				SharedHeap<DomainFile> pFile = new DomainFile(this, file);
				mFiles.Add(pFile);
			}
		}

		//Look for missing files
		for (const SharedHeap<DomainFile>& pFile : mFiles)
		{
			const String path = pFile->GetDescriptorPath();

			bool bMissingFile = true;
			for (const String& file : files)
			{
				if (path == file)
				{
					bMissingFile = false;
					break;
				}
			}

			if (bMissingFile)
			{
				pFile.Shutdown();
				mFiles.Remove(pFile);
			}
		}

		//Check if file source contents are changed
		for (const SharedHeap<DomainFile>& pFile : mFiles)
		{
			if (pFile->UpdateLastChangeTimeCheck()) // file seems to be edited
				pFile->Invalidate();
		}
	}

	void DomainFolder::_OnSubFolderDeleted(const DomainFolder* pTargetFolder)
	{
		mFolders.Remove(pTargetFolder);
	}

	void DomainFolder::_OnSubFileDeleted(const DomainFile* pFile)
	{
		mFiles.Remove(pFile);
	}

	void DomainFolder::OnShutdown()
	{
		//First notify the owner folder that this folder is removed
		if (mOwnerFolder != nullptr)
		{
			mOwnerFolder->_OnSubFolderDeleted(this);
		}

		//Shutdown files
		for (const SharedHeap<DomainFile>& pFile : mFiles)
			pFile.Shutdown();

		//Shutdown folders
		for (const SharedHeap<DomainFolder>& pFolder : mFolders)
			pFolder.Shutdown();

		mFolders.Clear();
	}
}
