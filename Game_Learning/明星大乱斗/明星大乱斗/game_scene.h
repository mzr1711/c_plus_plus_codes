#pragma once

#include <iostream>

#include "scene.h"
#include "scene_manager.h"
#include "camera.h"
#include "platform.h"
#include "status_bar.h"

extern IMAGE img_sky;									// 天空图片
extern IMAGE img_hills;									// 山脉图片
extern IMAGE img_platform_large;						// 大型平台图片
extern IMAGE img_platform_small;						// 小型平台图片

extern Camera main_camera;

extern SceneManager scene_manager;

extern std::vector<Platform> platform_list;

extern Player* player_1;
extern Player* player_2;

extern IMAGE* img_player_1_avatar;
extern IMAGE* img_player_2_avatar;

extern IMAGE img_1P_winner;							// 1P 获胜文本图片
extern IMAGE img_2P_winner;							// 2P 获胜文本图片
extern IMAGE img_winner_bar;						// 获胜玩家文本背景图片


class GameScene : public Scene {
public:
	GameScene() = default;
	~GameScene() = default;

	void OnEnter() {
		is_game_over = false;
		is_slide_out_started = false;

		pos_img_winner_bar.x = -img_winner_bar.getwidth();
		pos_img_winner_bar.y = (getheight() - img_winner_bar.getheight()) / 2;
		pos_x_img_winner_bar_dst = (getwidth() - img_winner_bar.getwidth()) / 2;

		pos_img_winner_text.x = pos_img_winner_bar.x;
		pos_img_winner_text.y = (getheight() - img_1P_winner.getheight()) / 2;
		pos_x_img_winner_text_dst = (getwidth() - img_1P_winner.getwidth()) / 2;

		timer_winner_slide_in.Restart();
		timer_winner_slide_in.SetWaitTime(2500);
		timer_winner_slide_in.SetOneShot(true);
		timer_winner_slide_in.SetCallback([&]()
			{
				is_slide_out_started = true;
			});

		timer_winner_slide_out.Restart();
		timer_winner_slide_out.SetWaitTime(1000);
		timer_winner_slide_out.SetOneShot(true);
		timer_winner_slide_out.SetCallback([&]()
			{
				scene_manager.SwitchTo(SceneManager::SceneType::MENU);
			});

		status_bar_P1.SetAvatar(img_player_1_avatar);
		status_bar_P2.SetAvatar(img_player_2_avatar);

		status_bar_P1.SetPosition(235, 625);
		status_bar_P2.SetPosition(675, 625);

		player_1->SetPosition(200, 50);
		player_2->SetPosition(975, 50);

		pos_img_sky.x = (getwidth() - img_sky.getwidth()) / 2;	
		pos_img_sky.y = (getheight() - img_sky.getheight()) / 2;
		
		pos_img_hills.x = (getwidth() - img_hills.getwidth()) / 2;
		pos_img_hills.y = (getheight() - img_hills.getheight()) / 2;

		platform_list.resize(4);

		Platform& large_platform = platform_list[0];
		large_platform.img = &img_platform_large;
		large_platform.render_position.x = 122;
		large_platform.render_position.y = 455;
		large_platform.shape.left = (float)large_platform.render_position.x + 30;
		large_platform.shape.right = (float)large_platform.render_position.x + img_platform_large.getwidth() - 30;
		large_platform.shape.y = (float)large_platform.render_position.y + 60;

		Platform& small_platform_1 = platform_list[1];
		small_platform_1.img = &img_platform_small;
		small_platform_1.render_position.x = 175;
		small_platform_1.render_position.y = 360;
		small_platform_1.shape.left = (float)small_platform_1.render_position.x + 40;
		small_platform_1.shape.right = (float)small_platform_1.render_position.x + img_platform_small.getwidth() - 40;
		small_platform_1.shape.y = (float)small_platform_1.render_position.y + img_platform_small.getheight() / 2;

		Platform& small_platform_2 = platform_list[2];
		small_platform_2.img = &img_platform_small;
		small_platform_2.render_position.x = 855;
		small_platform_2.render_position.y = 360;
		small_platform_2.shape.left = (float)small_platform_2.render_position.x + 40;
		small_platform_2.shape.right = (float)small_platform_2.render_position.x + img_platform_small.getwidth() - 40;
		small_platform_2.shape.y = (float)small_platform_2.render_position.y + img_platform_small.getheight() / 2;

		Platform& small_platform_3 = platform_list[3];
		small_platform_3.img = &img_platform_small;
		small_platform_3.render_position.x = 515;
		small_platform_3.render_position.y = 225;
		small_platform_3.shape.left = (float)small_platform_3.render_position.x + 40;
		small_platform_3.shape.right = (float)small_platform_3.render_position.x + img_platform_small.getwidth() - 40;
		small_platform_3.shape.y = (float)small_platform_3.render_position.y + img_platform_small.getheight() / 2;

		mciSendString(_T("play bgm_game repeat from 0"), NULL, 0, NULL);
	}

