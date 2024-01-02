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
		ProjectModule() : mAPI(nullptr)
		{

		}

		~ProjectModule() = default;
	private:
		void OnInitialize() override;
		void OnFinalize() override;
		void OnTick() override;
	private:
		ProjectAPI* mAPI;
	};
}




























