#include "EditorObjectModule.h"

namespace Portakal
{
	void EditorObjectModule::OnInitialize()
	{
		mAPI = new EditorObjectAPI();
	}
	void EditorObjectModule::OnFinalize()
	{
		delete mAPI;
		mAPI = nullptr;
	}
	void EditorObjectModule::OnTick()
	{
	}
	void EditorObjectModule::OnPreInvalidation()
	{

	}
	void EditorObjectModule::OnPostInvalidation()
	{

	}
}
