#include <string>
#include <vector>
#include <graphics.h>

enum {
	IDLE,
	MOVE_UP,
	MOVE_DOWN,
	MOVE_LEFT,
	MOVE_RIGHT
};

enum {
	HEIGHT_WINDOW = 720,
	WIDTH_WINDOW = 1280
};

enum {
	HEIGHT_BUTTON = 80,
	WIDTH_BUTTON = 160
};

#define PLAYER_IDLE_ANIM_NUM  2


bool running = true;
bool is_game_started = false;


#pragma comment(lib, "Winmm.lib")
#pragma comment(lib, "MSIMG32.LIB")
inline void putimage_alpha(int x, int y, IMAGE* img) {
	int w = img->getwidth();
	int h = img->getheight();
	AlphaBlend(GetImageHDC(NULL), x, y, w, h,
		GetImageHDC(img), 0, 0, w, h, { AC_SRC_OVER, 0, 255, AC_SRC_ALPHA });
}

class Atlas {
public:
	Atlas(LPCTSTR path, int num) {
		TCHAR path_file[256];
		for (size_t i = 0; i < num; i++) {
			_stprintf_s(path_file, path, i);

			IMAGE* frame = new IMAGE();
			loadimage(frame, path_file);
			frame_list.push_back(frame);
		}
	}

	~Atlas() {
		for (size_t i = 0; i < frame_list.size(); i++)
			delete frame_list[i];
	}

public:
	std::vector<IMAGE*> frame_list;
};

Atlas* atlas_player_left;
Atlas* atlas_player_right;
Atlas* atlas_enemy_left;
Atlas* atlas_enemy_right;


class Animation {
public:
	Animation(Atlas* atlas, int interval) {
		anim_atlas = atlas;
		interval_ms = interval;
	}

	~Animation() = default;

	void Play(int x, int y, int delta) {
		timer += delta;
		if (timer >= interval_ms) {
			timer = 0;
			index_frame = (index_frame + 1) % anim_atlas->frame_list.size();
		}
		putimage_alpha(x, y, anim_atlas->frame_list[index_frame]);
	}

private:
	Atlas* anim_atlas;
	int timer = 0;
	int index_frame = 0;
	int interval_ms = 0;
};

class Player {
public:
	Player() {
		loadimage(&img_shadow, _T("res/player_shadow.png"));
		anim_left = new Animation(atlas_player_left, 45);
		anim_right = new Animation(atlas_player_right, 45);
	}

	~Player() {
		delete anim_left;
		delete anim_right;
	}

	void ProcessEvent(const ExMessage& msg) {
		if (msg.message == WM_KEYDOWN) {
			if (msg.vkcode == VK_UP || msg.vkcode == 0x57)
				is_up_move = true;
			if (msg.vkcode == VK_DOWN || msg.vkcode == 0x53)
				is_down_move = true;
			if (msg.vkcode == VK_LEFT || msg.vkcode == 0x41)
				is_left_move = true;
			if (msg.vkcode == VK_RIGHT || msg.vkcode == 0x44)
				is_right_move = true;
		}
		if (msg.message == WM_KEYUP) {
			if (msg.vkcode == VK_UP || msg.vkcode == 0x57)
				is_up_move = false;
			if (msg.vkcode == VK_DOWN || msg.vkcode == 0x53)
				is_down_move = false;
			if (msg.vkcode == VK_LEFT || msg.vkcode == 0x41)
				is_left_move = false;
			if (msg.vkcode == VK_RIGHT || msg.vkcode == 0x44)
				is_right_move = false;
		}
	}

	void Move() {
		int dir_x = is_right_move - is_left_move;
		int dir_y = is_down_move - is_up_move;
		double len_dir = sqrt(dir_x * dir_x + dir_y * dir_y);
		if (len_dir != 0) {
			double normalized_x = dir_x / len_dir;
			double normalized_y = dir_y / len_dir;
			position.x += (int)(normalized_x * SPEED);
			position.y += (int)(normalized_y * SPEED);
		}

		if (position.x <= 0) position.x = 0;
		if (position.x >= WIDTH_WINDOW - FRAME_WIDTH) position.x = WIDTH_WINDOW - FRAME_WIDTH;
		if (position.y <= 0) position.y = 0;
		if (position.y >= HEIGHT_WINDOW - FRAME_HEIGHT) position.y = HEIGHT_WINDOW - FRAME_HEIGHT;
	}

