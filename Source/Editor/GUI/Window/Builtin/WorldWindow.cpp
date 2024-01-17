#include "WorldWindow.h"
#include <imgui.h>
#include <Runtime/World/SceneAPI.h>
#include <Runtime/Reflection/ReflectionAPI.h>
#include <Editor/Domain/DomainAPI.h>
#include <Editor/Domain/DomainFile.h>

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
			{
				ImGui::Text(*pAspect->GetType()->GetName());
			}
			if (ImGui::Button("+"))
			{
				ImGui::OpenPopup("CreateAspectPopup");
			}
		}

		if (ImGui::CollapsingHeader("Entities"))
		{
			const Array<SharedHeap<Entity>>& entities = mTargetScene->GetEntities();
			for (const SharedHeap<Entity>& pEntity : entities)
			{
				ImGui::Text(*pEntity->GetName());
			}
		}

		//Handle popups
		if (ImGui::BeginPopup("CreateAspectPopup"))
		{
			for (const Type* pType : mAspectTypes)
			{
				if (ImGui::Selectable(*pType->GetName()))
				{
					mTargetScene->CreateAspect(pType);
				}
			}
			ImGui::EndPopup();
		}

		if (ImGui::Button("Save"))
		{
			//Get domain file
			const SharedHeap<DomainFile> pFile = DomainAPI::GetFile(mTargetScene->GetName());
			if(pFile.IsShutdown())
			{
				DEV_LOG("WorldWindow", "No such DomainFile is found!");
				return;
			}

			//Save the file
			pFile->SaveSync();
		}
	}
	void WorldWindow::OnInitialize()
	{
		mAspectTypes = ReflectionAPI::GetSubTypes(typeof(SceneAspect));
	}
}
