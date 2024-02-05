#include "BasicCamera.h"
#include <Runtime/World/Scene.h>
#include <Runtime/Rendering/Builtin/BasicRenderAspect.h>
#include <Runtime/World/Aspects/DisplayAspect.h>
#include <Runtime/Graphics/GraphicsAPI.h>

namespace Portakal
{
	
	void BasicCamera::SetFieldOfView(const Float32 value)
	{
		mFieldOfView = value;
	}
	void BasicCamera::SetNearPlane(const Float32 value)
	{
		mNearPlane = value;
	}
	void BasicCamera::SetFarPlane(const Float32 value)
	{
		mFarPlane = value;
	}
	void BasicCamera::SetRenderTarget(const SharedHeap<RenderTarget>& pResource)
	{

	}
	void BasicCamera::OnInitialize()
	{
		GetOwnerEntity()->GetOwnerScene()->GetAspect<BasicRenderAspect>()->RegisterCamera(this);
	}
	void BasicCamera::OnShutdown()
	{
		GetOwnerEntity()->GetOwnerScene()->GetAspect<BasicRenderAspect>()->RemoveCamera(this);
	}
}
