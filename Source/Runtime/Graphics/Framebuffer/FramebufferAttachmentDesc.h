#pragma once
#include <Runtime/Core/Core.h>
#include <Runtime/Memory/SharedHeap.h>

namespace Portakal
{
	class Texture;
	struct RUNTIME_API FramebufferAttachmentDesc
	{
		SharedHeap<Texture> pTexture;
		byte MipLevel;
		byte ArrayLevel;
	};
}
