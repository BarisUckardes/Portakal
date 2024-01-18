#pragma once
#include <Runtime/World/Component.h>
#include <Runtime/Resource/RenderTarget/RenderTargetResource.h>
#include "BasicCamera.reflected.h"

namespace Portakal
{
	PCLASS();
	class RUNTIME_API BasicCamera : public Component
	{
		GENERATE_OBJECT;
	public:
		BasicCamera() : mFieldOfView(60), mNearPlane(0), mFarPlane(1000)
		{

		}
		~BasicCamera() = default;

		FORCEINLINE SharedHeap<RenderTargetResource> GetRenderTarget() const noexcept
		{
			return mRenderTarget;
		}
		FORCEINLINE float GetFieldOfView() const noexcept
		{
			return mFieldOfView;
		}
		FORCEINLINE float GetNearPlane() const noexcept
		{
			return mNearPlane;
		}
		FORCEINLINE float GetFarPlane() const noexcept
		{
			return mFarPlane;
		}

		void TestCreateDisplay();
		void SetFieldOfView(const float value);
		void SetNearPlane(const float value);
		void SetFarPlane(const float value);
		void SetRenderTarget(const SharedHeap<RenderTargetResource>& pResource);
	private:
		// Inherited via Component
		virtual void OnInitialize() override;
		virtual void OnShutdown() override;
	private:
		SharedHeap<RenderTargetResource> mRenderTarget;
		SharedHeap<TextureResource> mTestTexture;
		SharedHeap<GraphicsMemoryHeap> mTestHeap;
		float mFieldOfView;
		float mNearPlane;
		float mFarPlane;

	};
}

