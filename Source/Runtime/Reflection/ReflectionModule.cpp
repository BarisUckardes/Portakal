#include "ReflectionModule.h"

namespace Portakal
{
	void ReflectionModule::OnInitialize()
	{
		mAPI = new ReflectionAPI();
	}
	void ReflectionModule::OnTick()
	{

	}
	void ReflectionModule::OnFinalize()
	{
		delete mAPI;
		mAPI = nullptr;
	}
	void ReflectionModule::OnPreInvalidation()
	{

	}
	void ReflectionModule::OnPostInvalidation()
	{

	}
}
