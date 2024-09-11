#pragma once
#include <graphics.h>

#include "camera.h"

class Scene {
public:
	Scene() = default;
	~Scene() = default;

	virtual void OnEnter() {}
	virtual void OnUpdate(int delta) {}
	virtual void OnDraw(const Camera& camera) {}
	virtual void OnInput(const ExMessage& msg) {}
	virtual void OnExit() {}

private:

};