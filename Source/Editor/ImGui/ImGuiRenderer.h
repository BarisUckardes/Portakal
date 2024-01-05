#pragma once

#include <Runtime/Object/Object.h>
#include <Runtime/Window/WindowEventData.h>
#include <Runtime/Graphics/Device/GraphicsDevice.h>
#include <Runtime/Graphics/RenderPass/RenderPass.h>
#include <Runtime/Resource/Mesh/MeshResource.h>
#include <Runtime/Resource/Texture/TextureResource.h>
#include <Runtime/Resource/RenderTarget/RenderTarget.h>
#include <Runtime/Containers/HashMap.h>
#include <imgui.h>

namespace Portakal
{
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
		void EndRendering(const SharedHeap<RenderTarget>& pRenderTarget, const Color4F clearColor);

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
		void InvalidateRenderTarget(const SharedHeap<RenderTarget>& pRenderTarget,const Byte subpassIndex);
		virtual void OnShutdown() override;

	private:
		ImGuiContext* mContext;

		SharedHeap<GraphicsDevice> mDevice;

		SharedHeap<CommandList> mCmdList;
		SharedHeap<CommandPool> mCmdPool;
		SharedHeap<GraphicsMemoryHeap> mDeviceMemory;
		SharedHeap<GraphicsMemoryHeap> mHostMemory;

		SharedHeap<GraphicsBuffer> mStagingBuffer;
		SharedHeap<GraphicsBuffer> mConstantBuffer;

		SharedHeap<MeshResource> mMesh;

		SharedHeap<Shader> mVertexShader;
		SharedHeap<Shader> mFragmentShader;

		SharedHeap<Sampler> mSampler;

		SharedHeap<TextureResource> mDefaultFontTexture;
		SharedHeap<ResourceTableLayout> mStaticResourceLayout;
		SharedHeap<ResourceTableLayout> mFontResourceLayout;

		SharedHeap<ResourceTablePool> mResourcePool;
		SharedHeap<ResourceTable> mStaticResourceTable;
		SharedHeap<ResourceTable> mFontResourceTable;

		SharedHeap<Pipeline> mPipeline;
		SharedHeap<Fence> mFence;
		Array<SharedHeap<RenderTarget>> mRenderTargets;
	};
}
