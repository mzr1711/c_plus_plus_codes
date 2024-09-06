//#include <iostream>
//using namespace std;
//
//class Base
//{
//public:
//	Base()
//	{
//		m_A = 100;
//	}
//	void func()
//	{
//		cout << "Base" << endl;
//	}
//public:
//	int m_A;
//};
//
//class Son :public Base
//{
//public:
//	Son()
//	{
//		m_A = 200;
//	}
//	void func()
//	{
//		cout << "Son" << endl;
//	}
//public:
//	int m_A;
//};
//
//void test()
//{
//	Son s1;
//	cout << s1.m_A << endl;
//	cout << s1.Base::m_A << endl;
//	s1.func();
//	s1.Base::func();
//}
//
//int main()
//{
//	test();
//	return 0;
//}