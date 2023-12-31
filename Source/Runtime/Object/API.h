#pragma once
#include <Runtime/Core/Core.h>
#include <Runtime/Object/Object.h>

namespace Portakal
{
	/**
	 * @class API
	 * @brief Highly protected dynamic singleton class 
	 * for Low Level Abstraction Layers.
	 */
	template<typename T>
	class RUNTIME_API API : public Object
	{
	protected:
		static T* GetUnderlyingAPI() noexcept { return sUnderlyingAPI; }
	private:
		static inline T* sUnderlyingAPI = nullptr;
	public:
		API()
		{
			sUnderlyingAPI = (T*)this;
		}

		virtual void OnShutdown() override
		{
			sUnderlyingAPI = nullptr;
		}
	};
}