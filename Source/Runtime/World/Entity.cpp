#include "Entity.h"

namespace Portakal
{
	void Entity::_SetOwnerScene(Scene* pScene)
	{
		mOwnerScene = pScene;
	}
	void Entity::OnShutdown()
	{

	}
}
