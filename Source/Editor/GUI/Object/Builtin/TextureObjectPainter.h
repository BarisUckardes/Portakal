#pragma once
#include <Runtime/Resource/Texture/TextureResource.h>
#include <Editor/GUI/Object/IObjectPainter.h>
#include "TextureObjectPainter.reflected.h"
#include <Editor/ImGui/ImGuiTextureBinding.h>

namespace Portakal
{
	PATTRIBUTE(CustomObjectPainter, typeof(Portakal::TextureResource));
	PCLASS();
	class EDITOR_API TextureObjectPainter : public IObjectPainter
	{
		GENERATE_OBJECT;
	public:
		TextureObjectPainter() = default;
		~TextureObjectPainter() = default;

	private:
		// Inherited via IObjectPainter
		void OnInitialize() override;
		void OnPaint() override;
	private:
		SharedHeap<TextureResource> mTexture;
		SharedHeap<ImGuiTextureBinding> mTextureBinding;
	};
}

