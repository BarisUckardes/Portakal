#pragma once
#include <Runtime/Application/Application.h>

namespace Portakal
{
	class RUNTIME_API VulkanApplication : public Application
	{
	public:

	private:
		virtual void OnInitialize() override;
		virtual void OnFinalize() override;
		virtual void OnPreTick() override;
		virtual void OnPostTick() override;
	private:
	};
}
