#pragma once

namespace Portakal
{
	struct DescriptorSetCopyEntry
	{
		UInt32 SourceBinding;
		UInt32 SourceArrayElement;

		UInt32 DestinationBinding;
		UInt32 DestinationArrayElement;

		UInt32 DescriptorCount;
	};
}
