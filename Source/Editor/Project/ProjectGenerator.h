#pragma once
#include <Runtime/Containers/String.h>

namespace Portakal
{
	class RUNTIME_API ProjectGenerator final
	{
	public:
		static void GenerateProject(const String& name, const String& folderPath);
	public:
		ProjectGenerator() = delete;
		~ProjectGenerator() = delete;
	};
}
