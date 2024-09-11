//#include <iostream>
//using namespace std;
//
//class MyInteger
//{
//public:
//	MyInteger(int num);
//
//	MyInteger& operator=(MyInteger i)
//	{
//		// 如果堆空间有数据，将数据清空
//		if (m_Num != NULL)
//		{
//			delete m_Num;
//			m_Num = NULL;
//		}
//		m_Num = new int(*i.m_Num);
//		return *this;
//	}
//public:
//	int* m_Num;
//};
//
//MyInteger::MyInteger(int num)
//{
//	m_Num = new int(num);
//}
//
//void test()
//{
//	MyInteger i1(10);
//	MyInteger i2(20);
//	MyInteger i3(30);
//
//	i1 = i2 = i3;
//	cout << *i1.m_Num << *i2.m_Num << *i3.m_Num << endl;
//}
//
//int main()
//{
//	test();
//	return 0;
//}