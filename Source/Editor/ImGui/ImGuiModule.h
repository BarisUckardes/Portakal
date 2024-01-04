#pragma once
#include <Runtime/Application/ApplicationModule.h>
#include <Editor/ImGui/ImGuiRenderer.h>
#include <Editor/ImGui/ImGuiAPI.h>
#include "ImguiModule.reflected.h"

namespace Portakal
{
	class ImGuiAPI;

	PCLASS();
	class RUNTIME_API ImGuiModule : public ApplicationModule
	{
		GENERATE_OBJECT;
	public:
		ImGuiModule() : mAPI(nullptr)
		{

		}
		~ImGuiModule() = default;

	private:
		// Inherited via ApplicationModule
		void OnInitialize() override;
		void OnFinalize() override;
		void OnTick() override;
	private:
		ImGuiAPI* mAPI;
	};
}




































































