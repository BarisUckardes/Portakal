#pragma once
#include <Editor/GUI/ContextMenu/IContextMenuItem.h>
#include <Runtime/Resource/Shader/ShaderDescriptor.h>

#include "CreateShaderContextMenuItem.reflected.h"

namespace Portakal
{
	PATTRIBUTE(CustomContextMenuItem, "Create Shader");
	PCLASS();
	class EDITOR_API CreateShaderContextMenuItem : public IContextMenuItem
	{
		GENERATE_OBJECT;
	public:
		CreateShaderContextMenuItem() : mOpen(false),mStage(ShaderStage::VertexStage),mLanguage(ShaderLanguage::Unknown)
		{

		}
		~CreateShaderContextMenuItem() = default;
	private:
		// Inherited via IContextMenuItem
		bool OnAction(DomainFolder* pFolder) override;
		bool OnTick(DomainFolder* pFolder) override;
	private:
		bool mOpen;
		String mName;
		String mEntryMethod;
		ShaderStage mStage;
		ShaderLanguage mLanguage;
	};
}

