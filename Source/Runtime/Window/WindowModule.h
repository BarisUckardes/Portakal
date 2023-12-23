#pragma once
#include <Runtime/Platform/PlatformWindow.h>
#include <Runtime/Application/ApplicationModule.h>

namespace Portakal
{
	class WindowAPI;
	class RUNTIME_API WindowModule : public ApplicationModule
	{
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
