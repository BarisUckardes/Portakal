#pragma once
#include <Editor/GUI/Component/IComponentPainter.h>
#include <Runtime/Rendering/Builtin/BasicCamera.h>
#include "BasicCameraPainter.reflected.h"

namespace Portakal
{
	PATTRIBUTE(CustomComponentPainter,typeof(Portakal::BasicCamera))
	PCLASS();
	class EDITOR_API BasicCameraPainter : public IComponentPainter
	{
		GENERATE_OBJECT;
	public:
		BasicCameraPainter() = default;
		~BasicCameraPainter() = default;

	private:
		// Inherited via IComponentPainter
		void OnInitialize() override;
		void OnPaint() override;
	private:
		SharedHeap<BasicCamera> mCamera;
	};
}