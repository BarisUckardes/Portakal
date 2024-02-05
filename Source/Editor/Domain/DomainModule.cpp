#include "DomainModule.h"
#include <Editor/Domain/DomainAPI.h>
#include <Editor/Project/ProjectAPI.h>
#include <Runtime/Platform/PlatformDirectory.h>

namespace Portakal
{
	void DomainModule::OnInitialize()
	{
		//Validate project folder
		const String projectFolderPath = ProjectAPI::GetFolderPath();
		if (!PlatformDirectory::Exists(projectFolderPath))
		{
			DEV_LOG("DomainModule", "Invalid project path");
			PostQuitRequest("Invalid project path");
			return;
		}

		//Validate domain folder
		const String domainFolderPath = projectFolderPath + "\\Domain";
		if (!PlatformDirectory::Exists(domainFolderPath))
		{
			DEV_LOG("DomainModule", "Missing Domain folder, creating a default one!");
			if (!PlatformDirectory::Create(domainFolderPath))
			{
				DEV_LOG("DomainModule", "Failed to create Domain folder!");
				PostQuitRequest("Failed to create Domain folder!");
				return;
			}
			return;
		}

		//Create domain
		mAPI = new DomainAPI(domainFolderPath);
	}
	void DomainModule::OnFinalize()
	{
		delete mAPI;
		mAPI = nullptr;
	}
	void DomainModule::OnTick()
	{
	}
	void DomainModule::OnPreInvalidation()
	{

	}
	void DomainModule::OnPostInvalidation()
	{

	}
}
