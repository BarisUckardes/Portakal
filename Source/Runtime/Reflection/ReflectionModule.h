#pragma once
#include <Runtime/Application/ApplicationModule.h>
#include <Runtime/Reflection/ReflectionAPI.h>
#include "ReflectionModule.reflected.h"

namespace Portakal
{
	PCLASS();
	class RUNTIME_API ReflectionModule : public ApplicationModule
	{
		GENERATE_OBJECT;
	public:
		ReflectionModule() : mAPI(nullptr)
		{

		}
		~ReflectionModule() = default;

		virtual void OnInitialize() override;
		virtual void OnTick() override;
		virtual void OnFinalize() override;
	private:
		ReflectionAPI* mAPI;
	};
}































































































