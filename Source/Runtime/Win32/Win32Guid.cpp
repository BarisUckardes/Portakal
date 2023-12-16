#include "Win32Guid.h"
#include <Windows.h>

namespace Portakal
{
	void Win32Guid::Create(Guid& id)
	{
		CoCreateGuid((GUID*)&id.A);
	}
}
