#pragma once
#include <Runtime/Core/Core.h>
#include <Runtime/Memory/SharedHeap.h>

namespace Portakal
{
	class IThumbnail : public Object
	{
	public:
		IThumbnail() = default;
		~IThumbnail() = default;

		virtual void OnInitialize()
		{

		}
		virtual SharedHeap<TextureResource> GetCurrentThumbnail()
		{
			return nullptr;
		}

	};
}
