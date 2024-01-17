#pragma once
#include <Runtime/Core/Core.h>
#include <Runtime/Object/API.h>
#include <Runtime/Containers/String.h>
#include <Editor/Domain/DomainFolder.h>

namespace Portakal
{
	class EDITOR_API DomainAPI : public API<DomainAPI>
	{
		friend class DomainModule;
	public:
		static void Invalidate();
		static SharedHeap<DomainFolder> GetRootFolder();
		static SharedHeap<DomainFile> GetFile(const String& name);
		static SharedHeap<DomainFile> GetFile(const Guid& id);
	private:
		DomainAPI(const String& folderPath);
		~DomainAPI();

	private:
		const String mFolderPath;
		SharedHeap<DomainFolder> mRootFolder;
	};
}
