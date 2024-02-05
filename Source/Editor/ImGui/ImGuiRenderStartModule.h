#pragma once
#include <Runtime/Application/ApplicationModule.h>
#include "ImGuiRenderStartModule.reflected.h"

namespace Portakal
{
	PCLASS();
	class EDITOR_API ImGuiRenderStartModule : public ApplicationModule
	{
		GENERATE_OBJECT;
	public:
		ImGuiRenderStartModule() = default;
		~ImGuiRenderStartModule() = default;

	private:
		// Inherited via ApplicationModule
		virtual void OnInitialize() override;
		virtual void OnFinalize() override;
		virtual void OnTick() override;
		virtual void OnPreInvalidation() override;
		virtual void OnPostInvalidation() override;
	private:

	};
}
































































































