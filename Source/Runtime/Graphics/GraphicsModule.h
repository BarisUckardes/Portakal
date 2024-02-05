#pragma once
#include <Runtime/Application/ApplicationModule.h>
#include <Runtime/Graphics/Device/GraphicsDevice.h>

namespace Portakal
{
	class GraphicsAPI;
	class RUNTIME_API GraphicsModule : public ApplicationModule
	{
	public:
		GraphicsModule() = default;
		~GraphicsModule() = default;

	private:
		// Inherited via ApplicationModule
		virtual void OnInitialize() override;
		virtual void OnFinalize() override;
		virtual void OnTick() override;
		virtual void OnPreInvalidation() override;
		virtual void OnPostInvalidation() override;
	private:
		GraphicsAPI* mAPI;

	};
}
