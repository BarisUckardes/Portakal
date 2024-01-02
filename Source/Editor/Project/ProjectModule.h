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
		void OnInitialize() override;
		void OnFinalize() override;
		void OnTick() override;
	private:
		const String mProjectFolderPath;
		ProjectAPI* mAPI;
	};
}




























