#include "Object.h"

namespace Portakal
{
	void Object::SetName(const String& name)
	{
		if (IsShutdown())
			return;

		OnNameChange(name);
		mName = name;
	}
	void Object::OverrideID(const Guid& id)
	{
		if (IsShutdown())
			return;

		OnIDChange(id);
		mID = id;
	}
	void Object::Shutdown()
	{
		if (IsShutdown())
			return;

		OnShutdown();

		mShutdown = true;
	}
}
