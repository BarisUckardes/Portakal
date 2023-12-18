#include "TextureView.h"

namespace Portakal
{
	TextureView::TextureView(const TextureViewDesc& desc) : mTargetTexture(desc.pTexture),mArrayLevel(desc.ArrayLevel),mMipLevel(desc.MipLevel)
	{

	}
}
