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
		Uint32 VersionMajor;
		PFIELD();
		Uint32 VersionMinor;
		PFIELD();
		Uint32 VersionPatch;
	};
}



























































































































































