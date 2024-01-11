#pragma once
#include <Runtime/Core/Core.h>

namespace Portakal
{
	class RUNTIME_API IJob 
	{
	public:
		IJob() = default;
		~IJob() = default;

		virtual void OnRun()
		{

		}
	};
}
