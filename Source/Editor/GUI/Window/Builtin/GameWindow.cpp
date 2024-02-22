#include "GameWindow.h"
#include <imgui.h>
#include <Runtime/World/SceneAPI.h>
#include <Runtime/Rendering/Builtin/BasicRenderAspect.h>
#include <Runtime/World/Aspects/DisplayAspect.h>
#include <Editor/ImGui/ImGuiAPI.h>
#include <Runtime/Graphics/GraphicsAPI.h>

namespace Portakal
{
	void GameWindow::OnShutdown()
	{
	}
	void GameWindow::OnShow()
	{
	}
	void GameWindow::OnHide()
	{
	}
	SharedHeap<TextureResource> pTexture;
	SharedHeap<CommandPool> pCmdPool;
	SharedHeap<CommandList> pCmdList;
	void GameWindow::OnPaint()
	{
		ImGui::Text("Game");
		//Get primal scene
		SharedHeap<Scene> pScene = SceneAPI::GetPrimalScene();
		if (pScene.IsShutdown())
			return;

		DisplayAspect* pAspect = pScene->GetAspect<DisplayAspect>();
		if (pAspect == nullptr)
			return;

		SharedHeap<RenderTarget> pRenderTarget = pAspect->GetPrimaryDisplay();
		if (pRenderTarget.IsShutdown())
			return;

		if (pTexture.IsShutdown())
		{
			pTexture = new TextureResource();
			pTexture->Wrap(pRenderTarget->GetColorTargets()[0]);
			pTexture->CreateView(0, 0);

			CommandPoolDesc cmdPoolDesc = {};
			cmdPoolDesc.Type = CommandPoolType::Graphics;
			pCmdPool = GraphicsAPI::GetDefaultDevice()->CreateCommandPool(cmdPoolDesc);

			CommandListDesc cmdListDesc = {};
			cmdListDesc.pPool = pCmdPool;
			pCmdList = GraphicsAPI::GetDefaultDevice()->CreateCommandList(cmdListDesc);
		}

		SharedHeap<ImGuiTextureBinding> pBinding = ImGuiAPI::GetRenderer()->GetOrCreateTextureBinding(pTexture);
		ImGui::Image(pBinding->GetTable(), ImGui::GetContentRegionAvail());

		//Render to target
		pCmdList->BeginRecording();
		TextureMemoryBarrierDesc postMemoryBarrierDesc = {};
		postMemoryBarrierDesc.ArrayIndex = 0;
		postMemoryBarrierDesc.MipIndex = 0;
		postMemoryBarrierDesc.AspectFlags = TextureAspectFlags::Color;
		postMemoryBarrierDesc.SourceAccessFlags = GraphicsMemoryAccessFlags::TransferWrite;
		postMemoryBarrierDesc.SourceLayout = TextureMemoryLayout::Unknown;
		postMemoryBarrierDesc.SourceQueue = GraphicsQueueFamilyType::Graphics;
		postMemoryBarrierDesc.SourceStageFlags = PipelineStageFlags::Transfer;
		postMemoryBarrierDesc.DestinationAccessFlags = GraphicsMemoryAccessFlags::ShaderRead;
		postMemoryBarrierDesc.DestinationLayout = TextureMemoryLayout::ShaderReadOnly;
		postMemoryBarrierDesc.DestinationQueue = GraphicsQueueFamilyType::Graphics;
		postMemoryBarrierDesc.DestinationStageFlags = PipelineStageFlags::FragmentShader;
		pCmdList->SetTextureMemoryBarrier(pTexture->GetTexture().GetHeap(), postMemoryBarrierDesc);
		pCmdList->EndRecording();
		GraphicsAPI::GetDefaultDevice()->SubmitCommandLists(pCmdList.GetHeapAddress(), 1,GraphicsAPI::GetDefaultGraphicsQueue().GetHeap(),nullptr,0,nullptr,nullptr,0,nullptr); 
	}
	void GameWindow::OnInitialize()
	{
	}
}
