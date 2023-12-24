#pragma once
#include <Runtime/Application/ApplicationModule.h>
#include <Runtime/Reflection/ReflectionAPI.h>

namespace Portakal
{
	class RUNTIME_API ReflectionModule : public ApplicationModule
	{
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
