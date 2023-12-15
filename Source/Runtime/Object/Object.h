#pragma once
#include <Runtime/Containers/String.h>
#include <Runtime/Containers/Guid.h>
#include <Runtime/Memory/SharedHeap.h>

namespace Portakal
{
	class RUNTIME_API Object
	{
	public:
		Object() : mShutdown(false), mID(Guid::Create())
		{

		}
		~Object() = default;

		FORCEINLINE bool IsShutdown() const noexcept
		{
			return mShutdown;
		}
		FORCEINLINE String GetName() const noexcept
		{
			return mName;
		}
		FORCEINLINE Guid GetID() const noexcept
		{
			return mID;
		}

		void SetName(const String& name)
		{
			OnNameChange(name);
			mName = name;
		}
		void OverrideID(const Guid& id)
		{
			mID = id;
		}
		void Shutdown()
		{
			if (IsShutdown())
				return;

			OnShutdown();

			mShutdown = true;
		}
	protected:
		virtual void OnShutdown() = 0;
		virtual void OnNameChange(const String& name) = 0;
	private:
		String mName;
		Guid mID;
		bool mShutdown;
	};
}
