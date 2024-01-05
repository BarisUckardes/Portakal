#include "DomainFolder.h"
#include <Runtime/Platform/PlatformDirectory.h>

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
	
	void DomainFolder::OnShutdown()
	{
		//Shutdown files

		//Shutdown folders
		for (const SharedHeap<DomainFolder>& pFolder : mFolders)
			pFolder.Shutdown();
		mFolders.Clear();
	}
}
