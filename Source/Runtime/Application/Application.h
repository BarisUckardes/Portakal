#pragma once
#include <Runtime/Containers/Array.h>
#include <Runtime/Containers/String.h>
#include <Runtime/Application/ApplicationModuleState.h>
#include <Runtime/Application/ApplicationModule.h>
#include <Runtime/Object/Object.h>

namespace Portakal
{
	class RUNTIME_API Application
	{
		template<typename T>
		friend class API;
	public:
		static Application* GetCurrent()
		{
			return sApplication;
		}
	private:
		static inline Application* sApplication = nullptr;
	public:
		Application();
		~Application();

		template<typename T,typename... TArgs>
		void RegisterModule(const UInt32 index,TArgs... args)
		{
			T* pModule = new T(args...);
			pModule->_SetState(ApplicationModuleState::NeedsInitialization);
			mModules.AddAt(pModule, index);
		}

		template<typename T>
		T* GetModule() const noexcept
		{
			const Type* pTargetType = typeof(T);
			for (ApplicationModule* pModule : mModules)
				if (pModule->GetType() == pTargetType)
					return pModule;

			return nullptr;
		}

		void RemoveModule(const UInt32 index);
		void Run();
		void PostQuitRequest(const String& reason);
		void PostInvalidationRequest(const String& reason);
	protected:
		virtual void OnInitialize() {}
		virtual void OnFinalize() {}
		virtual void OnPreTick() {}
		virtual void OnPostTick() {}
	private:
		void _RegisterAPI(Object* pAPI);
		void _RemoveAPI(Object* pAPI);
	private:
		Array<ApplicationModule*> mModules;
		Array<Object*> mAPIs;
		String mQuitReason;
		Bool8 mQuitRequest;
		String mInvalidationReason;
		Bool8 mInvalidationRequest;

	};
}
