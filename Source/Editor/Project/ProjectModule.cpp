#include "ProjectModule.h"
#include <Editor/Project/ProjectAPI.h>
namespace Portakal
{
	void ProjectModule::OnInitialize()
	{
		mAPI = new ProjectAPI();
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
