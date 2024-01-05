#include "DomainWindow.h"
#include <Editor/Domain/DomainAPI.h>
#include <imgui.h>

namespace Portakal
{
	void DomainWindow::RenderTargetPath()
	{
		const String text = mTargetFolder.IsShutdown() ? "unknown" : mTargetFolder->GetPath();
		ImGui::Text(*text);
		ImGui::Separator();
	}
	void DomainWindow::OnShutdown()
	{

	}
	void DomainWindow::OnShow()
	{

	}
	void DomainWindow::OnHide()
	{

	}
	void DomainWindow::OnPaint()
	{
		//Render target path
		RenderTargetPath();
	}
	void DomainWindow::OnInitialize()
	{
		//Get domain API folder
		SharedHeap<DomainFolder> pRootFolder = DomainAPI::GetRootFolder();
		if (pRootFolder.IsShutdown())
			return;

		mTargetFolder = pRootFolder;
	}
}
