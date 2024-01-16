#pragma once
#include <Runtime/Application/ApplicationModule.h>
#include <Editor/GUI/Object/EditorObjectAPI.h>
#include "EditorObjectModule.reflected.h"

namespace Portakal
{
	PCLASS();
	class EDITOR_API EditorObjectModule : public ApplicationModule
	{
		GENERATE_OBJECT;
	public:
		EditorObjectModule() : mAPI(nullptr)
		{

		}
		~EditorObjectModule() = default;

	private:
		EditorObjectAPI* mAPI;

		// Inherited via ApplicationModule
		void OnInitialize() override;
		void OnFinalize() override;
		void OnTick() override;
	};
}

