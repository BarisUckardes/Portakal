#include "RenderOperation.h"

namespace Portakal
{
	void RenderOperation::RegisterTexture(const String& name)
	{
		if (mTextures.Find(name) != nullptr)
			return;

		mTextures.Insert(name, {});
	}
	void RenderOperation::RegisterFloat32(const String& name)
	{
		if (mFloat32s.Find(name) != nullptr)
			return;

		mFloat32s.Insert(name, 1.0f);
	}
	void RenderOperation::RegisterColor(const String& name)
	{
		if (mColors.Find(name) != nullptr)
			return;

		mColors.Insert(name, {});
	}
	void RenderOperation::RegisterMaterial(const String& name)
	{
	}
	void RenderOperation::SetTexture(const String& name, const SharedHeap<TextureResource>& pTexture)
	{
		SharedHeap<TextureResource>* ppTexture = mTextures.Find(name);
		if (ppTexture == nullptr)
			return;

		*ppTexture = pTexture;
	}
	void RenderOperation::SetFloat32(const String& name, const Float32 value)
	{
		Float32* pValue = mFloat32s.Find(name);
		if (pValue == nullptr)
			return;

		*pValue = value;
	}
	void RenderOperation::SetColor(const String& name, const Color4F& value)
	{
		Color4F* pValue = mColors.Find(name);
		if (pValue == nullptr)
			return;

		*pValue = value;
	}
	void RenderOperation::SetMaterial(const String& name)
	{
	}
	void RenderOperation::SetTargetTexture(const SharedHeap<TextureResource>& pTexture)
	{
		mTargetTexture = pTexture;
	}
	void RenderOperation::RegisterOutput(RenderOperation* pOperation)
	{
		if (mOutputs.Has(pOperation))
			return;

		mOutputs.Add(pOperation);
	}
	void RenderOperation::Removeoutput(RenderOperation* pOperation)
	{
		mOutputs.Remove(pOperation);
	}
}
