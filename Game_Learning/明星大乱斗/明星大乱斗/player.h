#pragma once


#include <graphics.h>

#include "animation.h"
#include "vector2.h"
#include "camera.h"
#include "player_id.h"
#include "platform.h"
#include "bullet.h"
#include "particle.h"


extern std::vector<Platform> platform_list;
extern std::vector<Bullet*> bullet_list;

extern bool is_debug;

extern IMAGE img_1P_cursor;								// 1P 指示光标图片
extern IMAGE img_2P_cursor;								// 2P 指示光标图片

extern Atlas atlas_run_effect;							// 奔跑特效动画图集
extern Atlas atlas_jump_effect;							// 跳跃特效动画图集
extern Atlas atlas_land_effect;							// 落地特效动画图集

class Player {
public:
	Player(bool facing_left = false) : is_facing_left(facing_left) {
		current_animation = is_facing_left ? &anim_idle_left : &anim_idle_right;

		timer_attack_cd.SetWaitTime(attack_cd);
		timer_attack_cd.SetOneShot(true);
		timer_attack_cd.SetCallback([&]()
			{
				can_attack = true;
			});

		timer_invulnerable.SetWaitTime(750);
		timer_invulnerable.SetOneShot(true);
		timer_invulnerable.SetCallback([&]()
			{
				is_invulnerable = false;
			});

		timer_invulnerable_blink.SetWaitTime(75);
		timer_invulnerable_blink.SetCallback([&]()
			{
				is_showing_sketch_frame = !is_showing_sketch_frame;
			});

		timer_run_effect_generation.SetWaitTime(75);
		timer_run_effect_generation.SetCallback([&]()
			{
				Vector2 particle_position;
				IMAGE* frame = atlas_run_effect.GetImage(0);
				particle_position.x = position.x + (size.x - frame->getwidth()) / 2;
				particle_position.y = position.y + size.y - frame->getheight();
				particle_list.emplace_back(particle_position, &atlas_run_effect, 45);
			});

		timer_die_effect_generation.SetWaitTime(35);
		timer_die_effect_generation.SetCallback([&]()
			{
				Vector2 particle_position;
				IMAGE* frame = atlas_run_effect.GetImage(0);
				particle_position.x = position.x + (size.x - frame->getwidth()) / 2;
				particle_position.y = position.y + size.y - frame->getheight();
				particle_list.emplace_back(particle_position, &atlas_run_effect, 150);
			});

		anim_jump_effect.SetAtlas(&atlas_jump_effect);
		anim_jump_effect.SetInterval(25);
		anim_jump_effect.SetLoop(false);
		anim_jump_effect.SetCallback([&]()
			{
				is_jump_effect_visiable = false;
			});

		anim_land_effect.SetAtlas(&atlas_land_effect);
		anim_land_effect.SetInterval(50);
		anim_land_effect.SetLoop(false);
		anim_land_effect.SetCallback([&]()
			{
				is_land_effect_visiable = false;
			});

		timer_cursor_visibility.SetWaitTime(2500);
		timer_cursor_visibility.SetOneShot(true);
		timer_cursor_visibility.SetCallback([&]()
			{
				is_cursor_visible = false;
			});
	}

	~Player() = default;

	virtual void OnUpdate(int delta) {
		int direction = is_right_key_down - is_left_key_down;

		if (direction != 0) {
			if (!is_attacking_ex)
				is_facing_left = direction < 0;
			current_animation = is_facing_left ? &anim_run_left : &anim_run_right;
			float distance = run_velocity * direction * delta;
			OnRun(distance);
		}
		else {
			current_animation = is_facing_left ? &anim_idle_left : &anim_idle_right;
			timer_run_effect_generation.Pause();
		}

		if (is_attacking_ex)
			current_animation = is_facing_left ? &anim_attack_ex_left : &anim_attack_ex_right;
		if (hp < 0)
			current_animation = last_hurt_direction.x < 0 ? &anim_die_left : &anim_die_right;

		current_animation->OnUpdate(delta);
		anim_jump_effect.OnUpdate(delta);
		anim_land_effect.OnUpdate(delta);

		timer_attack_cd.OnUpdate(delta);
		timer_invulnerable.OnUpdate(delta);
		timer_invulnerable_blink.OnUpdate(delta);
		timer_run_effect_generation.OnUpdate(delta);
		timer_cursor_visibility.OnUpdate(delta);

		if (hp <= 0)
			timer_die_effect_generation.OnUpdate(delta);

		particle_list.erase(std::remove_if(
			particle_list.begin(), particle_list.end(),
			[](const Particle& particle)
			{
				return !particle.CheckValid();
			}),
			particle_list.end());
		for (Particle& particle : particle_list)
			particle.OnUpdate(delta);

		if (is_showing_sketch_frame)
			SketchImage(current_animation->GetIndexImage(), &img_sketch);

		MoveAndCollide(delta);
	}

