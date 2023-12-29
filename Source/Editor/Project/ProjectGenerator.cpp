#include "ProjectGenerator.h"
#include <Runtime/Platform/PlatformDirectory.h>
#include <Runtime/Platform/PlatformFile.h>
#include <Editor/Project/ProjectDescriptor.h>
#include <Runtime/Yaml/Yaml.h>

namespace Portakal
{
	void ProjectGenerator::GenerateProject(const String& name, const String& folderPath)
	{
		//Validate and create folder path
		if (!PlatformDirectory::Exists(folderPath))
			PlatformDirectory::Create(folderPath);

		//Validate and create project header file 
		const String projectHeaderFilePath = folderPath + "/" + name + ".pproject";
		if (!PlatformFile::Create(projectHeaderFilePath))
		{
			DEV_LOG("ProjectGenerator", "Failed to create project header file");
			return;
		}

		//Create project descriptor upfront
		ProjectDescriptor projectDescriptor;
		projectDescriptor.Name = name;
		projectDescriptor.ID = Guid::Create();
		projectDescriptor.VersionMajor = 0;
		projectDescriptor.VersionMinor = 0;
		projectDescriptor.VersionPatch = 0;

		//Create project paths&files
		const String projectYAML = Yaml::ToYaml<ProjectDescriptor>(&projectDescriptor);
		if (projectYAML == "")
		{
			DEV_LOG("ProjectGenerator", "Invalid project yaml");
			return;
		}

		//Write project descriptor
		if (!PlatformFile::Write(projectHeaderFilePath, projectYAML))
		{
			DEV_LOG("ProjectGenerator", "Failed to write to project header file");
			return;
		}

		//Create sub folders
		PlatformDirectory::Create(folderPath + "/Settings");
		PlatformDirectory::Create(folderPath + "/Domain");
		PlatformDirectory::Create(folderPath + "/Codebase");
		PlatformDirectory::Create(folderPath + "/Cache");

		//Write default domain files


		//Create codebase solutions

	}
}
