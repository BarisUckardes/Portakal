#pragma once
#include <Editor/GUI/Window/GUIWindow.h>
#include <Runtime/World/Scene.h>
#include "WorldWindow.reflected.h"

namespace Portakal
{
	PCLASS();
	class EDITOR_API WorldWindow : public GUIWindow
	{
		GENERATE_OBJECT;
	public:
		WorldWindow() = default;
		~WorldWindow() = default;

	private:
		void OnSceneChanged(const SharedHeap<Scene>& pScene);
		// Inherited via GUIWindow
		virtual void OnShutdown() override;
		virtual void OnShow() override;
		virtual void OnHide() override;
		virtual void OnPaint() override;
		virtual void OnInitialize() override;
	private:
		SharedHeap<Scene> mTargetScene;
	};
}





































