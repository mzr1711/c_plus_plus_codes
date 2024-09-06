#include <iostream>
using namespace std;

class Person
{
public:
	static void person_test()
	{
		m_age = 100;  // 静态成员函数可以访问静态变量
		//m_id = 100;  // 静态成员函数不能访问非静态变量
		cout << "静态成员函数的调用" << endl;
	}

	static int m_age;
	int m_id;
};

int Person::m_age = 20;

void test0()
{
	Person p1;
	cout << p1.m_age << endl;
	Person p2;
	cout << p2.m_age << endl;
	
	p1.person_test();
	p2.person_test();
	Person::person_test();//吊毛谢金良，吊毛，别乱动
}

void test1()
{
	cout << Person::m_age << endl;
}

int main()
{
	test0();
	test1();
	return 0;
}