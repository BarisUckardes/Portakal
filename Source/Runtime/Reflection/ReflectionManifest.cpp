#include "ReflectionManifest.h"

namespace Portakal
{
	ReflectionManifest::~ReflectionManifest()
	{
		for (Type* pType : mTypes)
			delete pType;
	}
}
