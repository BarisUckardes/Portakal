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
		virtual void OnInitialize() override;
		virtual void OnFinalize() override;
		virtual void OnTick() override;
		virtual void OnPreInvalidation() override;
		virtual void OnPostInvalidation() override;
	private:
		SharedHeap<PlatformWindow> mWindow;
	};
}





































































































