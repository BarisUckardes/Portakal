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
		FORCEINLINE Float32 GetFieldOfView() const noexcept
		{
			return mFieldOfView;
		}
		FORCEINLINE Float32 GetNearPlane() const noexcept
		{
			return mNearPlane;
		}
		FORCEINLINE Float32 GetFarPlane() const noexcept
		{
			return mFarPlane;
		}

		void TestCreateDisplay();
		void SetFieldOfView(const Float32 value);
		void SetNearPlane(const Float32 value);
		void SetFarPlane(const Float32 value);
		void SetRenderTarget(const SharedHeap<RenderTargetResource>& pResource);
	public:
		PFIELD();
		Float32 mFieldOfView;
		PFIELD();
		Float32 mNearPlane;
		PFIELD();
		Float32 mFarPlane;
	private:
		// Inherited via Component
		virtual void OnInitialize() override;
		virtual void OnShutdown() override;
	private:
		SharedHeap<RenderTargetResource> mRenderTarget;
		SharedHeap<TextureResource> mTestTexture;
		SharedHeap<GraphicsMemoryHeap> mTestHeap;
	};
}

