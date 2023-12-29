#pragma once
#include <Runtime/Application/ApplicationModule.h>

namespace Portakal
{
	class ProjectAPI;
	class EDITOR_API ProjectModule : public ApplicationModule
	{
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
