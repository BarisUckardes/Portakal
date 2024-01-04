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
		static ProjectDescriptor GetProjectDetails();
		static String GetFolderPath();
	private:
		Bool8 _SetProject(const ProjectDescriptor& descriptor, const String& folderPath);
	private:
		ProjectAPI() = default;
		~ProjectAPI() = default;
	private:
		ProjectDescriptor mDescriptor;
		String mFolderPath;
	};
}
