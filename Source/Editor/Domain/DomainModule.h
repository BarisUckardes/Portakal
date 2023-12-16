#pragma once
#include <Runtime/Application/ApplicationModule.h>

namespace Portakal
{
	class DomainAPI;

	class EDITOR_API DomainModule : public ApplicationModule
	{
		GENERATED_APPLICATION_MODULE(false, false, false);

	public:
		DomainModule() : mAPI(nullptr) {}
		~DomainModule() override {}

	private:
		bool OnInitialize() override;
		void OnFinalize() override;
		void OnPreTick() override;
		void OnTick() override;
		void OnPostTick() override;
		void OnPreInvalidate() override;
		void OnPostInvalidate() override;
		void OnEvent(WindowEventData& event) override;

	private:
		DomainAPI* mAPI;
	};
}
