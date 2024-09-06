//#include <iostream>
//using namespace std;
//
//class Person
//{
//public:
//	Person()
//	{
//		cout << "构造函数的默认调用" << endl;
//	}
//	Person(int a)
//	{
//		cout << "构造函数的参数调用" << endl;
//	}
//	Person(const Person& p)
//	{
//		m_Age = p.m_Age;
//		cout << "构造函数的拷贝调用" << endl;
//	}
//
//	~Person()
//	{
//		cout << "析构函数调用" << endl;
//	}
//
//	int m_Age;
//};
//
//int main()
//{
//	//Person p1;  //默认
//	//Person p2(10);  //有参
//	//Person p3(p2);  //拷贝
//
//	//显示法
//	//Person p1;
//	//Person p2 = Person(10);  //<--匿名对象
//	//Person p3 = Person(p2);
//
//	//隐式转换法
//	Person p1;
//	Person p2 = 10;
//	Person p3 = p2;
//
//	return 0;
//}