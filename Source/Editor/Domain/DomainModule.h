#pragma once
#include <Runtime/Application/ApplicationModule.h>
#include "DomainModule.reflected.h"

namespace Portakal
{
	class DomainAPI;

	PCLASS();
	class EDITOR_API DomainModule : public ApplicationModule
	{
		GENERATE_OBJECT;
	public:
		DomainModule() :mAPI(nullptr)
		{

		}
		~DomainModule() = default;
	private:
		virtual void OnInitialize() override;
		virtual void OnFinalize() override;
		virtual void OnTick() override;
		virtual void OnPreInvalidation() override;
		virtual void OnPostInvalidation() override;
	private:
		DomainAPI* mAPI;
	};
}
























































































































































































































