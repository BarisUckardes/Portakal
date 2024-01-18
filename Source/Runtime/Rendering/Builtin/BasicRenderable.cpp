#include "BasicRenderable.h"
#include <Runtime/World/Scene.h>
#include <Runtime/Rendering/Builtin/BasicRenderAspect.h>

namespace Portakal
{
	void BasicRenderable::OnInitialize()
	{
		GetOwnerEntity()->GetOwnerScene()->GetAspect<BasicRenderAspect>()->RegisterRenderable(this);
	}
	void BasicRenderable::OnShutdown()
	{
		GetOwnerEntity()->GetOwnerScene()->GetAspect<BasicRenderAspect>()->RemoveRenderable(this);
	}
}
