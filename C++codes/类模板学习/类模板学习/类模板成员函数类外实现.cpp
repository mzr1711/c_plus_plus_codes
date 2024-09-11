//#include <iostream>
//using namespace std;
//
//
//template<class T1, class T2>
//class Person
//{
//public:
//	Person();
//
//	void show_infomationo();
//
//	T1 name;
//	T2 age;
//};
//
//template<class T1, class T2>
//Person<T1, T2>::Person()
//{
//	cout << "T1 type = " << typeid(T1).name() << endl;
//	cout << "T2 type = " << typeid(T2).name() << endl;
//}
//
//template<class T1, class T2>
//void Person<T1, T2>::show_infomationo()
//{
//	cout << "name = " << name << " age = " << age << endl;
//}
//
//
//void test()
//{
//	Person<string, int> p1;
//
//	p1.show_infomationo();
//}
//
//int main()
//{
//	test();
//
//	return 0;
//}