#include "GUIWindowModule.h"

#include <Editor/GUI/Window/GUIWindowAPI.h>
#include <Editor/GUI/Window/GUIWindowSettingsFileDescriptor.h>
#include <Editor/GUI/GUIRenderingContextCreateModule.h>
#include <Editor/GUI/GUIRenderingContext.h>

#include <Runtime/Platform/PlatformDirectory.h>
#include <Runtime/Platform/PlatformFile.h>
#include <Runtime/Yaml/Yaml.h>
#include <Runtime/Application/Application.h>

#include <imgui.h>

namespace Portakal
{
	void GUIWindowModule::OnInitialize()
	{
	}
	void GUIWindowModule::OnFinalize()
	{
	}
	void GUIWindowModule::OnTick()
	{
	}
	void GUIWindowModule::CreateDefaultWindowSettings()
	{
	}
	void GUIWindowModule::LoadWindowSettings()
	{
	}
	void GUIWindowModule::SaveWindowSettings()
	{
	}
}
