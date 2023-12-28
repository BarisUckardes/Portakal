#pragma once
#include <Runtime/Containers/String.h>
#include <Runtime/Containers/Guid.h>
#include <Runtime/Reflection/Reflection.h>
#include "Object.reflected.h"

namespace Portakal
{
	/**
	 * @class Object
	 * @brief Base class for all objects in the whole system.
	 */
	PCLASS();
	class RUNTIME_API Object
	{
	public:
		Object() : mShutdown(false), mID(Guid::Create()) {}
		virtual ~Object() = default;

		FORCEINLINE bool IsShutdown() const noexcept { return mShutdown; }
		FORCEINLINE String GetName() const noexcept { return mName; }
		FORCEINLINE Guid GetID() const noexcept { return mID; }

		void SetName(const String& name);
		void OverrideID(const Guid& id) { mID = id; }
		void Shutdown();
		virtual Type* GetType() const noexcept { return nullptr; }
	protected:
		virtual void OnShutdown() = 0;
		virtual void OnNameChange(const String& name) {}
	private:
		String mName;
		Guid mID;
		bool mShutdown;
	};
}





































































