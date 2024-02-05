#include "ProjectModule.h"
#include <Editor/Project/ProjectAPI.h>
#include <Runtime/Platform/PlatformDirectory.h>
#include <Runtime/Platform/PlatformFile.h>
#include <Runtime/Yaml/Yaml.h>

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

		//Check project descriptor path
		const String projectName = PlatformDirectory::GetName(mProjectFolderPath);
		const String projectDescriptorPath = (mProjectFolderPath + "\\" + projectName + ".pproject");

		DEV_LOG("File", *projectDescriptorPath);

		if (!PlatformFile::Exists(projectDescriptorPath))
		{
			DEV_LOG("ProjectModule", "Target project file does not exists!");
			PostQuitRequest("Target project file does not exists!");
			return;
		}

		//Read project file
		String content;
		if (!PlatformFile::Read(projectDescriptorPath, content))
		{
			DEV_LOG("ProjectModule", "Target project file is corrupt");
			PostQuitRequest("Target project file is corrupt");
			return;
		}

		//Deserialize descriptor
		ProjectDescriptor descriptor = {};
		Yaml::ToObject<ProjectDescriptor>(content, &descriptor);
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
	void ProjectModule::OnPreInvalidation()
	{

	}
	void ProjectModule::OnPostInvalidation()
	{

	}
}
