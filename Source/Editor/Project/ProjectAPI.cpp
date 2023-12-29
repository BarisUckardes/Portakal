#include "ProjectAPI.h"

namespace Portakal
{
	bool ProjectAPI::SetProject(const ProjectDescriptor& descriptor, const String& folderPath)
	{
		ProjectAPI* pAPI = GetUnderlyingAPI();
		if (pAPI == nullptr)
			return false;

		pAPI->mDescriptor = descriptor;
		pAPI->mFolderPath = folderPath;
		
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
