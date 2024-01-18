#pragma once
#include <Runtime/Application/ApplicationModule.h>
#include <Runtime/Resource/RenderTarget/RenderTargetResource.h>
#include "ImGuiRenderEndModule.reflected.h"

namespace Portakal
{
	PCLASS();
	class EDITOR_API ImGuiRenderEndModule : public ApplicationModule
	{
		GENERATE_OBJECT;
	public:
		ImGuiRenderEndModule() : mSwapchainBufferIndex(0)
		{

		}
		~ImGuiRenderEndModule() = default;

	private:
		// Inherited via ApplicationModule
		void OnInitialize() override;
		void OnFinalize() override;
		void OnTick() override;
	private:
		void InvalidateRenderTarget(const SharedHeap<GraphicsDevice>& pDevice);
	private:
		Array<SharedHeap<RenderTargetResource>> mRenderTargets;
		Vector2US mLastSwapchainSize;
		Byte mSwapchainBufferIndex;

	};
}
































































































