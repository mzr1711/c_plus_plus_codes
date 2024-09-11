#pragma once

#include "scene.h"
#include "camera.h"

extern Scene* menu_scene;
extern Scene* selector_scene;
extern Scene* game_scene;

class SceneManager {
public:
	enum class SceneType {
		MENU,
		SELECTOR,
		GAME
	};

public:
	SceneManager() = default;
	~SceneManager() = default;

	void SetCurrentScene(Scene* scene) {
		current_scene = scene;
		current_scene->OnEnter();
	}

	void SwitchTo(SceneType type) {
		current_scene->OnExit();
		switch (type) {
		case SceneType::MENU:
			current_scene = menu_scene;
			break;
		case SceneType::SELECTOR:
			current_scene = selector_scene;
			break;
		case SceneType::GAME:
			current_scene = game_scene;
			break;
		default:
			break;
		}
		current_scene->OnEnter();
	}

	void OnUpdate(int delta) {
		current_scene->OnUpdate(delta);
	}

	void OnDraw(const Camera& camera) {
		current_scene->OnDraw(camera);
	}

	void OnInput(const ExMessage& msg) {
		current_scene->OnInput(msg);
	}

private:
	Scene* current_scene = nullptr;
};