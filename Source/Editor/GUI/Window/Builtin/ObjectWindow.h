#pragma once
#include <Editor/GUI/Window/GUIWindow.h>
#include "ObjectWindow.reflected.h"

namespace Portakal
{
	PCLASS();
	class EDITOR_API ObjectWindow : public GUIWindow
	{
		GENERATE_OBJECT;
	public:
		ObjectWindow() = default;
		~ObjectWindow() = default;

	private:
		// Inherited via GUIWindow
		void OnShutdown() override;
		void OnShow() override;
		void OnHide() override;
		void OnPaint() override;
		void OnInitialize() override;
	};
}











