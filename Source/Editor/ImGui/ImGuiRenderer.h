#pragma once
#include <Runtime/Object/Object.h>
#include <Runtime/Window/WindowEventData.h>
#include <Runtime/Graphics/Device/GraphicsDevice.h>
#include <Runtime/Graphics/RenderPass/RenderPass.h>
#include <Runtime/Resource/Mesh/MeshResource.h>
#include <Runtime/Resource/Texture/TextureResource.h>
#include <Runtime/Resource/RenderTarget/RenderTargetResource.h>
#include <Editor/ImGui/ImGuiTextureBinding.h>
#include <Runtime/Containers/HashMap.h>
#include <imgui.h>
#include <Runtime/Resource/Shader/ShaderResource.h>

namespace Portakal
{

#define IMGUI_MAX_RESOURCE_TABLES 8192
	class ImGuiTextureBinding;
	class EDITOR_API ImGuiRenderer : public Object
	{
		friend class ImGuiBeginModule;
		friend class ImGuiEndModule;

	public:
		ImGuiRenderer(const SharedHeap<GraphicsDevice>& pTargetDevice);
		ImGuiRenderer();
		~ImGuiRenderer();

		FORCEINLINE SharedHeap<GraphicsDevice> GetDevice() const noexcept
		{
			return mDevice;
		}

		void StartRendering(float deltaTimeInMilliSeconds);
		void EndRendering(const SharedHeap<RenderTargetResource>& pRenderTarget, const Color4F clearColor);

		SharedHeap<ImGuiTextureBinding> GetOrCreateTextureBinding(const SharedHeap<TextureResource>& pTexture);
		void DeleteTextureBinding(const SharedHeap<TextureResource>& pTexture);
		void ClearTextureBindings();

		void OnResized(const Vector2US newSize);
		void OnMouseMoved(const Vector2I mousePosition);
		void OnMouseButtonDown(const MouseButtons button);
		void OnMouseButtonUp(const MouseButtons button);
		void OnMouseWheel(float delta);
		void OnKeyboardKeyDown(const KeyboardKeys key);
		void OnKeyboardKeyUp(const KeyboardKeys key);
		void OnKeyboardChar(const Char value);
	private:
		void CreateImGuiResources();
		void SetupDefaultTheme();
	private:
		void InvalidateRenderTarget(const SharedHeap<RenderTargetResource>& pRenderTarget,const Byte subpassIndex);
		virtual void OnShutdown() override;

	private:
		ImGuiContext* mContext;

		SharedHeap<GraphicsDevice> mDevice;

		SharedHeap<CommandList> mCmdList;
		SharedHeap<CommandPool> mCmdPool;

		SharedHeap<GraphicsBuffer> mStagingBuffer;
		SharedHeap<GraphicsBuffer> mConstantBuffer;

		SharedHeap<MeshResource> mMesh;

		SharedHeap<ShaderResource> mVertexShader;
		SharedHeap<ShaderResource> mFragmentShader;

		SharedHeap<Sampler> mSampler;

		SharedHeap<TextureResource> mDefaultFontTexture;
		SharedHeap<ResourceTableLayout> mStaticResourceLayout;
		SharedHeap<ResourceTableLayout> mFontResourceLayout;

		SharedHeap<ResourceTable> mStaticResourceTable;
		SharedHeap<ResourceTable> mFontResourceTable;

		SharedHeap<Pipeline> mPipeline;
		SharedHeap<Fence> mFence;
		Array<SharedHeap<RenderTargetResource>> mRenderTargets;
		HashMap<SharedHeap<TextureResource>, SharedHeap<ImGuiTextureBinding>> mTextureBindings;
	};
}
