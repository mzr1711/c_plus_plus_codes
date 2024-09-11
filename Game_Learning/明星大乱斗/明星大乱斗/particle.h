#pragma once

#include "atlas.h"
#include "vector2.h"
#include "util.h"


class Particle {
public:
	Particle() = default;
	Particle(const Vector2& position, Atlas* atlas, int lifespan)
		: position(position), atlas(atlas), lifespan(lifespan) {}
	~Particle() = default;

	void SetAtlas(Atlas* new_atlas) {
		atlas = new_atlas;
	}

	void SetPosition(const Vector2 new_position) {
		position = new_position;
	}

	void SetLifespan(int ms) {
		lifespan = ms;
	}

	const bool CheckValid() const {
		return valid;
	}

	void OnUpdate(int delta) {
		timer += delta;
		if (timer >= lifespan) {
			timer = 0;
			idx_frame++;
			if (idx_frame >= atlas->GetSize() - 1) {
				idx_frame = atlas->GetSize() - 1;
				valid = false;
			}
		}
	}

	void OnDraw(const Camera& camera) const {
		putimage_alpha((int)position.x, (int)position.y, atlas->GetImage(idx_frame));
	}

private:
	int timer = 0;			// 粒子动画播放定时器
	int lifespan = 0;		// 单帧粒子动画持续时长
	int idx_frame = 0;		// 当前正在播放的动画帧
	Vector2 position;		// 粒子的世界坐标位置
	bool valid = true;		// 粒子对象是否有效
	Atlas* atlas = nullptr;	// 粒子动画所使用的图集
};
