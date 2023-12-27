#include "GUIRenderingContext.h"

#include <imgui.h>
#include <imgui_internal.h>

namespace Portakal
{
	GUIRenderingContext::GUIRenderingContext(const SharedHeap<ImGuiRenderer>& pRenderer) : mImGuiRenderer(pRenderer)
	{

	}
	bool GUIRenderingContext::BeginWindow(const String windowTitle, const GUIWindowFlags flags, bool bOpen)
	{
		return ImGui::Begin(*windowTitle, &bOpen, (ImGuiWindowFlags)flags);
	}
	void GUIRenderingContext::FinalizeWindow()
	{
		ImGui::End();
	}
	void GUIRenderingContext::SetNextWindowSize(const Vector2UI size)
	{
		ImGui::SetNextWindowSize({ (float)size.X,(float)size.Y });
	}
	void GUIRenderingContext::SetNextWindowPos(const Vector2UI position)
	{
		ImGui::SetNextWindowPos({ (float)position.X,(float)position.Y });
	}
	void GUIRenderingContext::SetNextWindowViewport(const GUIViewport* pViewport)
	{
		ImGui::SetNextWindowViewport(pViewport->GetID());
	}
	void GUIRenderingContext::BeginStyleVariable(const GUIStyleVariables variable, const Vector2F value)
	{
		ImGui::PushStyleVar((ImGuiStyleVar)variable, { (float)value.X,(float)value.Y });
	}
	void GUIRenderingContext::BeginStyleVariable(const GUIStyleVariables variable, const float value)
	{
		ImGui::PushStyleVar((ImGuiStyleVar)variable, value);
	}
	void GUIRenderingContext::BeginStyleColor(const GUIColorVariables variable, const Color4F color)
	{
		ImGui::PushStyleColor((ImGuiCol)variable, { color.R,color.G,color.B,color.A });
	}
	void GUIRenderingContext::FinalizeStyleVariable()
	{
		ImGui::PopStyleVar();
	}
	void GUIRenderingContext::FinalizeColorVariable()
	{
		ImGui::PopStyleColor();
	}
	GUIID GUIRenderingContext::GetObjectID(const String& name)
	{
		return ImGui::GetID(*name);
	}
	GUIID GUIRenderingContext::CreateDockspace(const GUIID id, const Vector2UI size, const GUIDockNodeFlags flags)
	{
		return ImGui::DockSpace(id, { (float)size.X,(float)size.Y }, (ImGuiDockNodeFlags)flags);
	}
	void GUIRenderingContext::DockBuilderRemoveNode(const GUIID id)
	{
		ImGui::DockBuilderRemoveNode(id);
	}
	void GUIRenderingContext::DockBuilderAddNode(const GUIID id, const GUIDockNodeFlags flags)
	{
		ImGui::DockBuilderAddNode(id, (ImGuiDockNodeFlags)flags);
	}
	void GUIRenderingContext::DockBuilderSetNodeSize(const GUIID id, const Vector2UI size)
	{
		ImGui::DockBuilderSetNodeSize(id, { (float)size.X,(float)size.Y });
	}
	GUIID GUIRenderingContext::DockBuilderSplitNode(const GUIID id, const GUIDirection direction, const float sizeRatio, GUIID& outIdOppositeDir)
	{
		return ImGui::DockBuilderSplitNode(id, (ImGuiDir)direction, sizeRatio, nullptr, &outIdOppositeDir);
	}
	void GUIRenderingContext::DockBuilderDockWindow(const String& windowName, const GUIID nodeID)
	{
		ImGui::DockBuilderDockWindow(*windowName, nodeID);
	}
	void GUIRenderingContext::DockBuilderFinish(const GUIID nodeID)
	{
		ImGui::DockBuilderFinish(nodeID);
	}
	const GUIViewport* const GUIRenderingContext::GetMainViewport() const
	{
		return (GUIViewport*)ImGui::GetMainViewport();
	}
	void GUIRenderingContext::OnShutdown()
	{
		mImGuiRenderer.Deference();
	}
	void GUIRenderingContext::SetTheme(const GUITheme& theme)
	{
		ImGuiStyle& style = ImGui::GetStyle();

		style.Alpha = theme.Alpha;
		style.DisabledAlpha = theme.DisabledAlpha;
		style.WindowPadding = { theme.WindowPadding.X,theme.WindowPadding.Y };
		style.WindowRounding = theme.WindowRounding;
		style.WindowBorderSize = theme.WindowBorderSize;
		style.WindowMinSize = { theme.WindowMinSize.X,theme.WindowMinSize.Y };
		style.WindowTitleAlign = { theme.WindowTitleAlign.X,theme.WindowTitleAlign.Y };
		style.WindowMenuButtonPosition = (ImGuiDir)theme.WindowMenuButtonPosition;
		style.ChildRounding = theme.ChildRounding;
		style.ChildBorderSize = theme.ChildBorderSize;
		style.PopupRounding = theme.PopupRounding;
		style.PopupBorderSize = theme.PopupBorderSize;
		style.FramePadding = { theme.FramePadding.X,theme.FramePadding.Y };
		style.FrameRounding = theme.FrameRounding;
		style.FrameBorderSize = theme.FrameBorderSize;
		style.ItemSpacing = { theme.ItemSpacing.X,theme.ItemSpacing.Y };
		style.ItemInnerSpacing = { theme.ItemInnerSpacing.X,theme.ItemInnerSpacing.Y };
		style.CellPadding = { theme.CellPadding.X,theme.CellPadding.Y };
		style.TouchExtraPadding = { theme.TouchExtraPadding.X,theme.TouchExtraPadding.Y };
		style.IndentSpacing = theme.IndentSpacing;
		style.ColumnsMinSpacing = theme.ColumnsMinSpacing;
		style.ScrollbarSize = theme.ScrollbarSize;
		style.ScrollbarRounding = theme.ScrollbarRounding;
		style.GrabMinSize = theme.GrabMinSize;
		style.GrabRounding = theme.GrabRounding;
		style.LogSliderDeadzone = theme.LogSliderDeadzone;
		style.TabRounding = theme.TabRounding;
		style.TabBorderSize = theme.TabBorderSize;
		style.TabMinWidthForCloseButton = theme.TabMinWidthForCloseButton;
		style.ColorButtonPosition = (ImGuiDir)theme.ColorButtonPosition;
		style.ButtonTextAlign = { theme.ButtonTextAlign.X,theme.ButtonTextAlign.Y };
		style.SelectableTextAlign = { theme.SelectableTextAlign.X,theme.SelectableTextAlign.Y };
		style.DisplayWindowPadding = { theme.DisplayWindowPadding.X,theme.DisplayWindowPadding.Y };
		style.DisplaySafeAreaPadding = { theme.DisplaySafeAreaPadding.X,theme.DisplaySafeAreaPadding.Y };
		style.MouseCursorScale = theme.MouseCursorScale;
		style.AntiAliasedLines = theme.bAntiAliasedLines;
		style.AntiAliasedLinesUseTex = theme.bAntiAliasedLinesUseTexture;
		style.AntiAliasedFill = theme.bAntiAliasedFill;
		style.CurveTessellationTol = theme.CurveTessellationTolerance;
		style.CircleTessellationMaxError = theme.CircleTessellationMaxError;
		Memory::Copy(&style.Colors, &theme.Colors, sizeof(style.Colors));
	}
}
