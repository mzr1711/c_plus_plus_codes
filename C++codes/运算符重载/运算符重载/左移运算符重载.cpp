//#include <iostream>
//using namespace std;
//
//class Person
//{
//	friend ostream& operator<<(ostream& cout, Person& p);
//public:
//	Person(int a, int b)
//	{
//		m_A = a;
//		m_B = b;
//	}
//private:
//	int m_A;
//	int m_B;
//};
////
////吊毛学32,学不了，等回来有单片机再学，掉毛别学标准库，学hal库，学寄存器，学不了一点，hal库学得快
//// 学c++
//// 左移运算符要想实现cout在左边只能在全局实现，不能在类内实现
//ostream& operator<<(ostream& cout, Person& p)
//{
//	cout << "p.m_A = " << p.m_A << " p.m_B = " << p.m_B;
//	return cout;
//}
//
//void test()
//{
//	Person p(10, 20);
//	cout << p << endl;
//}
//
//int main()
//{
//	test();
//	return 0;
//}