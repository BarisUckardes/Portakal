#pragma once
#include <Runtime/World/SceneAspect.h>
#include <Runtime/Resource/RenderTarget/RenderTarget.h>
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

		FORCEINLINE const Array<SharedHeap<RenderTarget>> GetDisplays() const noexcept
		{
			return mDisplays;
		}
		FORCEINLINE SharedHeap<RenderTarget> GetPrimaryDisplay() const noexcept
		{
			return mDisplays.IsEmpty() ? nullptr : mDisplays[0];
		}

		void RegisterDisplay(const SharedHeap<RenderTarget>& pDisplay);
		void RemoveDisplay(const SharedHeap<RenderTarget>& pDisplay);
	private:
		// Inherited via SceneAspect
		void OnInitialize() override;
		void OnExecute() override;
	private:
		Array<SharedHeap<RenderTarget>> mDisplays;
	};
}

