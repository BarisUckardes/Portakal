#pragma once

#include <Runtime/Application/ApplicationModule.h>
#include <Runtime/Memory/SharedHeap.h>

namespace Portakal
{
	class GUIWindowAPI;
	class GUIRenderingContext;

	class EDITOR_API GUIWindowModule : public ApplicationModule
	{
	public:
		GUIWindowModule() : mAPI(nullptr), mDockstate(false), mLayoutDirty(true)
		{

		}
		~GUIWindowModule() = default;

	private:
		// Inherited via ApplicationModule
		void OnInitialize() override;
		void OnFinalize() override;
		void OnTick() override;
	private:
		void CreateDefaultWindowSettings();
		void LoadWindowSettings();
		void SaveWindowSettings();
	private:
		SharedHeap<GUIRenderingContext> mRenderingContext;
		GUIWindowAPI* mAPI;
		bool mDockstate;
		bool mLayoutDirty;

	};
}
