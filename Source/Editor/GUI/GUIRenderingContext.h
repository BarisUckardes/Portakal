#pragma once

#include <Runtime/Object/Object.h>
#include <Runtime/Memory/SharedHeap.h>
#include <Runtime/Math/Color4.h>

#include <Editor/GUI/GUIWindowFlags.h>
#include <Editor/GUI/GUIViewport.h>
#include <Editor/GUI/GUITheme.h>
#include <Editor/GUI/GUIDockNodeFlags.h>
#include <Editor/GUI/GUIDirection.h>
#include <Editor/GUI/GUIColorVariables.h>
#include <Editor/GUI/GUIStyleVariables.h>

namespace Portakal
{
	typedef uint32 GUIID;

	class ImGuiRenderer;
	class EDITOR_API GUIRenderingContext : public Object
	{
		friend class GUIRenderingContextCreateModule;

	public:
		bool BeginWindow(const String windowTitle, const GUIWindowFlags flags, bool bOpen);
		void FinalizeWindow();
		void SetNextWindowSize(const Vector2UI size);
		void SetNextWindowPos(const Vector2UI position);
		void SetNextWindowViewport(const GUIViewport* pViewport);

		void BeginStyleVariable(const GUIStyleVariables variable, const Vector2F value);
		void BeginStyleVariable(const GUIStyleVariables variable, const float value);
		void BeginStyleColor(const GUIColorVariables variable, const Color4F color);
		void FinalizeStyleVariable();
		void FinalizeColorVariable();

		GUIID GetObjectID(const String& name);

		GUIID CreateDockspace(const GUIID id, const Vector2UI size, const GUIDockNodeFlags flags = GUIDockNodeFlags::None);
		void DockBuilderRemoveNode(const GUIID id);
		void DockBuilderAddNode(const GUIID id, const GUIDockNodeFlags flags = GUIDockNodeFlags::None);
		void DockBuilderSetNodeSize(const GUIID id, const Vector2UI size);
		GUIID DockBuilderSplitNode(const GUIID id, const GUIDirection direction, const float sizeRatio, GUIID& outIdOppositeDir);
		void DockBuilderDockWindow(const String& windowName, const GUIID nodeID);
		void DockBuilderFinish(const GUIID nodeID);

		const GUIViewport* const GetMainViewport() const;

		void SetTheme(const GUITheme& theme);
		virtual void OnShutdown() override;

	private:
		GUIRenderingContext(const SharedHeap<ImGuiRenderer>& renderer);
		~GUIRenderingContext() override = default;

	private:
		SharedHeap<ImGuiRenderer> mImGuiRenderer;
	};
}
