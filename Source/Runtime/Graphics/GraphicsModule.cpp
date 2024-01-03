#include "GraphicsModule.h"
#include <Runtime/Graphics/GraphicsAPI.h>
namespace Portakal
{
	void GraphicsModule::OnInitialize()
	{
		mAPI = new GraphicsAPI();
	}
	void GraphicsModule::OnFinalize()
	{

	}
	void GraphicsModule::OnTick()
	{

	}
}
