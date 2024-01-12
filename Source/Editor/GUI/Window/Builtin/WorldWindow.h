#pragma once
#include <Editor/GUI/Window/GUIWindow.h>
#include "WorldWindow.reflected.h"

namespace Portakal
{
	PCLASS();
	class EDITOR_API WorldWindow : public GUIWindow
	{
		GENERATE_OBJECT;
	public:
		WorldWindow() = default;
		~WorldWindow() = default;

	private:
		// Inherited via GUIWindow
		void OnShutdown() override;
		void OnShow() override;
		void OnHide() override;
		void OnPaint() override;
		void OnInitialize() override;
	private:

	};
}











