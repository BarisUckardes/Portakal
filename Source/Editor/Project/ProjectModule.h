#pragma once
#include <Runtime/Application/ApplicationModule.h>
#include "ProjectModule.reflected.h"

namespace Portakal
{
	class ProjectAPI;
	PCLASS();
	class EDITOR_API ProjectModule : public ApplicationModule
	{
		GENERATE_OBJECT;
	public:
		ProjectModule(const String& projectFolderPath) : mProjectFolderPath(projectFolderPath),mAPI(nullptr)
		{

		}
		ProjectModule() : mAPI(nullptr)
		{

		}

		~ProjectModule() = default;
	private:
		virtual void OnInitialize() override;
		virtual void OnFinalize() override;
		virtual void OnTick() override;
		virtual void OnPreInvalidation() override;
		virtual void OnPostInvalidation() override;
	private:
		const String mProjectFolderPath;
		ProjectAPI* mAPI;
	};
}










































































































































































































