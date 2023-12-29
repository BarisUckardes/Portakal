#pragma once
#include <Runtime/Containers/String.h>

namespace Portakal
{
	class EDITOR_API ProjectPaths final
	{
		friend class ProjectModule;
	private:
		static inline String sProjectFolder;
		static inline String sDomainFolder;
		static inline String sSettingsFolder;
	public:
		FORCEINLINE static String GetProjectFolder() noexcept
		{
			return sProjectFolder;
		}
		FORCEINLINE static String GetDomainFolder() noexcept
		{
			return sDomainFolder;
		}
		FORCEINLINE static String GetSettingsFolder() noexcept
		{
			return sSettingsFolder;
		}
	public:
		ProjectPaths() = delete;
		~ProjectPaths() = delete;
	};
}
