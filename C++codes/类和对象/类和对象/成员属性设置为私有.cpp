//#include <iostream>
//using namespace std;
//
//class Person
//{
//	//m_Name  可读可写
//	//m_Age   可读不可写
//	//m_Lover 不可读可写
//public:
//	//名字可读可写
//	void setName(string name)
//	{
//		m_Name = name;
//	}
//	string getName()
//	{
//		return m_Name;
//	}
//
//	//年龄可读不可写
//	int getAge()
//	{
//		m_Age = 10;
//		return m_Age;
//	}
//
//	//情人可写不可读
//	void setLover(string lover)
//	{
//		m_Lover = lover;
//	}
//
//private:
//	string m_Name;
//	int m_Age;
//	string m_Lover;
//};
//
//int main()
//{
//	Person p1;
//
//	p1.setName("张三");
//	cout << p1.getName() << endl;
//
//	cout << p1.getAge() << endl;
//
//	p1.setLover("仓井");
//	return 0;
//}