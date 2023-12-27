#pragma once

#include <Editor/GUI/Object/GUIObjectVisualizer.h>

namespace Roveldo
{
	class EDITOR_API TextureGUIVisualizer : public GUIObjectVisualizer
	{
	public:
		TextureGUIVisualizer() = default;
		~TextureGUIVisualizer() = default;

	private:
		virtual void OnInitialize() override;
		virtual void OnShutdown() override;
		virtual void OnPaint() override;
	};
}
