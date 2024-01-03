#include "DomainFolder.h"
#include <Runtime/Platform/PlatformDirectory.h>

namespace Portakal
{
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
