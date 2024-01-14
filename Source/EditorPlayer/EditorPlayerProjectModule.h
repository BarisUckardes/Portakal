#pragma once
#include <Runtime/Application/ApplicationModule.h>
#include "EditorPlayerProjectModule.reflected.h"

namespace Portakal
{
	PCLASS();
	class EditorPlayerProjectModule : public ApplicationModule
	{
		GENERATE_OBJECT;
	public:
		EditorPlayerProjectModule() = default;
		~EditorPlayerProjectModule() = default;
	private:
		// Inherited via ApplicationModule
		void OnInitialize() override;
		void OnFinalize() override;
		void OnTick() override;
	};
}























































































