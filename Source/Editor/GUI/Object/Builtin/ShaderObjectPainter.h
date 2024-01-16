#pragma once
#include <Editor/GUI/Object/IObjectPainter.h>
#include <Runtime/Resource/Shader/ShaderResource.h>
#include "ShaderObjectPainter.reflected.h"

namespace Portakal
{
	PATTRIBUTE(CustomObjectPainter, typeof(Portakal::ShaderResource));
	PCLASS();
	class EDITOR_API ShaderObjectPainter : public IObjectPainter
	{
		GENERATE_OBJECT;
	public:
		ShaderObjectPainter() = default;
		~ShaderObjectPainter() = default;

	private:
		// Inherited via IObjectPainter
		void OnInitialize() override;
		void OnPaint() override;
	private:
		SharedHeap<ShaderResource> mShader;
		ShaderLanguage mLanguage;
		ShaderStage mStage;
		String mEntryPoint;
		String mSource;
	};
}