	void Draw(int delta) {
		int pos_shadow_x = position.x;
		int pos_shadow_y = position.y + 5 * 4;
		putimage_alpha(pos_shadow_x, pos_shadow_y, &img_shadow);

		int dir_x = is_right_move - is_left_move;
		if (dir_x < 0)
			facing_left = true;
		else if (dir_x > 0)
			facing_left = false;

		if (facing_left)
			anim_left->Play(position.x, position.y, delta);
		else
			anim_right->Play(position.x, position.y, delta);

		setlinecolor(RGB(255, 255, 255));
		line(position.x + FRAME_WIDTH / 4, position.y + FRAME_HEIGHT / 4,
			position.x + FRAME_WIDTH * 3 / 4, position.y + FRAME_HEIGHT / 4);
		line(position.x + FRAME_WIDTH / 4, position.y + FRAME_HEIGHT * 3 / 4,
			position.x + FRAME_WIDTH * 3 / 4, position.y + FRAME_HEIGHT * 3 / 4);
		line(position.x + FRAME_WIDTH / 4, position.y + FRAME_HEIGHT / 4,
			position.x + FRAME_WIDTH / 4, position.y + FRAME_HEIGHT * 3 / 4);
		line(position.x + FRAME_WIDTH * 3 / 4, position.y + FRAME_HEIGHT / 4,
			position.x + FRAME_WIDTH * 3 / 4, position.y + FRAME_HEIGHT * 3 / 4);
	}

	const POINT& GetPosition() const {
		return position;
	}

	void BackToPoint() {
		position = { (WIDTH_WINDOW - FRAME_WIDTH) / 2, (HEIGHT_WINDOW - FRAME_HEIGHT) / 2 };
	}

public:
	const int SPEED = 3;           // 玩家移动速度
	const int FRAME_WIDTH = 128;   // 玩家图片宽度
	const int FRAME_HEIGHT = 128;  // 玩家图片高度
	const int SHADOW_WIDTH = 128;

private:
	IMAGE img_shadow;
	Animation* anim_left;
	Animation* anim_right;
	POINT position = { (WIDTH_WINDOW - FRAME_WIDTH) / 2, (HEIGHT_WINDOW - FRAME_HEIGHT) / 2 };
	bool is_up_move = false;
	bool is_down_move = false;
	bool is_left_move = false;
	bool is_right_move = false;
	bool facing_left = false;
};

class Bullet {
public:
	POINT position = { 0, 0 };

public:
	Bullet() = default;
	~Bullet() = default;

	void Draw() {
		setlinecolor(RGB(255, 155, 50));
		setfillcolor(RGB(200, 75, 10));
		fillcircle(position.x, position.y, RADIUS);
	}

private:
	const int RADIUS = 10;
};

class Enemy {
public:
	Enemy() {
		loadimage(&img_shadow, _T("res/enemy_shadow.png"));
		anim_left = new Animation(atlas_enemy_left, 45);
		anim_right = new Animation(atlas_enemy_right, 45);

		enum class SpawnEdge {
			UP,
			DOWN,
			LEFT,
			RIGHT
		};
		SpawnEdge edge = (SpawnEdge)(rand() % 4);
		switch (edge) {
		case SpawnEdge::UP:
			position.x = rand() % (WIDTH_WINDOW - FRAME_WIDTH);
			position.y = -FRAME_HEIGHT;
			break;
		case SpawnEdge::DOWN:
			position.x = rand() % (WIDTH_WINDOW - FRAME_WIDTH);
			position.y = HEIGHT_WINDOW + FRAME_HEIGHT;
			break;
		case SpawnEdge::LEFT:
			position.x = -FRAME_WIDTH;
			position.y = rand() % (HEIGHT_WINDOW - FRAME_HEIGHT);
			break;
		case SpawnEdge::RIGHT:
			position.x = WIDTH_WINDOW + FRAME_WIDTH;
			position.y = rand() % (HEIGHT_WINDOW - FRAME_HEIGHT);
			break;
		}
	}

