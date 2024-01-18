#pragma once
#include <Runtime/World/SceneAspect.h>
#include <Runtime/Resource/RenderTarget/RenderTargetResource.h>
#include <Runtime/Containers/HashMap.h>
#include "DisplayAspect.reflected.h"

namespace Portakal
{
	PCLASS();
	class RUNTIME_API DisplayAspect : public SceneAspect
	{
		GENERATE_OBJECT;
	public:
		DisplayAspect() = default;
		~DisplayAspect() = default;

		FORCEINLINE const Array<SharedHeap<RenderTargetResource>> GetDisplays() const noexcept
		{
			return mDisplays;
		}
		FORCEINLINE SharedHeap<RenderTargetResource> GetPrimaryDisplay() const noexcept
		{
			return mDisplays.IsEmpty() ? nullptr : mDisplays[0];
		}

		void RegisterDisplay(const SharedHeap<RenderTargetResource>& pDisplay);
		void RemoveDisplay(const SharedHeap<RenderTargetResource>& pDisplay);
	private:
		// Inherited via SceneAspect
		void OnInitialize() override;
		void OnExecute() override;
	private:
		Array<SharedHeap<RenderTargetResource>> mDisplays;
	};
}

