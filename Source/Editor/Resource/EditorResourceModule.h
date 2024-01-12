#pragma once
#include <Runtime/Application/ApplicationModule.h>
#include <Editor/Resource/EditorResourceAPI.h>
#include "EditorResourceModule.reflected.h"

namespace Portakal
{
	PCLASS();
	class EDITOR_API EditorResourceModule : public ApplicationModule
	{
		GENERATE_OBJECT;
	public:
		EditorResourceModule() = default;
		~EditorResourceModule() = default;

		// Inherited via ApplicationModule
		void OnInitialize() override;
		void OnFinalize() override;
		void OnTick() override;
	private:
		EditorResourceAPI* mAPI;
	};
}

