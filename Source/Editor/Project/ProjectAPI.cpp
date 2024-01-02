#include "ProjectAPI.h"

namespace Portakal
{
	bool ProjectAPI::_SetProject(const ProjectDescriptor& descriptor, const String& folderPath)
	{
		mDescriptor = descriptor;
		mFolderPath = folderPath;
		
		return true;
	}
	ProjectDescriptor ProjectAPI::GetProjectDetails()
	{
		ProjectAPI* pAPI = GetUnderlyingAPI();
		if (pAPI == nullptr)
			return {};

		return pAPI->mDescriptor;
	}
	String ProjectAPI::GetFolderPath()
	{
		ProjectAPI* pAPI = GetUnderlyingAPI();
		if (pAPI == nullptr)
			return {};

		return pAPI->mFolderPath;
	}
}
