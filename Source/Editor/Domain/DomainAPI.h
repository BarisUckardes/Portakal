#pragma once
#include <Runtime/Core/Core.h>
#include <Runtime/Object/API.h>
#include <Runtime/Containers/String.h>

namespace Portakal
{
	class EDITOR_API DomainAPI : public API<DomainAPI>
	{
	public:
		DomainAPI(const String& folderPath);
		~DomainAPI();

	private:
		const String mFolderPath;
	};
}
