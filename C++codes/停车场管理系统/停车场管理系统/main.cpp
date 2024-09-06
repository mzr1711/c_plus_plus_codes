//停车场管理系统简介
//一、问题描述
//设停车场是一个可停放若干辆辆汽车的狭多层平面区域，且只有一个大门可供汽车进出。
//若车场内已停满汽车，则后来的汽车只能在门外的狭长便道上等候，一旦停车场内有车开走，则排在便道上的第一辆车即可进入。
//每辆停放在车场的车在它离开停车场时必须按它停留的时间长短交纳费用。
//其它说明：
//1.车辆一旦进入便道，不可回退，只能等待进入停车场。
//2.离开便道，进入停车场，开始计时；离开停车场时，根据离开时间和进入时间差计费。
//3.计费以30分钟为计费周期，每30分钟1.5元；不超过15分钟免费；24小时最高收费30元封顶。（这些数据可维护）
//
//二、功能要求：
//1.车辆进入便道需要输入车辆的信息，比如车辆的车牌号码。
//2.车辆从便道进入停车场需要输入车辆的信息，比如车辆的车牌号码、入场时间、所占车位。
//3.车辆离场时，需要输入车辆的信息，比如车辆的车牌号码、离场时间并计费；如便道有车，开始驱动车辆入场。
//4.计费定价维护。
//5.统计功能：车场车辆数、空车位数量、便道车数量；时间段内收费总额；指定车进出记录。
//6.查询功能：车所在车场位置。
//7.维护功能：计费方式维护。
//
//三、技术要求
//1.采用面向对象方法设计与分析，程序用C++语言实现
//2.采用专业的绘图工具（如Visio等）绘制类图与流程图
//
//其他要求：
//系统可扩充性、可维护性；

#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <string>

class Time
{
public:
	Time() = default;

	Time(char h, char m)
	{
		hour = h;
		minute = m;
	}

	void set_time(char h, char m)
	{
		hour = h;
		minute = m;
	}

	void show_info()
	{
		std::cout << hour << ":" << minute;
	}

	bool operator>=(Time time)
	{
		if (this->hour >= time.hour)
		{
			if (this->minute >= time.minute)
				return true;
			else
				return false;
		}
		else
			return false;
	}

	int operator-(Time time)
	{
		return (this->hour - time.hour) * 60 + this->minute - time.minute;
	}

private:
	int hour;
	int minute;
};

class Place
{
public:
	Place() = default;

	Place(int _layer, int _row, int _col)
	{
		layer = _layer;
		row = _row;
		col = _col;
	}

	int get_layer()
	{
		return layer;
	}

	int get_row()
	{
		return row;
	}

	int get_col()
	{
		return col;
	}

	void set_layer(int _layer)
	{
		layer = _layer;
	}

	void set_row(int _row)
	{
		row = _row;
	}

	void set_col(int _col)
	{
		col = _col;
	}

private:
	int layer;
	int row;
	int col;
};

class CarInfo
{
public:
	void set_id(std::string _id)
	{
		id = _id;
	}

	void set_enter_time(Time time)
	{
		enter_time = time;
	}

	void set_valid(bool _valid)
	{
		valid = _valid;
	}

	std::string get_id()
	{
		return id;
	}

	Time get_enter_time()
	{
		return enter_time;
	}

	bool check_valid()
	{
		return valid;
	}

	void show_info()
	{
		std::cout << "id:" << id;
		std::cout << ", time ";
		enter_time.show_info();
		//std::cout << ", valid = " << valid;
		std::cout << "    ";
	}

private:
	std::string id;
	Time enter_time = { 0,0 };
	bool valid = false;
};

class Shortcut
{
public:
	void enter(std::string id)
	{
		if (cars.size() >= max)
		{
			std::cout << "便道已满，无法进入!!!" << std::endl;
			return;
		}

		CarInfo new_car;
		new_car.set_id(id);
		cars.push(new_car);

		std::cout << "进入便道成功，当前便道车辆数为" << cars.size() << std::endl;
	}

