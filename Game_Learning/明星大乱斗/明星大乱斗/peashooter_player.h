#pragma once

#include <iostream>

#include "player.h"
#include "pea_bullet.h"


extern Atlas atlas_peashooter_idle_left;				// 婉逗射手朝向左的默认动画图集
extern Atlas atlas_peashooter_idle_right;				// 婉逗射手朝向右的默认动画图集
extern Atlas atlas_peashooter_run_left;					// 婉逗射手朝向右的奔跑动画图集
extern Atlas atlas_peashooter_run_right;				// 婉逗射手朝向右的奔跑动画图集
extern Atlas atlas_peashooter_attack_ex_left;			// 婉逗射手朝向右的特殊攻击动画图集
extern Atlas atlas_peashooter_attack_ex_right;			// 婉逗射手朝向右的特殊攻击动画图集
extern Atlas atlas_peashooter_die_left;					// 婉逗射手朝向右的死亡动画图集
extern Atlas atlas_peashooter_die_right;				// 婉逗射手朝向右的死亡动画图集

extern Camera main_camera;

extern std::vector<Bullet*> bullet_list;


class PeashooterPlayer : public Player {
public:
	PeashooterPlayer(bool facing_left = false) : Player(facing_left) {
		anim_idle_left.SetAtlas(&atlas_peashooter_idle_left);
		anim_idle_right.SetAtlas(&atlas_peashooter_idle_right);
		anim_run_left.SetAtlas(&atlas_peashooter_run_left);
		anim_run_right.SetAtlas(&atlas_peashooter_run_right);
		anim_attack_ex_left.SetAtlas(&atlas_peashooter_attack_ex_left);
		anim_attack_ex_right.SetAtlas(&atlas_peashooter_attack_ex_right);
		anim_die_left.SetAtlas(&atlas_peashooter_die_left);
		anim_die_right.SetAtlas(&atlas_peashooter_die_right);

		anim_idle_left.SetInterval(75);
		anim_idle_right.SetInterval(75);
		anim_run_left.SetInterval(75);
		anim_run_right.SetInterval(75);
		anim_attack_ex_left.SetInterval(75);
		anim_attack_ex_right.SetInterval(75);
		anim_die_left.SetInterval(150);
		anim_die_right.SetInterval(150);

		anim_die_left.SetLoop(false);
		anim_die_right.SetLoop(false);

		size.x = 96;
		size.y = 96;

		timer_attack_ex.SetWaitTime(attack_ex_duration);
		timer_attack_ex.SetOneShot(true);
		timer_attack_ex.SetCallback([&]()
			{
				is_attacking_ex = false;
			});

		timer_spawn_pea_ex.SetWaitTime(100);
		timer_spawn_pea_ex.SetCallback([&]()
			{
				SpawnPeaBullet(speed_pea_ex);
			});

		attack_cd = 100;

		hp = 100;
		mp = 0;
	}

	~PeashooterPlayer() = default;

	void OnUpdate(int delta) {
		Player::OnUpdate(delta);

		if (is_attacking_ex) {
			main_camera.Shake(5, 100);
			timer_attack_ex.OnUpdate(delta);
			timer_spawn_pea_ex.OnUpdate(delta);

			is_facing_left
				? anim_attack_ex_left.OnUpdate(delta)
				: anim_attack_ex_right.OnUpdate(delta);
		}
	}

	void OnDraw(const Camera& camera) {
		Player::OnDraw(camera);
	}

	void OnAttack() {
		SpawnPeaBullet(speed_pea);

		switch (rand() % 2) {
		case 0:
			mciSendString(_T("play pea_shoot_1 from 0"), NULL, 0, NULL);
			break;
		case 1:
			mciSendString(_T("play pea_shoot_2 from 0"), NULL, 0, NULL);
			break;
		}
	}

	void OnAttackEx() {
		is_attacking_ex = true;
		timer_attack_ex.Restart();

		is_facing_left ? anim_attack_ex_left.Reset() : anim_attack_ex_right.Reset();

		mciSendString(_T("play pea_shoot_ex from 800"), NULL, 0, NULL);
	}

private:
	void SpawnPeaBullet(float speed) {
		Bullet* bullet = new PeaBullet();

		Vector2 bullet_position, bullet_velocity;
		const Vector2& bullet_size = bullet->GetSize();
		bullet_position.x = is_facing_left
			? position.x - bullet_size.x / 2
			: position.x + size.x - bullet_size.x / 2;
		bullet_position.y = position.y;
		bullet_velocity.x = is_facing_left ? -speed : speed;
		bullet_velocity.y = 0;

		bullet->SetPosition(bullet_position.x, bullet_position.y);
		bullet->SetVelocity(bullet_velocity.x, bullet_velocity.y);

		bullet->SetCollideTarget(id == PlayerID::P1 ? PlayerID::P2 : PlayerID::P1);

		bullet->SetCallBack([&]() { mp += 25; });

		bullet_list.push_back(bullet);
	}

private:
	const float	speed_pea = 0.75f;			// 普通攻击子弹速度
	const float	speed_pea_ex = 1.5f;		// 特殊攻击子弹速度
	const int attack_ex_duration = 2500;	// 特殊攻击状态持续时长 

private:
	Timer timer_attack_ex;		// 特殊攻击状态定时器
	Timer timer_spawn_pea_ex;	// 豌豆子弹发射定时器
};