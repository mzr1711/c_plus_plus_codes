#pragma once

#include <iostream>
#include "scene.h"
#include "scene_manager.h"
#include "animation.h"
#include "camera.h"
#include "timer.h"

extern IMAGE img_menu_background;

extern SceneManager scene_manager;


class MenuScene : public Scene {
public:
	MenuScene() = default;
	~MenuScene() = default;

	void OnEnter() {
		mciSendString(_T("play bgm_menu repeat from 0"), NULL, 0, NULL);
	}

	void OnUpdate(int delta) {

	}

	void OnDraw(const Camera& camera) {
		putimage(0, 0, &img_menu_background);
	}

	void OnInput(const ExMessage& msg) {
		if (msg.message == WM_KEYUP) {
			mciSendString(_T("play ui_confirm from 0"), NULL, 0, NULL);
			scene_manager.SwitchTo(SceneManager::SceneType::SELECTOR);
		}
	}

	void OnExit() {
		
	}

private:
	Timer timer;
	Camera camera;
};