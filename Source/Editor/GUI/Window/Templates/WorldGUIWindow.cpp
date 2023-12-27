#include "WorldGUIWindow.h"

#include <imgui.h>

namespace Portakal
{
	void WorldGUIWindow::OnShow()
	{
		DEV_LOG("WorldGUIWindow", "Show");
	}
	void WorldGUIWindow::OnHide()
	{
		DEV_LOG("WorldGUIWindow", "Hide");
	}
	void WorldGUIWindow::OnPaint()
	{
		ImGui::Text("ALLAH HEPIMIZIN BELASINI VERMIS");
	}
	void WorldGUIWindow::OnInitialize()
	{
	}
	void WorldGUIWindow::OnShutdown()
	{
	}
}