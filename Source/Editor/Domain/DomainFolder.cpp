#include "DomainFolder.h"

namespace Portakal
{
	DomainFolder::DomainFolder(const SharedHeap<DomainFolder>& pOwnerFolder, const String& path) : mOwnerFolder(pOwnerFolder),mPath(path)
	{
		//Search for files

		//Search for folders
	}
	
	void DomainFolder::OnShutdown()
	{
		//Shutdown files

		//Shutdown folders
	}
}