	virtual void OnDraw(const Camera& camera) {
		if (is_jump_effect_visiable)
			anim_jump_effect.OnDraw(camera, (int)position_jump_effect.x, (int)position_jump_effect.y);
		if (is_land_effect_visiable)
			anim_land_effect.OnDraw(camera, (int)position_land_effect.x, (int)position_land_effect.y);

		for (Particle& particle : particle_list)
			particle.OnDraw(camera);

		if (hp > 0 && is_invulnerable && is_showing_sketch_frame)
			putimage_alpha((int)position.x, (int)position.y, &img_sketch);
		else
			current_animation->OnDraw(camera, (int)position.x, (int)position.y);

		if (is_cursor_visible) {
			switch (id) {
			case PlayerID::P1:
				putimage_alpha(camera, (int)(position.x + (size.x - img_1P_cursor.getwidth()) / 2),
					(int)(position.y - img_1P_cursor.getheight()), &img_1P_cursor);
				break;
			case PlayerID::P2:
				putimage_alpha(camera, (int)(position.x + (size.x - img_2P_cursor.getwidth()) / 2),
					(int)(position.y - img_2P_cursor.getheight()), &img_2P_cursor);
				break;
			}
		}

		if (is_debug) {
			setlinecolor(RGB(0, 125, 255));
			rectangle((int)position.x, (int)position.y, (int)(position.x + size.x), (int)(position.y + size.y));
		}
	}

	virtual void OnInput(const ExMessage& msg) {
		switch (msg.message) {
		case WM_KEYDOWN:
			switch (id) {
			case PlayerID::P1:
				switch (msg.vkcode) {
					// 'A'
				case 0x41:
					is_left_key_down = true;
					break;
					// 'D'
				case 0x44:
					is_right_key_down = true;
					break;
					// 'W'
				case 0x57:
					OnJump();
					break;
					// 'F'
				case 0x46:
					if (can_attack) {
						can_attack = false;
						OnAttack();
						timer_attack_cd.Restart();
					}
					break;
					// 'G'
				case 0x47:
					if (mp >= 100) {
						mp = 0;
						OnAttackEx();
					}
					break;
				}
				break;
			case PlayerID::P2:
				switch (msg.vkcode) {
					// '<-'
				case VK_LEFT:
					is_left_key_down = true;
					break;
					// '->'
				case VK_RIGHT:
					is_right_key_down = true;
					break;
					// '^'
				case VK_UP:
					OnJump();
					break;
					// '.'
				case VK_OEM_PERIOD:
					if (can_attack) {
						can_attack = false;
						OnAttack();
						timer_attack_cd.Restart();
					}
					break;
					// '/'
				case VK_OEM_2:
					if (mp >= 100) {
						mp = 0;
						OnAttackEx();
					}
					break;
				}
				break;
			}
			break;
		case WM_KEYUP:
			switch (id) {
			case PlayerID::P1:
				switch (msg.vkcode) {
					// 'A'
				case 0x41:
					is_left_key_down = false;
					break;
					// 'D'
				case 0x44:
					is_right_key_down = false;
					break;
				}
				break;
			case PlayerID::P2:
				switch (msg.vkcode) {
					// '<-'
				case VK_LEFT:
					is_left_key_down = false;
					break;
					// '->'
				case VK_RIGHT:
					is_right_key_down = false;
					break;
				}
				break;
			}
			break;
		default:
			break;
		}
	}

	virtual void OnRun(float distance) {
		if (is_attacking_ex)
			return;

		position.x += distance;
		timer_run_effect_generation.Resume();
	}

	virtual void OnJump() {
		if (velocity.y != 0 || is_attacking_ex)
			return;

		velocity.y += jump_velocity;

		is_jump_effect_visiable = true;
		anim_jump_effect.Reset();

		IMAGE* effect_frame = anim_jump_effect.GetIndexImage();
		position_jump_effect.x = position.x + (size.x - effect_frame->getwidth()) / 2;
		position_jump_effect.y = position.y + size.y - effect_frame->getheight();
	}

	virtual void OnLand() {
		is_land_effect_visiable = true;
		anim_land_effect.Reset();

		IMAGE* effect_frame = anim_land_effect.GetIndexImage();
		position_land_effect.x = position.x + (size.x - effect_frame->getwidth()) / 2;
		position_land_effect.y = position.y + size.y - effect_frame->getheight();
	}

	void SetID(PlayerID id) {
		this->id = id;
	}

	void SetPosition(float x, float y) {
		position.x = x;
		position.y = y;
	}

	const Vector2& GetPosition() const {
		return position;
	}

	const Vector2& GetSize() const {
		return size;
	}

	virtual void OnAttack() {}
	virtual void OnAttackEx() {}

