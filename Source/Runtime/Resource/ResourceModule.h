#pragma once
#include <Runtime/Application/ApplicationModule.h>
#include <Runtime/Resource/Resource.h>
#include "ResourceModule.reflected.h"

namespace Portakal
{
	class ResourceAPI;

	PCLASS();
	class RUNTIME_API ResourceModule : public ApplicationModule
	{
		GENERATE_OBJECT;
	public:
		ResourceModule() = default;
		~ResourceModule() = default;

	private:
		ResourceAPI* mAPI;

		// Inherited via ApplicationModule
		void OnInitialize() override;
		void OnFinalize() override;
		void OnTick() override;
	};
}

