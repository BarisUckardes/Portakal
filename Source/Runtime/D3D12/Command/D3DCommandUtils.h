#pragma once

#include <Runtime/D3D12/D3DIncludes.h>

#include <Runtime/Graphics/Command/CommandPoolType.h>

namespace Portakal
{
	class RUNTIME_API D3DCommandUtils
	{
	public:
		static D3D12_COMMAND_LIST_TYPE GetCommandType(CommandPoolType type)
		{
			switch (type)
			{
			case CommandPoolType::Graphics:
				return D3D12_COMMAND_LIST_TYPE_DIRECT;
			case CommandPoolType::Compute:
				return D3D12_COMMAND_LIST_TYPE_COMPUTE;
			case CommandPoolType::Transfer:
				return D3D12_COMMAND_LIST_TYPE_COPY;
			default:
				return D3D12_COMMAND_LIST_TYPE_DIRECT;
			}
		}
	private:
		D3DCommandUtils() = delete;
		~D3DCommandUtils() = delete;
	};
}
