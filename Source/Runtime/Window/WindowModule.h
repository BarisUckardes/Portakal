#pragma once
#include <Runtime/Platform/PlatformWindow.h>
#include <Runtime/Application/ApplicationModule.h>
#include "WindowModule.reflected.h"

namespace Portakal
{
	class WindowAPI;
	PCLASS();
	class RUNTIME_API WindowModule : public ApplicationModule
	{
		GENERATE_OBJECT;
	public:
		WindowModule() = default;
		~WindowModule() = default;
	private:
		virtual void OnInitialize() override;
		virtual void OnTick() override;
		virtual void OnFinalize() override;
	private:
		WindowAPI* mAPI;
	};
}

































































































































































































