//#include <iostream>
//using namespace std;
//
//class Base
//{
//public:
//	// 纯虚函数
//	// 只要有一个纯虚函数，这个类就叫做抽象类
//	// 抽象类特点：
//	// 1.无法实例化对象
//	// 2.子类必须重写父类的纯虚函数，否则也是抽象类
//	virtual void func() = 0;
//};
//
//class Son : public Base
//{
//public:
//	void func()
//	{
//		cout << "hello world!" << endl;
//	}
//};
//
//void test()
//{
//	Son son1;
//	son1.func()
//}
//
//int main()
//{
//	test();
//	return 0;
//}