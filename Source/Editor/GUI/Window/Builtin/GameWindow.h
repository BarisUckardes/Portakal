#pragma once
#include <Editor/GUI/Window/GUIWindow.h>
#include "GameWindow.reflected.h"

namespace Portakal
{
	PCLASS();
	class EDITOR_API GameWindow : public GUIWindow
	{
		GENERATE_OBJECT;
	public:
		GameWindow() = default;
		~GameWindow() = default;

		// Inherited via GUIWindow
		void OnShutdown() override;
		void OnShow() override;
		void OnHide() override;
		void OnPaint() override;
		void OnInitialize() override;
	private:

	};
}





































