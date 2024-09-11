//#include <iostream>
//using namespace std;
//
//class Father
//{
//public:
//	int m_a;
//protected:
//	int m_b;
//private:
//	int m_c;
//};
//
//// 公共继承
//class Son1 :public Father
//{
//public:
//	void func()
//	{
//		m_a = 10;  // 父类的公共权限成员，到子类依然是工共权限
//		m_b = 10;  // 父类的保护权限成员，到子类依然是保护权限
//		//m_c = 10;  // 父类的私有权限成员，无法被子类继承
//	}
//};
//
//// 保护继承
//class Son2 :protected Father
//{
//	void func()
//	{
//		m_a = 20;
//		m_b = 20;
//		//m_c = 20;
//	}
//};
//
//// 私有继承
//class Son3 :private Father
//{
//	void func()
//	{
//		m_a = 30;
//		m_b = 30;
//		//m_c = 30;
//	}
//};
//
//void test1()
//{
//	Son1 s1;
//	s1.m_a;
//	//s1.m_b;  // 保护权限类内可以访问，类外访问不到
//}
//
//void test2()
//{
//	Son2 s2;
//	//s2.m_a;  // 保护继承后，公共权限变为保护权限
//}
//
//void test3()
//{
//
//}
//
//int main()
//{
//	test1();
//	return 0;
//}