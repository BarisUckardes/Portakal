#include "EditorResourceAPI.h"
#include <Runtime/Platform/PlatformPaths.h>
#include <Runtime/Platform/PlatformDirectory.h>
#include <Runtime/Platform/PlatformFile.h>
#include <Editor/Resource/EditorTextureResource.h>

namespace Portakal
{
	SharedHeap<EditorResource> EditorResourceAPI::GetResource(const String& name)
	{
		//Get API
		EditorResourceAPI* pAPI = GetUnderlyingAPI();
		if (pAPI == nullptr)
			return nullptr;

		//Get resource
		SharedHeap<EditorResource>* pResource = pAPI->mResources.Find(name);
		if (pResource == nullptr)
			return nullptr;

		return *pResource;
	}
	EditorResourceAPI::EditorResourceAPI()
	{
		//Get editor path
		const String path = PlatformPaths::GetProgramsPath() + "\\Portakal\\Editor\\Resources\\";

		//Collect and load textures
		Array<String> pngFiles;
		if (!PlatformDirectory::GetFileNamesViaExtension(path + "Icons\\", ".png", pngFiles))
		{
			DEV_LOG("EditorResourceAPI", "Failed to get .png files");
			return;
		}

		for (const String& file : pngFiles)
		{
			//Get name
			const String fileName = PlatformFile::GetNameWithoutExtension(file);
			DEV_LOG("EditorResourceAPI", "Found png %s", *fileName);
			//Create resource
			SharedHeap<EditorResource> pResource = new EditorTextureResource(file);

			//Add reg
			mResources.Insert(fileName, pResource);
		}
	}
	EditorResourceAPI::~EditorResourceAPI()
	{

	}
}
