#pragma once
#include <Runtime/Application/ApplicationModule.h>
#include <Runtime/Resource/RenderTarget/RenderTarget.h>
#include "ImGuiRenderEndModule.reflected.h"

namespace Portakal
{
	PCLASS();
	class EDITOR_API ImGuiRenderEndModule : public ApplicationModule
	{
		GENERATE_OBJECT;
	public:
		ImGuiRenderEndModule() = default;
		~ImGuiRenderEndModule() = default;

	private:
		// Inherited via ApplicationModule
		void OnInitialize() override;
		void OnFinalize() override;
		void OnTick() override;
	private:
		void InvalidateRenderTarget(const SharedHeap<GraphicsDevice>& pDevice);
	private:
		Array<SharedHeap<RenderTarget>> mRenderTargets;
		byte mSwapchainBufferIndex;

	};
}










