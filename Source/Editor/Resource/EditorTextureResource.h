#pragma once
#include <Editor/Resource/EditorResource.h>
#include <Runtime/Resource/Texture/TextureResource.h>

namespace Portakal
{
	class EDITOR_API EditorTextureResource final : public EditorResource
	{
	public:
		EditorTextureResource(const String& path);
		~EditorTextureResource() = default;


		virtual void OnShutdown() override;
	private:
		EditorResourceType GetResourceType() const noexcept override final
		{
			return EditorResourceType::Texture;
		}
		SharedHeap<ResourceSubObject> GetResource()  noexcept override final
		{
			return mTexture.QueryAs<ResourceSubObject>();
		}
	private:
		SharedHeap<TextureResource> mTexture;
		SharedHeap<GraphicsMemoryHeap> mHostHeap;
		SharedHeap<GraphicsMemoryHeap> mDeviceHeap;

		// Inherited via EditorResource
	};
}
