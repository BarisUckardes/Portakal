#include "TextureView.h"

namespace Portakal
{
	TextureView::~TextureView()
	{
	}
	TextureView::TextureView(const TextureViewDesc& desc, GraphicsDevice* pDevice) : GraphicsDeviceObject(pDevice),mTexture(desc.pTexture),mArrayLevel(desc.ArrayLevel),mMipLevel(desc.MipLevel)
	{
	}
}
