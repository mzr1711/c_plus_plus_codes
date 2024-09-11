#pragma once


#include "bullet.h"
#include "animation.h"


extern Atlas atlas_sun;
extern Atlas atlas_sun_explode;

extern Camera main_camera;


class SunBullet : public Bullet {
public:
	SunBullet() {
		size.x = 96;
		size.y = 96;

		damage = 20;

		anim_idle.SetAtlas(&atlas_sun);
		anim_idle.SetInterval(50);

		anim_explode.SetAtlas(&atlas_sun_explode);
		anim_explode.SetInterval(50);
		anim_explode.SetLoop(false);
		anim_explode.SetCallback([&]() {can_remove = true; });

		IMAGE* frame_idle = anim_idle.GetIndexImage();
		IMAGE* frame_explode = anim_explode.GetIndexImage();
		explode_render_offset.x = (frame_idle->getwidth() - frame_explode->getwidth()) / 2.0f;
		explode_render_offset.y = (frame_idle->getheight() - frame_explode->getheight()) / 2.0f;
	}

	~SunBullet() = default;

	void OnCollide() {
		Bullet::OnCollide();

		main_camera.Shake(5, 250);

		mciSendString(_T("play sun_explode from 0"), NULL, 0, NULL);
	}

	void OnUpdate(int delta) {
		if (valid) {
			velocity.y += gravity * delta;
			position += velocity * (float)delta;
		}

		if (!valid)
			anim_explode.OnUpdate(delta);
		else
			anim_idle.OnUpdate(delta);

		if (CheckIfExceedsScreen())
			can_remove = true;
	}

	void OnDraw(const Camera& camera) const {
		if (valid)
			anim_idle.OnDraw(camera, (int)position.x, (int)position.y);
		else {
			anim_explode.OnDraw(camera,
				(int)(explode_render_offset.x + position.x),
				(int)(explode_render_offset.y + position.y));
		}

		Bullet::OnDraw(camera);
	}

private:
	const float gravity = 1e-3f;	// 日光炸弹重力

private:
	Animation anim_idle;			// 日光炸弹默认动画
	Animation anim_explode;			// 日光炸弹爆炸动画
	Vector2 explode_render_offset;	// 爆炸动画渲染偏移
};