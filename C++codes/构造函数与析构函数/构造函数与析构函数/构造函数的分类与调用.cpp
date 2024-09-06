#include <iostream>
using namespace std;

class Person {
public:
	Person() {
		m_age = 0;
		cout << "默认构造函数的调用" << endl;
	}
	Person(int a) {
		m_age = a;
		cout << "有参构造函数的调用" << endl;
	}
	Person(const Person& p) {
		m_age = p.m_age;
		cout << "拷贝构造函数的调用" << endl;
	}

	~Person() {
		cout << "析构函数的调用" << endl;
	}

	int GetAge() {
		return m_age;
	}

private:
	int m_age;
};

int main() {
	//// 1.括号法
	//Person p1;
	//Person p2(10);
	//Person p3(p2);
	// 
	//// 2.显示法
	//Person p1;
	//Person p2 = Person(10);
	//Person p3 = Person(p2);

	// 3.隐式转换法
	Person p1;
	Person p2 = 10;
	Person p3 = p2;

	cout << "p1的年龄为:" << p1.GetAge() << endl;
	cout << "p2的年龄为:" << p2.GetAge() << endl;
	cout << "p3的年龄为:" << p3.GetAge() << endl;

	return 0;
}