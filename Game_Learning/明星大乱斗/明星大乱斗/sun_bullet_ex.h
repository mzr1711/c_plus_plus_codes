#pragma once


#include "bullet.h"
#include "animation.h"
#include "camera.h"


extern Atlas atlas_sun_ex;								// 特殊日光动画图集
extern Atlas atlas_sun_ex_explode;						// 特殊日光爆炸动画图集

extern Camera main_camera;


class SunBulletEx : public Bullet {
public:
	SunBulletEx() {
		size.x = 288;
		size.y = 288;

		damage = 30;

		anim_idle.SetAtlas(&atlas_sun_ex);
		anim_idle.SetInterval(50);

		anim_explode.SetAtlas(&atlas_sun_ex_explode);
		anim_explode.SetInterval(50);
		anim_explode.SetLoop(false);
		anim_explode.SetCallback([&]() { can_remove = true; });

		IMAGE* frame_idle = anim_idle.GetIndexImage();
		IMAGE* frame_explode = anim_explode.GetIndexImage();
		explode_render_offset.x = (frame_idle->getwidth() - frame_explode->getwidth()) / 2.0f;
		explode_render_offset.y = (frame_idle->getheight() - frame_explode->getheight()) / 2.0f;
	}

	~SunBulletEx() = default;

	bool CheckCollision(const Vector2& position, const Vector2& size) {
		bool is_collide_x = (max(this->position.x + this->size.x, position.x + size.x) - min(this->position.x, position.x))
			<= this->size.x + size.x;
		bool is_collide_y = (max(this->position.y + this->size.y, position.y + size.y) - min(this->position.y, position.y)) 
			<= this->size.y + size.y;
		return is_collide_x && is_collide_y;
	}

	void OnCollide() {
		Bullet::OnCollide();

		main_camera.Shake(20, 350);

		mciSendString(_T("play sun_explode_ex from 0"), NULL, 0, NULL);
	}

	void OnUpdate(int delta) {
		if (valid)
			position += velocity * (float)delta;

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
				(int)(position.x + explode_render_offset.x),
				(int)(position.y + explode_render_offset.y));
		}

		Bullet::OnDraw(camera);
	}

private:
	Animation anim_idle;			// 巨大日光炸弹默认动画
	Animation anim_explode;			// 巨大日光炸弹爆炸动画
	Vector2 explode_render_offset;	// 爆炸动画渲染偏移
};