//#include <iostream>
//using namespace std;
//
//class Person
//{
//public:
//	Person();
//	Person operator+(Person& p);
//public:
//	int m_A;
//	int m_B;
//};
//
//Person::Person()
//{
//	m_A = 10;
//	m_B = 20;
//}
//
//Person Person::operator+(Person& p)
//{
//	Person temp;
//	temp.m_A = this->m_A + p.m_A;
//	temp.m_B = this->m_B + p.m_B;
//	return temp;
//}
//
//void test()
//{
//	Person p1, p2, p3;
//	p3 = p1 + p2;
//	cout << p3.m_A << " " << p3.m_B << endl;
//}
//
//int main()
//{
//	test();
//
//	return 0;
//}