	void OnUpdate(int delta) {
		player_1->OnUpdate(delta);
		player_2->OnUpdate(delta);

		main_camera.OnUpdate(delta);

		bullet_list.erase(std::remove_if(
			bullet_list.begin(), bullet_list.end(),
			[](const Bullet* bullet)
			{
				bool deletable = bullet->CheckCanRemove();
				if (deletable) delete bullet;
				return deletable;
			}),
			bullet_list.end());

		for (Bullet* bullet : bullet_list)
			bullet->OnUpdate(delta);

		const Vector2& position_player_1 = player_1->GetPosition();
		const Vector2& position_player_2 = player_2->GetPosition();
		if (position_player_1.y >= getheight())
			player_1->SetHp(0);
		if (position_player_2.y >= getheight())
			player_2->SetHp(0);

		if (player_1->GetHp() <= 0 || player_2->GetHp() <= 0) {
			if (!is_game_over) {
				mciSendString(_T("stop bgm_game"), NULL, 0, NULL);
				mciSendString(_T("play ui_win from 0"), NULL, 0, NULL);

				is_game_over = true;
			}
		}

		status_bar_P1.SetHp(player_1->GetHp());
		status_bar_P2.SetHp(player_2->GetHp());
		status_bar_P1.SetMp(player_1->GetMp());
		status_bar_P2.SetMp(player_2->GetMp());
		
		if (is_game_over) {
			pos_img_winner_bar.x += (int)(speed_winner_bar * delta);
			pos_img_winner_text.x += (int)(speed_winner_text * delta);

			if (!is_slide_out_started) {
				timer_winner_slide_in.OnUpdate(delta);
				if (pos_img_winner_bar.x >= pos_x_img_winner_bar_dst)
					pos_img_winner_bar.x = pos_x_img_winner_bar_dst;
				if (pos_img_winner_text.x >= pos_x_img_winner_text_dst)
					pos_img_winner_text.x = pos_x_img_winner_text_dst;
			}
			else
				timer_winner_slide_out.OnUpdate(delta);
		}
	}

	void OnDraw(const Camera& camera) {
		putimage_alpha(camera, pos_img_sky.x, pos_img_sky.y, &img_sky);
		putimage_alpha(camera, pos_img_hills.x, pos_img_hills.y, &img_hills);

		for (const Platform& platform : platform_list)
			platform.OnDraw(camera);

		if (is_debug) {
			settextcolor(RGB(255, 0, 0));
			outtextxy(15, 15, _T("已开启调试模式，按 'Q' 键关闭"));
		}

		player_1->OnDraw(camera);
		player_2->OnDraw(camera);

		for (Bullet* bullet : bullet_list)
			bullet->OnDraw(camera);

		if (is_game_over) {
			putimage_alpha(pos_img_winner_bar.x, pos_img_winner_bar.y, &img_winner_bar);
			putimage_alpha(pos_img_winner_text.x, pos_img_winner_text.y,
				player_1->GetHp() > 0 ? &img_1P_winner : &img_2P_winner);
		}
		else {
			status_bar_P2.OnDraw();
			status_bar_P1.OnDraw();
		}
	}

	void OnInput(const ExMessage& msg) {
		player_1->OnInput(msg);
		player_2->OnInput(msg);

		switch (msg.message) {
		case WM_KEYUP:
			// 'Q'
			if (msg.vkcode == 0x51)
				is_debug = !is_debug;
			break;
		default:
			break;
		}
	}

	void OnExit() {
		delete player_1; player_1 = nullptr;
		delete player_2; player_2 = nullptr;

		is_debug = false;

		bullet_list.clear();
		main_camera.Reset();
	}

private:
	const float speed_winner_bar = 3.0f;	// 结算动效背景移动速度
	const float speed_winner_text = 1.5f;	// 结算动效文本移动速度

private:
	POINT pos_img_sky = { 0 };			// 天空背景图片
	POINT pos_img_hills = { 0 };		// 山脉背景图片

	StatusBar status_bar_P1;			// 玩家 1 的状态栏
	StatusBar status_bar_P2;			// 玩家 2 的状态栏

	bool is_game_over = false;			// 游戏是否结束

	POINT pos_img_winner_bar = { 0 };	// 结算动效背景位置
	POINT pos_img_winner_text = { 0 };	// 结算动效文本位置
	int pos_x_img_winner_bar_dst = 0;	// 结算动效背景移动的目标位置
	int pos_x_img_winner_text_dst = 0;	// 结算动效文本移动的目标位置
	Timer timer_winner_slide_in;		// 结算动效滑入定时器
	Timer timer_winner_slide_out;		// 结算动效滑出定时器
	bool is_slide_out_started = false;	// 结算动效是否开始滑出
};