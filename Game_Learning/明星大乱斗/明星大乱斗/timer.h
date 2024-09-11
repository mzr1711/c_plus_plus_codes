#pragma once

#include <functional>

class Timer {
public:
	Timer() = default;
	~Timer() = default;

	void Restart() {
		pass_time = 0;
		shotted = false;
	}

	void SetWaitTime(int val) {
		wait_time = val;
	}

	void SetOneShot(bool flag) {
		one_shot = flag;
	}

	void Pause() {
		paused = true;
	}

	void Resume() {
		paused = false;
	}

	void SetCallback(std::function<void()> callback) {
		this->callback = callback;
	}

	void OnUpdate(int delta) {
		if (paused)
			return;
		pass_time += delta;
		if (pass_time >= wait_time) {
			if (!one_shot || (one_shot && !shotted) && callback)
				callback();
			shotted = false;
			pass_time = 0;
		}
	}

protected:
	int pass_time = 0;				// 已过时间
	int wait_time = 0;				// 等待时间
	bool paused = false;			// 是否暂停
	bool shotted = false;			// 是否触发
	bool one_shot = false;			// 单次触发
	std::function<void()> callback;
};