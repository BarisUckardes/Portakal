#pragma once

#include <Runtime/Math/Vector2.h>

#include <Editor/GUI/GUIDirection.h>
#include <Editor/GUI/GUIColorVariables.h>

namespace Portakal
{
	struct EDITOR_API GUITheme
	{
		GUITheme();

		float Alpha;
		float DisabledAlpha;
		Vector2F WindowPadding;
		float WindowRounding;
		float WindowBorderSize;
		Vector2F WindowMinSize;
		Vector2F WindowTitleAlign;
		GUIDirection WindowMenuButtonPosition;
		float ChildRounding;
		float ChildBorderSize;
		float PopupRounding;
		float PopupBorderSize;
		Vector2F FramePadding;
		float FrameRounding;
		float FrameBorderSize;
		Vector2F ItemSpacing;
		Vector2F ItemInnerSpacing;
		Vector2F CellPadding;
		Vector2F TouchExtraPadding;
		float IndentSpacing;
		float ColumnsMinSpacing;
		float ScrollbarSize;
		float ScrollbarRounding;
		float GrabMinSize;
		float GrabRounding;
		float LogSliderDeadzone;
		float TabRounding;
		float TabBorderSize;
		float TabMinWidthForCloseButton;
		GUIDirection ColorButtonPosition;
		Vector2F ButtonTextAlign;
		Vector2F SelectableTextAlign;
		Vector2F DisplayWindowPadding;
		Vector2F DisplaySafeAreaPadding;
		float MouseCursorScale;
		bool bAntiAliasedLines;
		bool bAntiAliasedLinesUseTexture;
		bool bAntiAliasedFill;
		float CurveTessellationTolerance;
		float CircleTessellationMaxError;
		GUIColorVariables Colors[(byte)GUIColorVariables::COUNT];
	};
}
