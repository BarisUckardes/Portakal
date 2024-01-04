#pragma once
#include <Runtime/Application/ApplicationModule.h>
#include <Editor/ImGui/ImGuiRenderer.h>
#include <Runtime/Object/API.h>

namespace Portakal
{
	class EDITOR_API ImGuiAPI : public API<ImGuiAPI>
	{
		friend class ImGuiModule;
	public:
		static SharedHeap<ImGuiRenderer> GetRenderer();
	private:
		ImGuiAPI();
		~ImGuiAPI();
	private:
		SharedHeap<ImGuiRenderer> mRenderer;
	};
}
