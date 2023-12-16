#pragma once
#include <Runtime/Containers/String.h>
#include <Runtime/Math/Vector2.h>
#include <Runtime/Memory/SharedHeap.h>
#include <Runtime/Window/WindowMode.h>
#include <Runtime/Platform/PlatformMonitor.h>

namespace Portakal
{
	struct RUNTIME_API WindowDesc
	{
		String Title;
		Vector2US Size;
		Vector2I Position;
		WindowMode Mode;
		SharedHeap<PlatformMonitor> pMonitor;
	};
}
