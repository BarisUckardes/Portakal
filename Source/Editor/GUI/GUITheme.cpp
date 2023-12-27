#include "GUITheme.h"

#include <imgui.h>

namespace Portakal
{
	GUITheme::GUITheme()
	{
		Alpha = 1.0f;             // Global alpha applies to everything in Dear ImGui.
		DisabledAlpha = 0.60f;            // Additional alpha multiplier applied by BeginDisabled(). Multiply over current value of Alpha.
		WindowPadding = { 8, 8 };      // Padding within a window
		WindowRounding = 0.0f;             // Radius of window corners rounding. Set to 0.0f to have rectangular windows. Large values tend to lead to variety of artifacts and are not recommended.
		WindowBorderSize = 1.0f;             // Thickness of border around windows. Generally set to 0.0f or 1.0f. Other values not well tested.
		WindowMinSize = { 32, 32 };    // Minimum window size
		WindowTitleAlign = { 0.0f, 0.5f }; // Alignment for title bar text
		WindowMenuButtonPosition = GUIDirection::Left;    // Position of the collapsing/docking button in the title bar (left/right). Defaults to ImGuiDir_Left.
		ChildRounding = 0.0f;             // Radius of child window corners rounding. Set to 0.0f to have rectangular child windows
		ChildBorderSize = 1.0f;             // Thickness of border around child windows. Generally set to 0.0f or 1.0f. Other values not well tested.
		PopupRounding = 0.0f;             // Radius of popup window corners rounding. Set to 0.0f to have rectangular child windows
		PopupBorderSize = 1.0f;             // Thickness of border around popup or tooltip windows. Generally set to 0.0f or 1.0f. Other values not well tested.
		FramePadding = { 4, 3 };      // Padding within a framed rectangle (used by most widgets)
		FrameRounding = 0.0f;             // Radius of frame corners rounding. Set to 0.0f to have rectangular frames (used by most widgets).
		FrameBorderSize = 0.0f;             // Thickness of border around frames. Generally set to 0.0f or 1.0f. Other values not well tested.
		ItemSpacing = { 8, 4 };      // Horizontal and vertical spacing between widgets/lines
		ItemInnerSpacing = { 4, 4 };      // Horizontal and vertical spacing between within elements of a composed widget (e.g. a slider and its label)
		CellPadding = { 4, 2 };      // Padding within a table cell
		TouchExtraPadding = { 0, 0 };      // Expand reactive bounding box for touch-based system where touch position is not accurate enough. Unfortunately we don't sort widgets so priority on overlap will always be given to the first widget. So don't grow this too much!
		IndentSpacing = 21.0f;            // Horizontal spacing when e.g. entering a tree node. Generally == (FontSize + FramePadding.x*2).
		ColumnsMinSpacing = 6.0f;             // Minimum horizontal spacing between two columns. Preferably > (FramePadding.x + 1).
		ScrollbarSize = 14.0f;            // Width of the vertical scrollbar, Height of the horizontal scrollbar
		ScrollbarRounding = 9.0f;             // Radius of grab corners rounding for scrollbar
		GrabMinSize = 12.0f;            // Minimum width/height of a grab box for slider/scrollbar
		GrabRounding = 0.0f;             // Radius of grabs corners rounding. Set to 0.0f to have rectangular slider grabs.
		LogSliderDeadzone = 4.0f;             // The size in pixels of the dead-zone around zero on logarithmic sliders that cross zero.
		TabRounding = 4.0f;             // Radius of upper corners of a tab. Set to 0.0f to have rectangular tabs.
		TabBorderSize = 0.0f;             // Thickness of border around tabs.
		TabMinWidthForCloseButton = 0.0f;           // Minimum width for close button to appears on an unselected tab when hovered. Set to 0.0f to always show when hovering, set to FLT_MAX to never show close button unless selected.
		ColorButtonPosition = GUIDirection::Right;   // Side of the color button in the ColorEdit4 widget (left/right). Defaults to ImGuiDir_Right.
		ButtonTextAlign = { 0.5f, 0.5f };// Alignment of button text when button is larger than text.
		SelectableTextAlign = { 0.0f, 0.0f };// Alignment of selectable text. Defaults to (0.0f, 0.0f) (top-left aligned). It's generally important to keep this left-aligned if you want to lay multiple items on a same line.
		DisplayWindowPadding = { 19, 19 };    // Window position are clamped to be visible within the display area or monitors by at least this amount. Only applies to regular windows.
		DisplaySafeAreaPadding = { 3, 3 };      // If you cannot see the edge of your screen (e.g. on a TV) increase the safe area padding. Covers popups/tooltips as well regular windows.
		MouseCursorScale = 1.0f;             // Scale software rendered mouse cursor (when io.MouseDrawCursor is enabled). May be removed later.
		bAntiAliasedLines = true;             // Enable anti-aliased lines/borders. Disable if you are really tight on CPU/GPU.
		bAntiAliasedLinesUseTexture = true;             // Enable anti-aliased lines/borders using textures where possible. Require backend to render with bilinear filtering (NOT point/nearest filtering).
		bAntiAliasedFill = true;             // Enable anti-aliased filled shapes (rounded rectangles, circles, etc.).
		CurveTessellationTolerance = 1.25f;            // Tessellation tolerance when using PathBezierCurveTo() without a specific number of segments. Decrease for highly tessellated curves (higher quality, more polygons), increase to reduce quality.
		CircleTessellationMaxError = 0.30f;         // Maximum error (in pixels) allowed when using AddCircle()/AddCircleFilled() or drawing rounded corner rectangles with no explicit segment count specified. Decrease for higher quality but more geometry.

		// Default theme
		ImGui::StyleColorsDark((ImGuiStyle*)this);
	}
}