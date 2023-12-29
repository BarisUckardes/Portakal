#pragma once
#include <Runtime/Containers/String.h>
#include <Runtime/Object/API.h>
#include <Editor/Project/ProjectDescriptor.h>

namespace Portakal
{
	class EDITOR_API ProjectAPI : public API<ProjectAPI>
	{
		friend class ProjectModule;
	public:
		static bool SetProject(const ProjectDescriptor& descriptor, const String& folderPath);
		static ProjectDescriptor GetProjectDetails();
		static String GetFolderPath();
	private:
		ProjectAPI() = default;
		~ProjectAPI() = default;
	private:
		ProjectDescriptor mDescriptor;
		String mFolderPath;
	};
}
