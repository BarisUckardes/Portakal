#include "D3DDevice.h"

#include <Runtime/D3D12/Adapter/D3DAdapter.h>
#include <Runtime/D3D12/Swapchain/D3DSwapchain.h>
#include <Runtime/D3D12/Command/D3DCommandList.h>
#include <Runtime/D3D12/Command/D3DCommandPool.h>
#include <Runtime/D3D12/Fence/D3DFence.h>
#include <Runtime/D3D12/Texture/D3DTexture.h>
#include <Runtime/D3D12/Texture/D3DTextureView.h>

namespace Portakal
{
	D3DDevice::D3DDevice(const GraphicsDeviceDesc& desc) : GraphicsDevice(desc), mAdapter(((const D3DAdapter*)desc.pAdapter)->GetAdapter())
	{
		DEV_SYSTEM(SUCCEEDED(D3D12CreateDevice(mAdapter.Get(), D3D_FEATURE_LEVEL_12_2, IID_PPV_ARGS(mDevice.GetAddressOf()))), "D3DDevice", "Failed to create D3DDevice",
				   "ID3D12Device has been created successfully.");

		D3D12_COMMAND_QUEUE_DESC graphicsQueueDesc = {};
		graphicsQueueDesc.Type = D3D12_COMMAND_LIST_TYPE_DIRECT;
		graphicsQueueDesc.Flags = D3D12_COMMAND_QUEUE_FLAG_NONE;
		graphicsQueueDesc.NodeMask = 0;
		graphicsQueueDesc.Priority = D3D12_COMMAND_QUEUE_PRIORITY_NORMAL;

		DEV_SYSTEM(SUCCEEDED(mDevice->CreateCommandQueue(&graphicsQueueDesc, IID_PPV_ARGS(mGraphicsQueue.GetAddressOf()))), "D3DDevice", "Failed to create graphics queue",
				   "Graphics queue has been created successfully.");

		D3D12_COMMAND_QUEUE_DESC computeQueueDesc = {};
		computeQueueDesc.Type = D3D12_COMMAND_LIST_TYPE_COMPUTE;
		computeQueueDesc.Flags = D3D12_COMMAND_QUEUE_FLAG_NONE;
		computeQueueDesc.NodeMask = 0;
		computeQueueDesc.Priority = D3D12_COMMAND_QUEUE_PRIORITY_NORMAL;

		DEV_SYSTEM(SUCCEEDED(mDevice->CreateCommandQueue(&computeQueueDesc, IID_PPV_ARGS(mComputeQueue.GetAddressOf()))), "D3DDevice", "Failed to create compute queue",
				   "Compute queue has been created successfully.");

		D3D12_COMMAND_QUEUE_DESC transferQueueDesc = {};
		transferQueueDesc.Type = D3D12_COMMAND_LIST_TYPE_COPY;
		transferQueueDesc.Flags = D3D12_COMMAND_QUEUE_FLAG_NONE;
		transferQueueDesc.NodeMask = 0;
		transferQueueDesc.Priority = D3D12_COMMAND_QUEUE_PRIORITY_NORMAL;

		DEV_SYSTEM(SUCCEEDED(mDevice->CreateCommandQueue(&transferQueueDesc, IID_PPV_ARGS(mTransferQueue.GetAddressOf()))), "D3DDevice", "Failed to create transfer queue",
				   "Transfer queue has been created successfully.");
	}
	SharedHeap<Texture> D3DDevice::CreateD3DSwapchainTexture(const TextureDesc& desc, ComPtr<ID3D12Resource> pResource)
	{
		SharedHeap<Texture> texture = new D3DTexture(desc, this, pResource);
		RegisterChild(texture.QueryAs<GraphicsDeviceObject>());
		return texture;
	}
	Texture* D3DDevice::CreateTextureCore(const TextureDesc& desc)
	{
		return new D3DTexture(desc, this);
	}
	TextureView* D3DDevice::CreateTextureViewCore(const TextureViewDesc& desc)
	{
		return new D3DTextureView(desc, this);
	}
	CommandList* D3DDevice::CreateCommandListCore(const CommandListDesc& desc)
	{
		return new D3DCommandList(desc, this);
	}
	CommandPool* D3DDevice::CreateCommandPoolCore(const CommandPoolDesc& desc)
	{
		return new D3DCommandPool(desc, this);
	}
	Fence* D3DDevice::CreateFenceCore()
	{
		return new D3DFence(this);
	}
	Swapchain* D3DDevice::CreateSwapchainCore(const SwapchainDesc& desc)
	{
		return new D3DSwapchain(desc, this);
	}
}