	void set_max(int val)
	{
		max = val;
	}

	CarInfo& get_front_info()
	{
		CarInfo& car = cars.front();
		return car;
	}

	void pop()
	{
		cars.pop();
	}

private:
	std::queue<CarInfo> cars;
	int max = 5;
};

class Park
{
public:
	Park()
	{
		cars.resize(layer);
		for (int i = 0; i < layer; i++)
		{
			cars[i].resize(row);
			for (int j = 0; j < row; j++)
			{
				cars[i][j].resize(col);
			}
		}
	}

	void enter(Shortcut& shortcut, int i, int j, int k)
	{
		CarInfo car = shortcut.get_front_info();
		shortcut.pop();

		car.set_valid(true);
		cars[i][j][k] = car;
	}

	void show_park()
	{
		for (int i = 0; i < layer; i++)
		{
			for (int j = 0; j < row; j++)
			{
				for (int k = 0; k < col; k++)
				{
					if (cars[i][j][k].check_valid())
						cars[i][j][k].show_info();
					else
						std::cout << "empty\t";
				}
				std::cout << std::endl;
			}
			std::cout << std::endl;
		}
	}

	bool check_valid(int _layer, int _row, int _col)
	{
		return _layer >= 0 && _layer < layer && _row >= 0 && _row < row && _col >= 0 && _col < col;
	}

	CarInfo* search(std::string _id)
	{
		for (int i = 0; i < layer; i++)
		{
			for (int j = 0; j < row; j++)
			{
				for (int k = 0; k < col; k++)
				{
					if (cars[i][j][k].get_id() == _id)
					{
						return &cars[i][j][k];
					}
				}
			}
		}
		return nullptr;
	}

	void out_of_part(std::string _id)
	{
		for (int i = 0; i < layer; i++)
		{
			for (int j = 0; j < row; j++)
			{
				for (int k = 0; k < col; k++)
				{
					if (cars[i][j][k].get_id() == _id)
					{
						cars[i][j][k].set_id(" ");
						cars[i][j][k].set_enter_time({ 0,0 });
						cars[i][j][k].set_valid(false);
					}
				}
			}
		}
	}

private:
	std::vector<std::vector<std::vector<CarInfo>>> cars;
	int layer = 3;
	int row = 3;
	int col = 3;
};

void menu()
{
	std::cout << "******************************************************************" << std::endl;
	std::cout << "***------------------------------------------------------------***" << std::endl;
	std::cout << "***--------------------   停车场管理系统   --------------------***" << std::endl;
	std::cout << "***------------------------------------------------------------***" << std::endl;
	std::cout << "******************************************************************" << std::endl;
	std::cout << "*************         0.退出系统                     *************" << std::endl;
	std::cout << "*************         1.输入进入便道车辆信息         *************" << std::endl;
	std::cout << "*************         2.车辆从便道进入车库           *************" << std::endl;
	std::cout << "*************         3.车辆离开车库                 *************" << std::endl;
	std::cout << "*************         4.显示车库停车信息             *************" << std::endl;
	std::cout << "*************         5.计费定价维护                 *************" << std::endl;
	std::cout << "*************         6.显示计费定价                 *************" << std::endl;
	std::cout << "******************************************************************" << std::endl;
}

