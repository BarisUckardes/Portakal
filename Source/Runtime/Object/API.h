#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
	template<typename T>
	class RUNTIME_API API
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
		~API()
		{
			sUnderlyingAPI = nullptr;
		}

	};
}