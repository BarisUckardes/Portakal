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
		void OnInitialize() override;
		void OnFinalize() override;
		void OnTick() override;
	private:
		DomainAPI* mAPI;
	};
}










































































































