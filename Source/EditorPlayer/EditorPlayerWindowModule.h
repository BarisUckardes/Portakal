#pragma once
#include <Runtime/Application/ApplicationModule.h>
#include <Runtime/Platform/PlatformWindow.h>

namespace Portakal
{
	class RUNTIME_API EditorPlayerWindowModule : public ApplicationModule
	{
	public:
		EditorPlayerWindowModule() = default;
		~EditorPlayerWindowModule() = default;
	private:
		// Inherited via ApplicationModule
		void OnInitialize() override;
		void OnFinalize() override;
		void OnTick() override;
	private:
		SharedHeap<PlatformWindow> mWindow;

	};
}