	~Enemy() {
		delete anim_left;
		delete anim_right;
	}

	bool CheckBulletCollision(const Bullet& bullet) {
		if (bullet.position.x > position.x + FRAME_WIDTH / 4 &&
			bullet.position.x < position.x + FRAME_WIDTH * 3 / 4) {
			if (bullet.position.y > position.y + FRAME_HEIGHT / 3 &&
				bullet.position.y < position.y + FRAME_HEIGHT) {
				return true;
			}
		}
		return false;
	}

	bool CheckPlayerCollision(const Player& player) {
		if (!alive)
			return false;
		// 将敌人的碰撞中心简化为点，判断是否在玩家矩形内
		POINT check_pos = { position.x + FRAME_WIDTH / 2, position.y + FRAME_HEIGHT * 2 / 3 };
		const POINT& player_pos = player.GetPosition();
		if (check_pos.x > player_pos.x + player.FRAME_WIDTH / 4 &&
			check_pos.y < player_pos.x + player.FRAME_WIDTH * 3 / 4) {
			if (check_pos.y > player_pos.y + player.FRAME_HEIGHT / 4 &&
				check_pos.y < player_pos.y + player.FRAME_HEIGHT * 3 / 4) {
				return true;
			}
		}
		return false;
	}

	void Move(const Player& player) {
		const POINT& player_pos = player.GetPosition();
		int dir_x = player_pos.x - position.x;
		int dir_y = player_pos.y - position.y;
		double len_dir = sqrt(dir_x * dir_x + dir_y * dir_y);
		if (len_dir != 0) {
			double normalized_x = dir_x / len_dir;
			double normalized_y = dir_y / len_dir;
			position.x += (int)(normalized_x * SPEED);
			position.y += (int)(normalized_y * SPEED);
		}

		if (dir_x > 0)
			facing_left = false;
		else
			facing_left = true;
	}

	void Draw(int delta) {
		int pos_shadow_x = position.x;
		int pos_shadow_y = position.y + 3 * 5;
		putimage_alpha(pos_shadow_x, pos_shadow_y, &img_shadow);

		POINT check_pos = { position.x + FRAME_WIDTH / 2, position.y + FRAME_HEIGHT * 2 / 3 };

		if (facing_left)
			anim_left->Play(position.x, position.y, delta);
		else
			anim_right->Play(position.x, position.y, delta);

		setlinecolor(BLUE);
		circle(check_pos.x, check_pos.y, 20);
	}

	void Hurt() {
		alive = false;
	}

	bool CheckAlive() {
		return alive;
	}

	const POINT& GetPosition() const {
		return position;
	}

private:
	const int SPEED = 2;
	const int FRAME_HEIGHT = 120;
	const int FRAME_WIDTH = 120;
	const int SHADOW_WIDTH = 120;

private:
	IMAGE img_shadow;
	Animation* anim_left;
	Animation* anim_right;
	POINT position = { 0, 0 };
	bool facing_left = false;
	bool alive = true;
};

class Button {
public:
	Button(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed) {
		region = rect;

		loadimage(&img_idle, path_img_idle);
		loadimage(&img_hovered, path_img_hovered);
		loadimage(&img_pushed, path_img_pushed);
	}

	~Button() = default;

	void ProcessEvent(const ExMessage& msg) {
		switch (msg.message) {
		case WM_MOUSEMOVE:
			if (CheckCursorHit(msg.x, msg.y))
				status = Status::HOVERED;
			else
				status = Status::IDLE;
			break;
		case WM_LBUTTONDOWN:
			if (CheckCursorHit(msg.x, msg.y))
				status = Status::PUSHED;
		case WM_LBUTTONUP:
			if (status == Status::PUSHED)
				OnClick();
			break;
		default:
			break;
		}
	}

