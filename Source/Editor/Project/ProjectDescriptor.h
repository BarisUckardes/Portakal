#pragma once
#include <Runtime/Containers/String.h>
#include <Runtime/Containers/Guid.h>
#include "ProjectDescriptor.reflected.h"

namespace Portakal
{
	PCLASS();
	class EDITOR_API ProjectDescriptor : public Class
	{
		GENERATE_OBJECT;
	public:
		ProjectDescriptor() = default;
		~ProjectDescriptor() = default;

		PFIELD();
		String Name;
		PFIELD();
		Guid ID;
		PFIELD();
		uint32 VersionMajor;
		PFIELD();
		uint32 VersionMinor;
		PFIELD();
		uint32 VersionPatch;
	};
}













































