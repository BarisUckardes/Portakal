#pragma once
#include <Runtime/World/Component.h>
#include <Runtime/Resource/Mesh/MeshResource.h>
#include <Runtime/Resource/Material/MaterialResource.h>

namespace Portakal
{
	class RUNTIME_API BasicRenderable : public Component
	{
	public:
		BasicRenderable() = default;
		~BasicRenderable() = default;

	private:
		// Inherited via Component
		virtual void OnInitialize() override;
		virtual void OnShutdown() override;
	};
}
