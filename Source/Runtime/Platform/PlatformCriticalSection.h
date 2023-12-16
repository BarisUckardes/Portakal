#pragma once
#include <Runtime/Object/Object.h>
#include <Runtime/Memory/SharedHeap.h>

namespace Portakal
{
	class RUNTIME_API PlatformCriticalSection : public Object
	{
	public:
		static SharedHeap<PlatformCriticalSection> Create();
	public:
		PlatformCriticalSection() = default;
		~PlatformCriticalSection() = default;

		FORCEINLINE virtual bool TryEnter() = 0;
		FORCEINLINE virtual void Enter() = 0;
		FORCEINLINE virtual void Leave() = 0;
	};
}
