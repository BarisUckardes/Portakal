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

		FORCEINLINE SharedHeap<TextureResource> GetTexture() const noexcept
		{
			return mTexture;
		}
		EditorResourceType GetResourceType() const noexcept override final
		{
			return EditorResourceType::Texture;
		}
		virtual void OnShutdown() override;
	private:
		SharedHeap<TextureResource> mTexture;
	};
}
