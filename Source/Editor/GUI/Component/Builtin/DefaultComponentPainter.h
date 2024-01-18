#pragma once
#include <Editor/GUI/Component/IComponentPainter.h>

namespace Portakal
{
	class EDITOR_API DefaultComponentPainter : public IComponentPainter
	{
	public:
		DefaultComponentPainter() = default;
		~DefaultComponentPainter() = default;

	private:
		// Inherited via IComponentPainter
		void OnInitialize() override;
		void OnPaint() override;
	private:

	};
}
