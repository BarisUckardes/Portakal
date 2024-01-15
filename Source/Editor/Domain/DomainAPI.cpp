#include "DomainAPI.h"

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
	DomainAPI::DomainAPI(const String& folderPath) : mFolderPath(folderPath)
	{
		//Create root folder
		mRootFolder = new DomainFolder(nullptr, folderPath);
	}
	DomainAPI::~DomainAPI()
	{

	}
}
