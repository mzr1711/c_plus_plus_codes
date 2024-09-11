//#include <iostream>
//using namespace std;
//
//class AbstractDrinking
//{
//public:
//	// 煮水
//	virtual void Boil() = 0;
//	// 冲泡
//	virtual void Brew() = 0;
//	// 倒入杯中
//	virtual void PourInCup() = 0;
//	// 加入作料
//	virtual void PutSomething() = 0;
//
//	// 制作饮料
//	void MakeDrink()
//	{
//		Boil();
//		Brew();
//		PourInCup();
//		PutSomething();
//	}
//};
//
//class Coffee :public AbstractDrinking
//{
//public:
//	// 煮水
//	void Boil()
//	{
//		cout << "煮农夫三拳" << endl;
//	}
//	// 冲泡
//	void Brew()
//	{
//		cout << "冲咖啡粉" << endl;
//	}
//	// 倒入杯中
//	void PourInCup()
//	{
//		cout << "倒进杯中" << endl;
//	}
//	// 加入作料
//	void PutSomething()
//	{
//		cout << "加入牛奶" << endl;
//	}
//};
//
//class Tea :public AbstractDrinking
//{
//public:
//	// 煮水
//	void Boil()
//	{
//		cout << "煮自来水" << endl;
//	}
//	// 冲泡
//	void Brew()
//	{
//		cout << "冲茶叶" << endl;
//	}
//	// 倒入杯中
//	void PourInCup()
//	{
//		cout << "倒进杯中" << endl;
//	}
//	// 加入作料
//	void PutSomething()
//	{
//		cout << "加入枸杞" << endl;
//	}
//};
//
//// 制作函数
//void doWork(AbstractDrinking* abs)
//{
//	abs->MakeDrink();
//	delete abs;
//}
//
//void test()
//{
//	doWork(new Coffee);
//	cout << "---------------------" << endl;
//	doWork(new Tea);
//}
//
//int main()
//{
//	test();
//	return 0;
//}