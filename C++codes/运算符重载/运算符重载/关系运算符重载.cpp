//#include <iostream>
//using namespace std;
//
//class Person
//{
//public:
//	Person(string name, int age)
//	{
//		m_Name = name;
//		m_Age = age;
//	}
//	bool operator>(Person p);
//	bool operator<(Person p);
//	bool operator==(Person p);
//	bool operator>=(Person p);
//	bool operator<=(Person p);
//private:
//	string m_Name;
//	int m_Age;
//};
//
//bool Person::operator>(Person p)
//{
//	if (m_Age > p.m_Age)
//		return true;
//	return false;
//}
//
//bool Person::operator<(Person p)
//{
//	if (m_Age < p.m_Age)
//		return true;
//	return false;
//}
//
//bool Person::operator==(Person p)
//{
//	if (m_Age == p.m_Age)
//		return true;
//	return false;
//}
//
//bool Person::operator>=(Person p)
//{
//	if (m_Age >= p.m_Age)
//		return true;
//	return false;
//}
//
//bool Person::operator<=(Person p)
//{
//	if (m_Age <= p.m_Age)
//		return true;
//	return false;
//}
//
//int main()
//{
//	Person p1("张三", 20);
//	Person p2("李四", 20);
//
//	if (p1 > p2)
//		cout << "p1 > p2" << endl;
//	else if (p1 < p2)
//		cout << "p1 < p2" << endl;
//	else
//		cout << "p1 == p2" << endl;
//
//	if (p1 == p2)
//		cout << "hello" << endl;
//
//	if (p1 >= p2)
//		cout << "world" << endl;
//
//	if (p1 <= p2)
//		cout << "你好" << endl;
//
//	return 0;
//}