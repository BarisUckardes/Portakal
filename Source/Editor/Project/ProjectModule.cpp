#include "ProjectModule.h"
#include <Editor/Project/ProjectAPI.h>
#include <Runtime/Platform/PlatformDirectory.h>

namespace Portakal
{
	void ProjectModule::OnInitialize()
	{
		//Initialize API
		mAPI = new ProjectAPI();

		//Check if given project path is a valid directory
		if (!PlatformDirectory::Exists(mProjectFolderPath))
		{
			DEV_LOG("ProjectModule", "Failed to find the target project folder!");
			PostQuitRequest("Invalid project folder path!");
			return;
		}

		//Set project path
		ProjectDescriptor descriptor = {};
		mAPI->_SetProject(descriptor, mProjectFolderPath);
	}
	void ProjectModule::OnFinalize()
	{
		delete mAPI;
		mAPI = nullptr;
	}
	void ProjectModule::OnTick()
	{

	}
}
