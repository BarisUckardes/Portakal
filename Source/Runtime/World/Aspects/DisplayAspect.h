#pragma once
#include <Runtime/World/SceneAspect.h>
#include "DisplayAspect.reflected.h"

namespace Portakal
{
	PCLASS();
	class RUNTIME_API DisplayAspect : public SceneAspect
	{
		GENERATE_OBJECT;
	public:
		DisplayAspect() = default;
		~DisplayAspect() = default;

		// Inherited via SceneAspect
		void OnInitialize() override;
		void OnExecute() override;
		void OnFinalize() override;
	};
}

