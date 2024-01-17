#include "DomainAPI.h"
#include <Editor/Domain/DomainFile.h>
#include <Editor/Domain/DomainFolder.h>

namespace Portakal
{
	void DomainAPI::Invalidate()
	{
		DomainAPI* pAPI = GetUnderlyingAPI();
		if (pAPI == nullptr)
			return;

		//TODO:
	}
	SharedHeap<DomainFolder> DomainAPI::GetRootFolder()
	{
		DomainAPI* pAPI = GetUnderlyingAPI();
		if (pAPI == nullptr)
			return nullptr;

		return pAPI->mRootFolder;
	}
	SharedHeap<DomainFile> GetFileInternal(const SharedHeap<DomainFolder>& pFolder,const String& name)
	{
		//First check files
		const Array<SharedHeap<DomainFile>>& files = pFolder->GetFiles();
		for (const SharedHeap<DomainFile>& pFile : files)
		{
			if (pFile->GetName() == name)
				return pFile;
		}

		//Check other folders
		const Array<SharedHeap<DomainFolder>> folders = pFolder->GetFolders();
		for (const SharedHeap<DomainFolder>& pFolder : folders)
		{
			const SharedHeap<DomainFile> pFile = GetFileInternal(pFolder, name);
			if (!pFile.IsShutdown())
				return pFile;
		}

		return nullptr;
	}
	SharedHeap<DomainFile> DomainAPI::GetFile(const String& name)
	{
		DomainAPI* pAPI = GetUnderlyingAPI();
		if (pAPI == nullptr)
			return nullptr;

		return GetFileInternal(pAPI->mRootFolder, name);
	}
	SharedHeap<DomainFile> DomainAPI::GetFile(const Guid& id)
	{
		return SharedHeap<DomainFile>();
	}
	DomainAPI::DomainAPI(const String& folderPath) : mFolderPath(folderPath)
	{
		//Create root folder
		mRootFolder = new DomainFolder(nullptr, folderPath);
	}
	DomainAPI::~DomainAPI()
	{

	}
}
