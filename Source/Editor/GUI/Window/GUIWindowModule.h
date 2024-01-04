#pragma once
#include <Runtime/Application/ApplicationModule.h>
#include <Editor/GUI/Window/GUIWindowAPI.h>
#include "GUIWindowModule.reflected.h"

namespace Portakal
{
	PCLASS();
	class EDITOR_API GUIWindowModule : public ApplicationModule
	{
		GENERATE_OBJECT;
	public:
		GUIWindowModule() = default;
		~GUIWindowModule() = default;

	private:
		// Inherited via ApplicationModule
		void OnInitialize() override;
		void OnFinalize() override;
		void OnTick() override;
	private:
		GUIWindowAPI* mAPI;
	};
}












