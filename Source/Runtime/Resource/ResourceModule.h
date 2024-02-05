#pragma once
#include <Runtime/Application/ApplicationModule.h>
#include <Runtime/Resource/Resource.h>
#include "ResourceModule.reflected.h"

namespace Portakal
{
	class ResourceAPI;

	PCLASS();

	/// <summary>
	/// A module that is responsible for the lifetime of the ResourceAPI
	/// </summary>
	class RUNTIME_API ResourceModule : public ApplicationModule
	{
		GENERATE_OBJECT;
	public:
		ResourceModule() = default;
		~ResourceModule() = default;

	private:
		// Inherited via ApplicationModule
		virtual void OnInitialize() override;
		virtual void OnFinalize() override;
		virtual void OnTick() override;
	private:
		ResourceAPI* mAPI;

	};
}

