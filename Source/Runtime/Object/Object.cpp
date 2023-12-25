#include "Object.h"

namespace Portakal
{
	void Object::SetName(const String& name)
	{
		OnNameChange(name);
		mName = name;
	}
	void Object::Shutdown()
	{
		if (IsShutdown())
			return;

		OnShutdown();

		mShutdown = true;
	}
}
