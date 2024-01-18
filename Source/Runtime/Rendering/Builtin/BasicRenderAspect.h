#pragma once
#include <Runtime/World/SceneAspect.h>
#include <Runtime/Rendering/Builtin/BasicCamera.h>
#include <Runtime/Rendering/Builtin/BasicRenderable.h>
#include "BasicRenderAspect.reflected.h"

namespace Portakal
{
	PCLASS();
	class RUNTIME_API BasicRenderAspect : public SceneAspect
	{
		GENERATE_OBJECT;
	public:
		BasicRenderAspect() = default;
		~BasicRenderAspect() = default;

		void RegisterCamera(const BasicCamera* pCamera);
		void RemoveCamera(const BasicCamera* pCamera);

		void RegisterRenderable(const BasicRenderable* pRenderable);
		void RemoveRenderable(const BasicRenderable* pRenderable);
	private:
		// Inherited via SceneAspect
		void OnInitialize() override;
		void OnExecute() override;
	private:
		Array<const BasicCamera*> mCameras;
		Array<const BasicRenderable*> mRenderables;
		SharedHeap<TextureResource> mTexture;
		SharedHeap<CommandPool> mCmdPool;
		SharedHeap<CommandList> mCmdList;
		SharedHeap<Shader> mVertexShader;
		SharedHeap<Shader> mFragmentShader;
	};
}

