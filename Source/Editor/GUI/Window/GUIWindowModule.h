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
		virtual void OnInitialize() override;
		virtual void OnFinalize() override;
		virtual void OnTick() override;
		virtual void OnPreInvalidation() override;
		virtual void OnPostInvalidation() override;
	private:
		GUIWindowAPI* mAPI;
	};
}


























































