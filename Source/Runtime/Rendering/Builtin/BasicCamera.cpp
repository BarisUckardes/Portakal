#include "BasicCamera.h"
#include <Runtime/World/Scene.h>
#include <Runtime/Rendering/Builtin/BasicRenderAspect.h>
#include <Runtime/World/Aspects/DisplayAspect.h>
#include <Runtime/Graphics/GraphicsAPI.h>

namespace Portakal
{
	void BasicCamera::TestCreateDisplay()
	{
		DisplayAspect* pAspect = GetOwnerEntity()->GetOwnerScene()->GetAspect<DisplayAspect>();
		if (pAspect == nullptr)
			return;

		//Create memory heap
		GraphicsMemoryHeapDesc heapDesc = {};
		heapDesc.Type = GraphicsMemoryType::Device;
		heapDesc.SizeInBytes = 4096 + (4 * 512 * 512);
		mTestHeap = GraphicsAPI::GetDefaultDevice()->CreateMemoryHeap(heapDesc);

		//First create color texture
		TextureDesc textureDesc = {};
		textureDesc.Type = TextureType::Texture2D;
		textureDesc.Format = TextureFormat::B8_G8_R8_A8_UNorm;
		textureDesc.Usage = TextureUsage::Sampled | TextureUsage::ColorAttachment | TextureUsage::TransferDestination;
		textureDesc.ArrayLevels = 1;
		textureDesc.MipLevels = 1;
		textureDesc.SampleCount = TextureSampleCount::SAMPLE_COUNT_1;
		textureDesc.Size = { 512,512,1 };
		textureDesc.pHeap = mTestHeap;
		mTestTexture = new TextureResource();
		mTestTexture->AllocateTexture(textureDesc);

		//Create render target
		mRenderTarget = new RenderTargetResource();
		RenderPassDesc renderPassDesc = {};
		renderPassDesc.bSwapchain = false;
		renderPassDesc.Size = { 512,512 };
		RenderPassAttachmentDesc attachmentDesc = {};
		attachmentDesc.ArrayLevel = 0;
		attachmentDesc.MipLevel = 0;
		attachmentDesc.ColorLoadOperation = RenderPassLoadOperation::Clear;
		attachmentDesc.ColorStoreOperation = RenderPassStoreOperation::Store;
		attachmentDesc.InputLayout = TextureMemoryLayout::Unknown;
		attachmentDesc.OutputLayout = TextureMemoryLayout::ShaderReadOnly;
		attachmentDesc.StencilLoadOperation = RenderPassLoadOperation::Clear;
		attachmentDesc.StencilStoreOperation = RenderPassStoreOperation::Ignore;
		attachmentDesc.pTexture = mTestTexture->GetTexture();
		renderPassDesc.ColorAttachments.Add(attachmentDesc);
		mTestTexture->CreateView(0, 0);
		renderPassDesc.AttachmentViews.Add(mTestTexture->GetView(0, 0));

		RenderPassSubpassDesc subpassDesc = {};
		subpassDesc.BindPoint = PipelineBindPoint::Graphics;
		subpassDesc.DepthStencilInput = {};
		subpassDesc.Inputs = {0};
		subpassDesc.MultisampleInputs = {};
		subpassDesc.PreserveAttachments = {};
		renderPassDesc.Subpasses.Add(subpassDesc);
		mRenderTarget->Create(renderPassDesc);

		//Register
		pAspect->RegisterDisplay(mRenderTarget);
	}
	void BasicCamera::SetFieldOfView(const Float32 value)
	{
		mFieldOfView = value;
	}
	void BasicCamera::SetNearPlane(const Float32 value)
	{
		mNearPlane = value;
	}
	void BasicCamera::SetFarPlane(const Float32 value)
	{
		mFarPlane = value;
	}
	void BasicCamera::SetRenderTarget(const SharedHeap<RenderTargetResource>& pResource)
	{

	}
	void BasicCamera::OnInitialize()
	{
		TestCreateDisplay();
		GetOwnerEntity()->GetOwnerScene()->GetAspect<BasicRenderAspect>()->RegisterCamera(this);
	}
	void BasicCamera::OnShutdown()
	{
		GetOwnerEntity()->GetOwnerScene()->GetAspect<BasicRenderAspect>()->RemoveCamera(this);
	}
}
