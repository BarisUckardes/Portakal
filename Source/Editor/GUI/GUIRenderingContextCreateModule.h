#pragma once

#include <Runtime/Application/ApplicationModule.h>

#include <Editor/GUI/GUIRenderingContext.h>

namespace Portakal
{
	class EDITOR_API GUIRenderingContextCreateModule : public ApplicationModule
	{
	public:
		FORCEINLINE const SharedHeap<GUIRenderingContext>& GetRenderingContext() const noexcept { return mGUIRenderingContext; }

	private:
		// Inherited via ApplicationModule
		void OnInitialize() override;
		void OnFinalize() override;
		void OnTick() override;

	private:
		SharedHeap<GUIRenderingContext> mGUIRenderingContext;
	};
}