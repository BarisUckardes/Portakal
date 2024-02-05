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
		virtual void OnInitialize() override;
		virtual void OnFinalize() override;
		virtual void OnTick() override;
		virtual void OnPreInvalidation() override;
		virtual void OnPostInvalidation() override;
	private:
		EditorResourceAPI* mAPI;
	};
}





