	virtual bool GetIsAttackingEx() {
		return is_attacking_ex;
	}

	void MakeInvulnerable() {
		is_invulnerable = true;
		timer_invulnerable.Restart();
	}

	void SetHp(int val) {
		hp = val;
	}

	int GetHp() const {
		return hp;
	}

	int GetMp() const {
		return mp;
	}

protected:
	void MoveAndCollide(int delta) {
		float last_velocity_y = velocity.y;

		velocity.y += gravity * delta;
		position += velocity * (float)delta;

		if (hp <= 0)
			return;

		if (velocity.y > 0) {
			for (const Platform& platform : platform_list) {
				const Platform::CollisionShape shape = platform.shape;
				bool is_collide_x = (max(position.x + size.x, shape.right) - min(position.x, shape.left))
					<= size.x + (shape.right - shape.left);  // 判断角色与平台最右与最左差值，是否小于二者宽度之和
				bool is_collide_y = (shape.y >= position.y && shape.y <= position.y + size.y);

				if (is_collide_x && is_collide_y) {
					float delta_pos_y = velocity.y * delta;
					float last_tick_foot_pos_y = position.y + size.y - delta_pos_y;
					if (last_tick_foot_pos_y <= shape.y) {
						position.y = shape.y - size.y;
						velocity.y = 0;

						if (last_velocity_y != 0)
							OnLand();

						break;
					}
				}
			}
		}

		if (!is_invulnerable) {
			for (Bullet* bullet : bullet_list) {
				if (!bullet->GetValid() || bullet->GetCollideTarget() != id)
					continue;

				if (bullet->CheckCollision(position, size)) {
					MakeInvulnerable();
					bullet->OnCollide();
					bullet->SetValid(false);
					hp -= bullet->GetDamage();
					last_hurt_direction = bullet->GetPosition() - position;
					if (hp <= 0) {
						velocity.x = last_hurt_direction.x < 0 ? -0.35f : 0.35f;
						velocity.y = -1.0f;
					}
				}
			}
		}
	}

protected:
	const float gravity = 1.6e-3f;			// 玩家重力
	const float	run_velocity = 0.55f;		// 跑动速度
	const float jump_velocity = -0.85f;		// 跳起速度

protected:
	int mp = 0;								// 角色能量
	int hp = 100;							// 角色生命值

	Vector2 size;							// 角色尺寸
	Vector2 position;						// 角色位置
	Vector2 velocity;						// 角色速度

	Animation anim_idle_left;				// 朝向左的默认动画
	Animation anim_idle_right;				// 朝向右的默认动画
	Animation anim_run_left;				// 朝向左的奔跑动画
	Animation anim_run_right;				// 朝向右的奔跑动画
	Animation anim_attack_ex_left;			// 朝向左的特殊攻击动画
	Animation anim_attack_ex_right;			// 朝向右的特殊攻击动画
	Animation anim_jump_effect;				// 跳跃动画特效
	Animation anim_land_effect;				// 落地动画特效
	Animation anim_die_left;				// 朝向左的死亡动画
	Animation anim_die_right;				// 朝向右的死亡动画

	bool is_jump_effect_visiable = false;	// 跳跃动画是否可见
	bool is_land_effect_visiable = false;	// 落地动画是否可见

	Vector2 position_jump_effect;			// 跳跃动画播放位置
	Vector2 position_land_effect;			// 落地动画播放位置

	Animation* current_animation = nullptr;	// 当前正在播放的动画

	PlayerID id = PlayerID::P1;				// 玩家序列号

	bool is_left_key_down = false;			// 向左的按键是否被按下
	bool is_right_key_down = false;			// 向右的按键是否被按下

	bool is_facing_left = false;			// 是否面向左侧

	int attack_cd = 500;					// 普通攻击冷却时间
	bool can_attack = true;					// 是否可以释放普通攻击
	Timer timer_attack_cd;					// 普通攻击冷却定时器

	bool is_attacking_ex = false;			// 是否在释放特殊攻击

	IMAGE img_sketch;						// 剪影后的图片
	bool is_invulnerable = false;			// 角色是否处于无敌帧
	bool is_showing_sketch_frame = false;	// 当前帧是否应该显示剪影
	Timer timer_invulnerable;				// 无敌状态定时器
	Timer timer_invulnerable_blink;			// 无敌状态闪烁定时器

	std::vector<Particle> particle_list;	// 粒子对象列表

	Timer timer_run_effect_generation;		// 跑动粒子特效发射定时器 
	Timer timer_die_effect_generation;		// 死亡粒子特效发射定时器

	bool is_cursor_visible = true;			// 玩家光标指示器是否显示
	Timer timer_cursor_visibility;			// 玩家光标指示器可见性定时器

	Vector2 last_hurt_direction;			// 最后一次受击方向
};