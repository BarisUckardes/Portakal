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
		ImGuiRenderEndModule() : mSwapchainBufferIndex(0)
		{

		}
		~ImGuiRenderEndModule() = default;

	private:
		// Inherited via ApplicationModule
		virtual void OnInitialize() override;
		virtual void OnFinalize() override;
		virtual void OnTick() override;
		virtual void OnPreInvalidation() override;
		virtual void OnPostInvalidation() override;
	private:
		void InvalidateRenderTarget(const SharedHeap<GraphicsDevice>& pDevice);
	private:
		Array<SharedHeap<RenderTarget>> mRenderTargets;
		Vector2US mLastSwapchainSize;
		Byte mSwapchainBufferIndex;

	};
}
































































































