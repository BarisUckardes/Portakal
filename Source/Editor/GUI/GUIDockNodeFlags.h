#pragma once

#include <Runtime/Core/Core.h>

namespace Portakal
{
	enum class EDITOR_API GUIDockNodeFlags : uint64
	{
		None = 0,
		DockSpace = 1 << 10,
		CentralNode = 1 << 11,
		NoTabBar = 1 << 12,
		HiddenTabBar = 1 << 13,
		NoWindowMenuButton = 1 << 14,
		NoCloseButton = 1 << 15,
		NoDocking = 1 << 16,
		NoDockingSplitMe = 1 << 17,
		NoDockingSplitOther = 1 << 18,
		NoDockingOverMe = 1 << 19,
		NoDockingOverOther = 1 << 20,
		NoDockingOverEmpty = 1 << 21,
		NoResizeX = 1 << 22,
		NoResizeY = 1 << 23
	};

	GENERATE_FLAGS(GUIDockNodeFlags, uint64);
}
