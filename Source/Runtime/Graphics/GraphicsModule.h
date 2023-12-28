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
		void OnInitialize() override;
		void OnFinalize() override;
		void OnTick() override;
	private:
		GraphicsAPI* mAPI;

	};
}