	void Draw() {
		switch (status) {
		case Status::IDLE:
			putimage_alpha(region.left, region.top, &img_idle);
			break;
		case Status::HOVERED:
			putimage_alpha(region.left, region.top, &img_hovered);
			break;
		case Status::PUSHED:
			putimage_alpha(region.left, region.top, &img_pushed);
			break;
		}
	}

private:
	bool CheckCursorHit(int x, int y) {
		return x > region.left && x < region.right && y > region.top && y < region.bottom;
	}

protected:
	virtual void OnClick() = 0;

private:
	enum class Status {
		IDLE = 0,
		HOVERED,
		PUSHED
	};

private:
	RECT region;
	IMAGE img_idle;
	IMAGE img_hovered;
	IMAGE img_pushed;
	Status status = Status::IDLE;
};

class StartGameButton : public Button {
public:
	StartGameButton(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed)
		: Button(rect, path_img_idle, path_img_hovered, path_img_pushed) {}

	~StartGameButton() = default;

protected:
	void OnClick() {
		is_game_started = true;

		mciSendString(_T("play bgm repeat from 0"), NULL, 0, NULL);
	}
};

class QuitGameButton : public Button {
public:
	QuitGameButton(RECT rect, LPCTSTR path_img_idle, LPCTSTR path_img_hovered, LPCTSTR path_img_pushed)
		: Button(rect, path_img_idle, path_img_hovered, path_img_pushed) {}

	~QuitGameButton() = default;

protected:
	void OnClick() {
		running = false;
	}
};


void TryGenerateEnemy(std::vector<Enemy*>& enemy_list) {
	const int INTERVAL = 100;
	static int counter = 0;
	if ((++counter) % INTERVAL == 0) {
		counter = 0;
		enemy_list.push_back(new Enemy());
	}
}

void UpdataBullet(std::vector<Bullet>& bullet_list, const Player& player) {
	const double RADIAL_SPEED = 0.0045;  // 径向波动速度
	const double TANGENT_SPEED = 0.0055;  // 切向波动速度
	double radian_interval = 2 * 3.14159265 / bullet_list.size();  // 子弹之间的弧度间隔
	POINT player_pos = player.GetPosition();
	double radius = 100 + 25 * sin(GetTickCount() * RADIAL_SPEED);  // 半径
	for (int i = 0; i < bullet_list.size(); i++) {
		double radian = radian_interval * i + GetTickCount() * TANGENT_SPEED;  // 弧度
		bullet_list[i].position.x = player_pos.x + player.FRAME_WIDTH / 2 + radius * sin(radian);
		bullet_list[i].position.y = player_pos.y + player.FRAME_HEIGHT / 2 + radius * cos(radian);
	}
}

void DrawPlayerScore(int score, const std::vector<Enemy*> enemy_list, const Player& player) {
	int distance = 1300;
	for (Enemy* enemy : enemy_list) {
		POINT enemy_pos = enemy->GetPosition();
		POINT player_pos = player.GetPosition();
		int dist = sqrt((player_pos.x - enemy_pos.x) * (player_pos.x - enemy_pos.x) +
			(player_pos.y - enemy_pos.y) * (player_pos.y - enemy_pos.y));
		if (dist < distance) {
			distance = dist;
		}
	}

	static TCHAR text[64];
	_stprintf_s(text, _T("当前得分为：%d， 当前最近敌人距离为：%d"), score, distance);

	setbkmode(TRANSPARENT);
	settextcolor(RGB(255, 85, 185));
	outtextxy(10, 10, text);
}


