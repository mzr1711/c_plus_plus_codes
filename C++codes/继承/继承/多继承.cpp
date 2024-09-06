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
//class Base2
//{
//public:
//	Base2()
//	{
//		m_A = 300;
//	}
//public:
//	int m_A;
//};
//
//class Son :public Base, public Base2
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
//	Son s;
//	cout << s.m_A << endl;
//	cout << s.Base::m_A << endl;
//	cout << s.Base2::m_A << endl;
//}
//
//int main()
//{
//	test();
//	return 0;
//}