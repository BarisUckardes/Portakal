#pragma once
#include <Runtime/Containers/String.h>
#include <Runtime/Containers/Guid.h>

namespace Portakal
{
	/**
	 * @class Object
	 * @brief Base class for all objects in the whole system.
	 */
	class RUNTIME_API Object
	{
	public:
		Object() : mShutdown(false), mID(Guid::Create())
		{
		}

		virtual ~Object() = default;

		FORCEINLINE bool IsShutdown() const noexcept { return mShutdown; }
		FORCEINLINE String GetName() const noexcept { return mName; }
		FORCEINLINE Guid GetID() const noexcept { return mID; }

		void SetName(const String& name)
		{
			OnNameChange(name);
			mName = name;
		}

		void OverrideID(const Guid& id) { mID = id; }

		void Shutdown()
		{
			if (IsShutdown())
				return;

			OnShutdown();

			mShutdown = true;
		}

	protected:
		virtual void OnShutdown() = 0;
		virtual void OnNameChange(const String& name)
		{

		}

	private:
		String mName;
		Guid mID;
		bool mShutdown;
	};
}
