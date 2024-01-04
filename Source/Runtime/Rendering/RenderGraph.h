#pragma once
#include <Runtime/Graphics/Device/GraphicsDevice.h>
#include <Runtime/Graphics/RenderPass/RenderPass.h>
#include <Runtime/Resource/Mesh/MeshResource.h>
#include <Runtime/Resource/Texture/TextureResource.h>
#include <Runtime/Graphics/Pipeline/Pipeline.h>
#include <Runtime/Containers/HashMap.h>
#include <Runtime/Rendering/RenderOperation.h>
#include "RenderGraph.reflected.h"

namespace Portakal
{
	PCLASS();
	class RUNTIME_API RenderGraph : public Object
	{
		GENERATE_OBJECT;
	public:
		RenderGraph();
		~RenderGraph() = default;

		void RegisterTexture(const String& name, const SharedHeap<TextureResource>& pTexture);
		void RemoveTexture(const String& name);

		void RegisterOperation(RenderOperation* pOperation);
		void RemoveRenderOperation(RenderOperation* pOperation);

		void SetBeginOperation(RenderOperation* pOperation);
		void SetEndOperation(RenderOperation* pOperation);

		void Build();
		void Execute();
	private:
		virtual void OnShutdown() override;
	private:
		HashMap<String, SharedHeap<TextureResource>> mTextures;
		Array<RenderOperation*> mOperations;
		Array<Array<RenderOperation*>> mRenderPath;
		RenderOperation* mBeginOperation;
		RenderOperation* mEndOperation;
	};
}




























































































































































































































