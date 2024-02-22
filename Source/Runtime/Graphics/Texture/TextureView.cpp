#include "TextureView.h"

namespace Portakal
{
	TextureView::TextureView(const TextureViewDesc& desc,GraphicsDevice* pDevice) : GraphicsDeviceObject(pDevice),mTargetTexture(desc.pTexture),mArrayLevel(desc.ArrayLevel),mMipLevel(desc.MipLevel)
	{

	}
}
