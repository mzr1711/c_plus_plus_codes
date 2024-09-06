//#include <iostream>
//using namespace std;
//
//class MyInteger
//{
//	friend ostream& operator<<(ostream& cout, MyInteger my_int);
//public:
//	MyInteger();
//
//	// ++运算符重载
//	// 前置++
//	MyInteger& operator++();
//	// 后置++
//
//private:
//	int m_Num;
//};
//
//MyInteger::MyInteger()
//{
//	m_Num =	10;
//}
//
//MyInteger& MyInteger::operator++()
//{
//	m_Num++;
//	return *this;
//}
//
//ostream& operator<<(ostream& cout, MyInteger my_int)
//{
//	cout << my_int.m_Num;
//	return cout;
//}
//
//void test()
//{
//	MyInteger my_int;
//	cout << my_int << endl;
//
//	cout << ++(++my_int) << endl;
//	cout << my_int << endl;
//}
//
//int main()
//{
//	test();
//	return 0;
//}