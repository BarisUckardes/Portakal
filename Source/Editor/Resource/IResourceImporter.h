#pragma once
#include <Runtime/Core/Core.h>
#include <Runtime/Containers/String.h>
#include <Runtime/Object/Object.h>
#include "IResourceImporter.reflected.h"

namespace Portakal
{
	class DomainFolder;

	PCLASS(Virtual);
	class EDITOR_API IResourceImporter
	{
	public:
		IResourceImporter() = default;
		~IResourceImporter() = default;

		virtual void OnImport(DomainFolder* pFolder, const String& sourcePath) = 0;
	};
}


