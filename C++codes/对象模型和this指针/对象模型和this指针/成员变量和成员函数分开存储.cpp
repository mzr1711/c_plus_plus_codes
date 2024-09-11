#include <iostream>
using namespace std;

class Person
{
public:
	void ShowAge()
	{
		cout << m_age << endl;
	}
	static void ShowId()
	{
		cout << m_id << endl;
	}
	
	int m_age;
	static int m_id;
};

void test()
{
	Person p1;  // 空对象创建也会有1字节的空间
	cout << sizeof(p1) << endl;//吊毛
	//好好学离散数学，吊毛，课都不听的
}

//int main()
//{
//	test();
//	return 0;
//}