#pragma once

#include "vector2.h"
#include "timer.h"


class Camera {
public:
	Camera() {
		timer_shake.SetOneShot(true);
		timer_shake.SetCallback([&]()
			{
				is_shaking = false;
				Reset();
			});
	}
	~Camera() = default;

	const Vector2& GetPosition() const {
		return position;
	}

	void Reset() {
		position.x = 0;
		position.y = 0;
	}

	void OnUpdate(int delta) {
		timer_shake.OnUpdate(delta);

		if (is_shaking) {
			position.x = (-50 + rand() % 100) / 50.0f * shaking_strength;
			position.y = (-50 + rand() % 100) / 50.0f * shaking_strength;
		}
	}

	void Shake(float strength, int duration) {
		is_shaking = true;
		shaking_strength = strength;

		timer_shake.SetWaitTime(duration);
		timer_shake.Restart();
	}

private:
	Vector2 position;			// 摄像机位置
	Timer timer_shake;			// 摄像机抖动定时器
	bool is_shaking = false;	// 摄像机是否在抖动
	float shaking_strength = 0;	// 摄像机抖动幅度
};