int main()
{
	bool is_running = true;

	Shortcut shortcut;
	Park park;

	while (is_running)
	{
		menu();

		std::cout << "请输入：" << std::endl;
		int input;
		std::cin >> input;

		std::string car_id;
		Time enter_time;
		Time out_time;
		int h, m;
		int layer, row, col;
		
		int count_circle;		// 计费周期，例如每30分钟计费一次
		float price_per_circle;	// 每个计费周期收取的费用，例如每30分钟收取1.5元
		int free_count_time;	// 在一个计费周期内超过多久开始计费，例如不超过15分钟免费
		float price_max;		// 最高收费多少，例如30元封顶

		float price = 0;

		// 退出系统
		if (input == 0)
		{
			is_running = false;
			std::cout << "退出成功" << std::endl;
		}
		// 输入进入便道车辆信息
		else if (input == 1)
		{
			std::cout << "请输入车牌号码：";
			std::cin >> car_id;

			shortcut.enter(car_id);
		}
		// 车辆从便道进入车库
		else if (input == 2)
		{
			CarInfo& car = shortcut.get_front_info();

			std::cout << "入场车牌号码为：" << car.get_id() << std::endl;

			std::cout << "入场时间：hour:";
			std::cin >> h;
			std::cout << "minute:";
			std::cin >> m;
			enter_time.set_time(h, m);

			std::cout << "所占车位：";
			std::cout << "layer：";
			std::cin >> layer;
			std::cout << "row:";
			std::cin >> row;
			std::cout << "col:";
			std::cin >> col;

			if (!park.check_valid(layer, row, col))
			{
				std::cout << "输入位置不在车库内" << std::endl;
			}
			else
			{
				car.set_enter_time(enter_time);

				park.enter(shortcut, layer, row, col);

				park.show_park();
			}
		}
		// 车辆离开车库
		else if(input == 3)
		{
			std::cout << "请输入要离开的车辆id：";
			std::cin >> car_id;

			CarInfo* car = park.search(car_id);
			
			if (car == nullptr)
			{
				std::cout << "未找到对应车辆" << std::endl;
			}
			else
			{
				std::ifstream ifs_price("price.txt", std::ios::out);

				if (ifs_price.is_open())
				{
					ifs_price >> count_circle >> price_per_circle >> free_count_time >> price_max;

					ifs_price.close();
				}

				std::cout << "离场时间：hour:";
				std::cin >> h;
				std::cout << "minute:";
				std::cin >> m;
				out_time.set_time(h, m);

				enter_time = car->get_enter_time();

				int overall_minute;

				if (out_time >= enter_time)
				{
					overall_minute = out_time - enter_time;

					if (overall_minute % 30 >= 15)
					{
						price += 1.5;
					}
					overall_minute /= 30;
					price += 1.5 * overall_minute;
					if (price > 30)
						price = 30;

					std::cout << "需支付费用：" << price << std::endl;

					park.out_of_part(car_id);
				}
			}
		}
		// 显示车库停车信息
		else if (input == 4)
		{
			park.show_park();
		}
		// 计费定价维护
		else if (input == 5)
		{
			std::ofstream ofs_price("price.txt", std::ios::out);

			if (ofs_price.is_open())
			{
				std::cout << "请输入修改后的定价方案" << std::endl;
				std::cout << "计费周期" << std::endl;
				std::cin >> count_circle;
				std::cout << "计费周期内收取的费用" << std::endl;
				std::cin >> price_per_circle;
				std::cout << "多少时间内算作免费" << std::endl;
				std::cin >> free_count_time;
				std::cout << "封顶价格" << std::endl;
				std::cin >> price_max;

				ofs_price << count_circle << " " << price_per_circle << " "
					<< free_count_time << " " << price_max << std::endl;

				ofs_price.close();

				std::cout << "写入成功" << std::endl;
			}
		}
		// 显示计费定价
		else if (input == 6)
		{
			std::ifstream ifs_price("price.txt", std::ios::out);

			if (ifs_price.is_open())
			{
				ifs_price >> count_circle >> price_per_circle >> free_count_time >> price_max;

				ifs_price.close();

				std::cout << "计费周期" << count_circle << std::endl;
				std::cout << "计费周期内收取的费用" << price_per_circle << std::endl;
				std::cout << "多少时间内算作免费" << free_count_time << std::endl;
				std::cout << "封顶价格" << price_max << std::endl;
			}
		}

		system("pause");
		system("cls");
	}

	return 0;
}