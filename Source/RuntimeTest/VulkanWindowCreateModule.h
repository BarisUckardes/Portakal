#pragma once
#include <Runtime/Application/ApplicationModule.h>
#include <Runtime/Platform/PlatformWindow.h>
#include <Runtime/Memory/SharedHeap.h>

namespace Portakal
{
	class RUNTIME_API VulkanWindowCreateModule : public ApplicationModule
	{
	public:
		VulkanWindowCreateModule() = default;
		~VulkanWindowCreateModule() = default;

	private:
		void OnInitialize() override;
		void OnFinalize() override;
		void OnTick() override;
	private:
		SharedHeap<PlatformWindow> mWindow;
	};
}
