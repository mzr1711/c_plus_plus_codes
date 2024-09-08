#pragma once

#include <functional>

#include "util.h"
#include "atlas.h"
#include "camera.h"


class Animation {
public:
	Animation() = default;
	~Animation() = default;

	void Reset() {
		idx_frame = 0;
		timer = 0;
	}

	void SetAtlas(Atlas* new_atlas) {
		Reset();
		atlas = new_atlas;
	}

	void SetLoop(bool loop) {
		is_loop = loop;
	}

	void SetInterval(int ms) {
		interval = ms;
	}

	void SetCallback(std::function<void()> callback) {
		this->callback = callback;
	}

	int GetIndexFrame() {
		return idx_frame;
	}

	IMAGE* GetIndexImage() {
		return atlas->GetImage(idx_frame);
	}

	bool CheckFinished() {
		if (is_loop)
			return false;
		return (idx_frame == atlas->GetSize() - 1);
	}

	void OnUpdate(int delta) {
		timer += delta;
		if (timer >= interval) {
			timer = 0;
			idx_frame++;
			if (idx_frame >= atlas->GetSize() - 1) {
				idx_frame = is_loop ? 0 : atlas->GetSize() - 1;
				if (!is_loop && callback)
					callback();
			}
		}
	}

	void OnDraw(const Camera& camera, int x, int y) const {
		putimage_alpha(camera, x, y, atlas->GetImage(idx_frame));
	}

private:
	int timer = 0;		// 计时器
	int interval = 0;	// 帧间隔
	int idx_frame = 0;  // 帧索引
	bool is_loop = true;
	Atlas* atlas = nullptr;
	std::function<void()> callback;
};