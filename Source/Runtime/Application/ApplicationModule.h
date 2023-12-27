#pragma once
#include <Runtime/Application/ApplicationModuleState.h>
#include <Runtime/Reflection/Reflection.h>
#include "ApplicationModule.reflected.h"

namespace Portakal
{
	class Application;
	PCLASS();
	class RUNTIME_API ApplicationModule
	{
		friend class Application;
	public:
		FORCEINLINE ApplicationModuleState GetState() const noexcept
		{
			return mState;
		}
		FORCEINLINE Application* GetOwnerApplication() const noexcept
		{
			return mOwnerApplication;
		}

		virtual void OnInitialize() = 0;
		virtual void OnFinalize() = 0;
		virtual void OnTick() = 0;
	private:
		void _SetState(const ApplicationModuleState state);
		void _SetOwnerApplication(Application* pApplication);
	private:
		ApplicationModuleState mState;
		Application* mOwnerApplication;
	};
}


























































