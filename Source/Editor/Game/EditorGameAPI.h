#pragma once
#include <Runtime/Object/API.h>
#include <Editor/Game/GameState.h>
#include <Runtime/Resource/Scene/SceneResource.h>

namespace Portakal
{
	class EDITOR_API EditorGameAPI : public API<EditorGameAPI>
	{
	public:
		static GameState GetGameState();
		static void StartGame();
		static void PauseGame();
		static void StopGame();
	public:
		EditorGameAPI() = default;
		~EditorGameAPI() = default;

	private:
		GameState mCurrentState;

	};
}
