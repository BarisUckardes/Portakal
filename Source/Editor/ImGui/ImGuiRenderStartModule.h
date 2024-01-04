#pragma once
#include <Runtime/Application/ApplicationModule.h>
#include "ImGuiRenderStartModule.reflected.h"

namespace Portakal
{
	PCLASS();
	class EDITOR_API ImGuiRenderStartModule : public ApplicationModule
	{
		GENERATE_OBJECT;
	public:
		ImGuiRenderStartModule() = default;
		~ImGuiRenderStartModule() = default;

	private:
		// Inherited via ApplicationModule
		void OnInitialize() override;
		void OnFinalize() override;
		void OnTick() override;
	private:

	};
}










