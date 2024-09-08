#pragma once


#include "bullet.h"
#include "animation.h"
#include "util.h"


extern IMAGE img_pea;									// Õ„∂πÕº∆¨
extern Atlas atlas_pea_break;							// Õ„∂π∆∆ÀÈ∂Øª≠ÕººØ


class PeaBullet : public Bullet {
public:
	PeaBullet() {
		size.x = 64;
		size.y = 64;

		damage = 10;

		anim_break.SetAtlas(&atlas_pea_break);
		anim_break.SetInterval(100);
		anim_break.SetLoop(false);
		anim_break.SetCallback([&]() {can_remove = true; });
	}

	~PeaBullet() = default;

	void OnCollide() {
		Bullet::OnCollide();

		switch (rand() % 3) {
		case 0:
			mciSendString(_T("play pea_break_1 from 200"), NULL, 0, NULL);
			break;
		case 1:
			mciSendString(_T("play pea_break_2 from 200"), NULL, 0, NULL);
			break;
		case 2:
			mciSendString(_T("play pea_break_3 from 200"), NULL, 0, NULL);
			break;
		}
	}

	void OnUpdate(int delta) {
		position += velocity * (float)delta;

		if (!valid)
			anim_break.OnUpdate(delta);

		if (CheckIfExceedsScreen())
			can_remove = true;
	}

	void OnDraw(const Camera& camera) const {
		if (valid)
			putimage_alpha(camera, (int)position.x, (int)position.y, &img_pea);
		else
			anim_break.OnDraw(camera, (int)position.x, (int)position.y);

		Bullet::OnDraw(camera);
	}

private:
	Animation anim_break;		// Õ„∂π◊”µØ∆∆¡—∂Øª≠
};