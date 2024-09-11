#pragma once


#include <iostream>

#include "player.h"
#include "sun_bullet.h"
#include "sun_bullet_ex.h"

extern Atlas atlas_sunflower_idle_left;				// 龙日葵朝向左的默认动画图集
extern Atlas atlas_sunflower_idle_right;			// 龙日葵朝向右的默认动画图集
extern Atlas atlas_sunflower_run_left;				// 龙日葵朝向右的奔跑动画图集
extern Atlas atlas_sunflower_run_right;				// 龙日葵朝向右的奔跑动画图集
extern Atlas atlas_sunflower_attack_ex_left;		// 龙日葵朝向右的特殊攻击动画图集
extern Atlas atlas_sunflower_attack_ex_right;		// 龙日葵朝向右的特殊攻击动画图集
extern Atlas atlas_sun_text;						// “日” 文本动画图集
extern Atlas atlas_sunflower_die_left;				// 龙日葵朝向右的死亡动画图集
extern Atlas atlas_sunflower_die_right;				// 龙日葵朝向右的死亡动画图集

extern Player* player_1;
extern Player* player_2;


class SunflowerPlayer : public Player {
public:
	SunflowerPlayer(bool facing_left = false) : Player(facing_left) {
		anim_idle_left.SetAtlas(&atlas_sunflower_idle_left);
		anim_idle_right.SetAtlas(&atlas_sunflower_idle_right);
		anim_run_left.SetAtlas(&atlas_sunflower_run_left);
		anim_run_right.SetAtlas(&atlas_sunflower_run_right);
		anim_attack_ex_left.SetAtlas(&atlas_sunflower_attack_ex_left);
		anim_attack_ex_right.SetAtlas(&atlas_sunflower_attack_ex_right);
		anim_sun_text.SetAtlas(&atlas_sun_text);
		anim_die_left.SetAtlas(&atlas_sunflower_die_left);
		anim_die_right.SetAtlas(&atlas_sunflower_die_right);

		anim_idle_left.SetInterval(75);
		anim_idle_right.SetInterval(75);
		anim_run_left.SetInterval(75);
		anim_run_right.SetInterval(75);
		anim_attack_ex_left.SetInterval(100);
		anim_attack_ex_right.SetInterval(100);
		anim_sun_text.SetInterval(100);
		anim_die_left.SetInterval(150);
		anim_die_right.SetInterval(150);

		anim_attack_ex_left.SetLoop(false);
		anim_attack_ex_right.SetLoop(false);
		anim_sun_text.SetLoop(false);
		anim_die_left.SetLoop(false);
		anim_die_right.SetLoop(false);

		anim_attack_ex_left.SetCallback([&]()
			{
				is_sun_text_visible = false;
				is_attacking_ex = false;
			});

		anim_attack_ex_right.SetCallback([&]()
			{
				is_sun_text_visible = false;
				is_attacking_ex = false;
			});

		size.x = 96;
		size.y = 96;

		attack_cd = 250;

		hp = 100;
		mp = 0;
	}

	~SunflowerPlayer() = default;

	void OnUpdate(int delta) {
		Player::OnUpdate(delta);

		if (is_sun_text_visible)
			anim_sun_text.OnUpdate(delta);
		if (is_attacking_ex)
			is_facing_left ? anim_attack_ex_left.OnUpdate(delta) : anim_attack_ex_right.OnUpdate(delta);
	}

	void OnDraw(const Camera& camera) {
		if (is_sun_text_visible) {
			Vector2 text_position;
			IMAGE* frame = anim_sun_text.GetIndexImage();
			text_position.x = position.x - (size.x - frame->getwidth()) / 2;
			text_position.y = position.y - frame->getheight();
			anim_sun_text.OnDraw(camera, (int)text_position.x, (int)text_position.y);
		}

		Player::OnDraw(camera);
	}

	void OnAttack() {
		Bullet* bullet = new SunBullet();

		Vector2 bullet_position;	
		const Vector2& bullet_size = bullet->GetSize();

		bullet_position.x = position.x + (size.x - bullet_size.x) / 2;
		bullet_position.y = position.y;

		bullet->SetPosition(bullet_position.x, bullet_position.y);
		bullet->SetVelocity(is_facing_left ? -velocity_sun.x : velocity_sun.x, velocity_sun.y);

		bullet->SetCollideTarget(id == PlayerID::P1 ? PlayerID::P2 : PlayerID::P1);

		bullet->SetCallBack([&]() { mp += 35; });

		bullet_list.push_back(bullet);
	}

	void OnAttackEx() {
		is_attacking_ex = true;
		is_sun_text_visible = true;

		anim_sun_text.Reset();
		is_facing_left ? anim_attack_ex_left.Reset() : anim_attack_ex_right.Reset();

		Bullet* bullet = new SunBulletEx();
		Player* target_player = (id == PlayerID::P1 ? player_2 : player_1);

		Vector2 bullet_position, bullet_velocity;
		const Vector2& bullet_size = bullet->GetSize();
		const Vector2& target_size = target_player->GetSize();
		const Vector2& target_position = target_player->GetPosition();
		bullet_position.x = target_position.x + (target_size.x - bullet_size.x) / 2;
		bullet_position.y = -size.y;
		bullet_velocity.x = 0;
		bullet_velocity.y = speed_sun_ex;

		bullet->SetPosition(bullet_position.x, bullet_position.y);
		bullet->SetVelocity(bullet_velocity.x, bullet_velocity.y);

		bullet->SetCollideTarget(id == PlayerID::P1 ? PlayerID::P2 : PlayerID::P1);

		bullet->SetCallBack([&]() { mp += 50; });

		bullet_list.push_back(bullet);

		mciSendString(_T("play sun_text from 200"), NULL, 0, NULL);
	}

private:
	const float speed_sun_ex = 0.15f;				// 大型日光炸弹下落速度
	const Vector2 velocity_sun = { 0.25f, -0.5f };	// 小型日光炸弹抛射速度

private:
	Animation anim_sun_text;						// 头顶文字动画
	bool is_sun_text_visible = false;				// 是否显示头顶文字
};