#pragma once
#include <Runtime/Application/ApplicationModule.h>
#include <Runtime/Graphics/Device/GraphicsDevice.h>
#include <Runtime/Graphics/Instance/GraphicsInstance.h>
#include <Runtime/Graphics/RenderPass/RenderPass.h>
#include <Runtime/Graphics/Adapter/GraphicsAdapter.h>
#include <Runtime/Graphics/Swapchain/Swapchain.h>
#include <Runtime/Graphics/Command/CommandList.h>
#include <Runtime/Graphics/Command/CommandPool.h>

namespace Portakal
{
	class RUNTIME_API VulkanGraphicsModule : public ApplicationModule
	{
	public:

	private:
		virtual void OnInitialize() override;
		virtual void OnTick() override;
		virtual void OnFinalize() override;
	private:
		SharedHeap<PlatformWindow> mWindow;
		SharedHeap<GraphicsInstance> mInstance;
		SharedHeap<GraphicsAdapter> mAdapter;
		SharedHeap<GraphicsDevice> mDevice;
		SharedHeap<Swapchain> mSwapchain;
		SharedHeap<CommandPool> mCmdPool;
		SharedHeap<CommandList> mCmdList;
		SharedHeap<RenderPass> mRenderPass;
		SharedHeap<Fence> mFence;
	};
}
