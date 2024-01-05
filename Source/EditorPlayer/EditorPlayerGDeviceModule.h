#pragma once
#include <Runtime/Application/ApplicationModule.h>
#include <Runtime/Graphics/Device/GraphicsDevice.h>
#include <Runtime/Graphics/Adapter/GraphicsAdapter.h>
#include <Runtime/Graphics/Instance/GraphicsInstance.h>
#include <Runtime/Graphics/Swapchain/Swapchain.h>
#include "EditorPlayerGDeviceModule.reflected.h"

namespace Portakal
{
	PCLASS();
	class EditorPlayerGDeviceModule : public ApplicationModule
	{
		GENERATE_OBJECT;
	public:
		EditorPlayerGDeviceModule() = default;
		~EditorPlayerGDeviceModule() = default;

	private:
		// Inherited via ApplicationModule
		void OnInitialize() override;
		void OnFinalize() override;
		void OnTick() override;
	private:
		SharedHeap<GraphicsInstance> mInstance;
		SharedHeap<GraphicsAdapter> mAdapter;
		SharedHeap<GraphicsDevice> mDevice;
		SharedHeap<Swapchain> mSwapchain;
	};
}




















































































