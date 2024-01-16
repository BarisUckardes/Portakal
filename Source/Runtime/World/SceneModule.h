#pragma once
#include <Runtime/Application/ApplicationModule.h>
#include <Runtime/World/SceneAPI.h>
#include "SceneModule.reflected.h"

namespace Portakal
{
	PCLASS();
	class RUNTIME_API SceneModule : public ApplicationModule
	{
		GENERATE_OBJECT;
	public:
		SceneModule() = default;
		~SceneModule() = default;
	private:
		// Inherited via ApplicationModule
		void OnInitialize() override;
		void OnFinalize() override;
		void OnTick() override;
	private:
		SceneAPI* mAPI;

	};
}
