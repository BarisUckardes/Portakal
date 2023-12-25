#pragma once
#include <Runtime/Containers/Array.h>
#include <Runtime/Memory/SharedHeap.h>

namespace Portakal
{
	class SceneAspect;
	class Entity;
	class RUNTIME_API Scene : public Object
	{
	public:
		Scene();
		~Scene();
	private:
		Array<SharedHeap<Entity>> mEntities;
	};
}
