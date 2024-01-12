#pragma once
#include <Runtime/Core/Core.h>
#include <Runtime/Reflection/Reflection.h>
#include <Runtime/Memory/SharedHeap.h>
#include <Runtime/Containers/HashMap.h>
#include <Runtime/Math/Color4.h>
#include <Runtime/Resource/Texture/TextureResource.h>
#include "RenderOperation.reflected.h"

namespace Portakal
{
	PCLASS(Virtual);
	class RUNTIME_API RenderOperation : public Object
	{
		GENERATE_OBJECT;
	public:
		RenderOperation() = default;
		~RenderOperation() = default;

		FORCEINLINE const Array<RenderOperation*>& GetOutputs() const noexcept
		{
			return mOutputs;
		}
		FORCEINLINE SharedHeap<TextureResource> GetTargetTexture() const noexcept
		{
			return mTargetTexture;
		}

		void RegisterTexture(const String& name);
		void RegisterFloat(const String& name);
		void RegisterColor(const String& name);
		void RegisterMaterial(const String& name); //TODO!

		void SetTexture(const String& name, const SharedHeap<TextureResource>& pTexture);
		void SetFloat(const String& name, const float value);
		void SetColor(const String& name, const Color4F& value);
		void SetMaterial(const String& name); //TODO!

		void SetTargetTexture(const SharedHeap<TextureResource>& pTexture);
		void RegisterOutput(RenderOperation* pOperation);
		void Removeoutput(RenderOperation* pOperation);

		virtual void Execute() = 0;
	private:
		HashMap<String, SharedHeap<TextureResource>> mTextures;
		HashMap<String, float> mFloats;
		HashMap<String, Color4F> mColors;
		SharedHeap<TextureResource> mTargetTexture;
		Array<RenderOperation*> mOutputs;
	};
}















































































































































































































