int main() {
	initgraph(1280, 720);

	atlas_player_left = new Atlas(_T("res/caractor_left%d.png"), 2);
	atlas_player_right = new Atlas(_T("res/caractor_right%d.png"), 2);
	atlas_enemy_left = new Atlas(_T("res/enemy_left%d.png"), 8);
	atlas_enemy_right = new Atlas(_T("res/enemy_right%d.png"), 8);

	int score = 0;

	ExMessage msg;

	Player player;
	std::vector<Enemy*> enemy_list;
	std::vector<Bullet> bullet_list(3);

	IMAGE img_background;
	IMAGE img_menu;

	mciSendString(_T("open mus/背景音乐后院.mp3 alias bgm"), NULL, 0, NULL);
	mciSendString(_T("open mus/火球撞击.mp3 alias hit"), NULL, 0, NULL);

	RECT region_btn_start_game, region_btn_quit_game;

	region_btn_start_game.left = (WIDTH_WINDOW - WIDTH_BUTTON) / 2;
	region_btn_start_game.right = region_btn_start_game.left + WIDTH_BUTTON;
	region_btn_start_game.top = 400;
	region_btn_start_game.bottom = region_btn_start_game.top + HEIGHT_BUTTON;
	region_btn_quit_game.left = (WIDTH_WINDOW - WIDTH_BUTTON) / 2;
	region_btn_quit_game.right = region_btn_quit_game.left + WIDTH_BUTTON;
	region_btn_quit_game.top = 520;
	region_btn_quit_game.bottom = region_btn_quit_game.top + HEIGHT_BUTTON;

	StartGameButton btn_start_game = StartGameButton(region_btn_start_game,
		_T("res/button_start_idle.png"), _T("res/button_start_hovered.png"), _T("res/button_start_pushed.png"));
	QuitGameButton btn_quit_game = QuitGameButton(region_btn_quit_game,
		_T("res/button_quit_idle.png"), _T("res/button_quit_hovered.png"), _T("res/button_quit_pushed.png"));

	loadimage(&img_background, _T("res/background.png"));
	loadimage(&img_menu, _T("res/menu.png"));

	BeginBatchDraw();
	while (running) {
		DWORD start_time = GetTickCount();

		while (peekmessage(&msg)) {
			if(is_game_started)
				player.ProcessEvent(msg);
			else {
				btn_start_game.ProcessEvent(msg);
				btn_quit_game.ProcessEvent(msg);
			}
		}

		if (is_game_started) {
			player.Move();
			UpdataBullet(bullet_list, player);
			TryGenerateEnemy(enemy_list);
			for (Enemy* enemy : enemy_list)
				enemy->Move(player);

			// 检测子弹和敌人碰撞
			for (const Bullet& bullet : bullet_list) {
				for (Enemy* enemy : enemy_list) {
					if (enemy->CheckBulletCollision(bullet)) {
						mciSendString(_T("play hit from 0"), NULL, 0, NULL);
						enemy->Hurt();
						score++;
					}
				}
			}
			// 移除生命值为0的敌人
			for (size_t i = 0; i < enemy_list.size(); i++) {
				Enemy* enemy = enemy_list[i];
				if (!enemy->CheckAlive()) {
					std::swap(enemy_list[i], enemy_list.back());
					enemy_list.pop_back();
					delete enemy;
				}
			}
			// 检测敌人和玩家碰撞
			for (Enemy* enemy : enemy_list) {
				if (enemy->CheckPlayerCollision(player)) {
					static TCHAR text[128];
					_stprintf_s(text, _T("最终得分为：%d"), score);
					MessageBox(GetHWnd(), text, _T("游戏结束"), MB_OK);
					is_game_started = false;
					break;
				}
			}
			if (is_game_started == false) {
				for (size_t i = 0; i < enemy_list.size(); i++) {
					Enemy* enemy = enemy_list[i];
					std::swap(enemy_list[i], enemy_list.back());
					enemy_list.pop_back();
					delete enemy;
				}
				player.BackToPoint();
				score = 0;
			}
		}

		cleardevice();

		if (is_game_started) {
			putimage(0, 0, &img_background);
			for (Enemy* enemy : enemy_list)
				enemy->Draw(1000 / 144);
			player.Draw(1000 / 144);
			for (Bullet& bullet : bullet_list)
				bullet.Draw();
			DrawPlayerScore(score, enemy_list, player);
		}
		else {
			putimage(0, 0, &img_menu);
			btn_start_game.Draw();
			btn_quit_game.Draw();
		}

		FlushBatchDraw();

		DWORD end_time = GetTickCount();
		DWORD delta_time = end_time - start_time;
		if (delta_time < 1000 / 144)
			Sleep(1000 / 144 - delta_time);
	}
	EndBatchDraw();

	delete atlas_player_left;
	delete atlas_player_right;
	delete atlas_enemy_left;
	delete atlas_enemy_right;

	return 0;
}