#pragma once

#include <Editor/GUI/Window/GUIWindow.h>

namespace Portakal
{
	class EDITOR_API WorldGUIWindow : public GUIWindow
	{
	public:
		WorldGUIWindow() = default;
		~WorldGUIWindow() = default;

		virtual void OnShow() override;
		virtual void OnHide() override;
		virtual void OnPaint() override;

		virtual void OnInitialize() override;
		virtual void OnShutdown() override;

	};
}