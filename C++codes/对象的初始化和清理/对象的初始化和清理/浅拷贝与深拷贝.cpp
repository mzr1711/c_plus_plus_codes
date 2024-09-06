#include <iostream>
using namespace std;

class Person
{
public:
	Person(int age, int height)
	{
		m_Age = age;
		m_Height = new int(height);
		cout << "构造函数的参数调用" << endl;
	}
	Person(const Person& p)
	{
		m_Age = p.m_Age;
		//m_Height = p.m_Height;  //编译器默认实现就是这行代码
		//深拷贝操作
		m_Height = new int(*p.m_Height);

		cout << "构造函数的拷贝调用" << endl;
	}
	~Person()
	{
		//析构代码，将堆区开辟数据做释放操作
		if (m_Height != NULL)
		{
			delete m_Height;
			m_Height = NULL;
		}
		cout << "析构函数的调用" << endl;
	}

	int m_Age;
	int* m_Height;
};

void test01()
{
	Person p1(19, 178);

	cout << p1.m_Age << endl;
	cout << *p1.m_Height << endl;

	Person p2(p1);

	cout << p2.m_Age << endl;
	cout << *p2.m_Height << endl;
}

int main()
{
	test01();

	return 0;
}