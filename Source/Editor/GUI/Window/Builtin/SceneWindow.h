#pragma once
#include <Editor/GUI/Window/GUIWindow.h>
#include "SceneWindow.reflected.h"

namespace Portakal
{
	PCLASS();
	class EDITOR_API SceneWindow : public GUIWindow
	{
		GENERATE_OBJECT;
	public:
		SceneWindow() = default;
		~SceneWindow() = default;

		// Inherited via GUIWindow
		void OnShutdown() override;
		void OnShow() override;
		void OnHide() override;
		void OnPaint() override;
		void OnInitialize() override;
	private:

	};
}



