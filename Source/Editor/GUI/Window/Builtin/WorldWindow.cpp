#include "WorldWindow.h"
#include <imgui.h>
#include <Runtime/World/SceneAPI.h>

namespace Portakal
{
	void WorldWindow::OnSceneChanged(const SharedHeap<Scene>& pScene)
	{
		mTargetScene = pScene;
	}
	void WorldWindow::OnShutdown()
	{

	}
	void WorldWindow::OnShow()
	{

	}
	void WorldWindow::OnHide()
	{

	}
	void WorldWindow::OnPaint()
	{
		//Check if scene changed
		SharedHeap<Scene> pCurrentScene = SceneAPI::GetPrimalScene();
		if (pCurrentScene != mTargetScene)
			OnSceneChanged(pCurrentScene);

		ImGui::Text("World");
		ImGui::Separator();

		if (mTargetScene.IsShutdown())
		{
			ImGui::Text("No valid primal scene is available at the moment");
			return;
		}

		if (ImGui::CollapsingHeader("Aspects"))
		{
			const Array<SharedHeap<SceneAspect>>& aspects = mTargetScene->GetAspects();
			for (const SharedHeap<SceneAspect>& pAspect : aspects)
				ImGui::Text(*pAspect->GetType()->GetName());
		}
		if (ImGui::CollapsingHeader("Entities"))
		{

		}
	}
	void WorldWindow::OnInitialize()
	{

	}
}
