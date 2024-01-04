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
	PCLASS(Virtual);
	class RUNTIME_API Object : public Class
	{
	public:
		Object() : mShutdown(false), mID(Guid::Create()) {}
		virtual ~Object() = default;

		FORCEINLINE Bool8 IsShutdown() const noexcept { return mShutdown; }
		FORCEINLINE String GetName() const noexcept { return mName; }
		FORCEINLINE Guid GetID() const noexcept { return mID; }

		void SetName(const String& name);
		void OverrideID(const Guid& id) { mID = id; }
		void Shutdown();
	protected:
		virtual void OnShutdown() = 0;
		virtual void OnNameChange(const String& name) {}
		virtual void OnIdChanged(const Guid& id) {}
	private:
		String mName;
		Guid mID;
		Bool8 mShutdown;
	};
}































































































































































































































































