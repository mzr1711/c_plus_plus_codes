#include <iostream>
using namespace std;

class Person
{
public:
	void person_test() const
	{
		//m_age = 100;  // const放在函数右侧表示函数内的参数不可改变
		// const限制this指针内的变量不可修改
		m_id = 100;
		cout << "m_id = " << m_id << endl;
	}

	int m_age;
	mutable int m_id;
};

int main()
{
	Person p1;
	p1.person_test();
	const Person p2;
	/p2.m_age = 10;  // 常对象只能调用常函数

	return 0;
}
