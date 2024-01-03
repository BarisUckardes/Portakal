#pragma once
#include <Runtime/Application/ApplicationModule.h>
#include <Runtime/Platform/PlatformWindow.h>
#include "EditorPlayerWindowModule.reflected.h"

namespace Portakal
{
	PCLASS();
	class EditorPlayerWindowModule : public ApplicationModule
	{
		GENERATE_OBJECT;
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















































