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
		UInt32 VersionMajor;
		PFIELD();
		UInt32 VersionMinor;
		PFIELD();
		UInt32 VersionPatch;
	};
}







































































































































































