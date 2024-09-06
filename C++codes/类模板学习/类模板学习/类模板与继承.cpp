//#include <iostream>
//using namespace std;
//
//
//template<class NameType>
//class Person
//{
//public:
//	NameType name;
//};
//
//class Student : public Person<string>
//{
//
//};
//
//template<typename T1, typename T2>
//class Teacher : public Person<T2>
//{
//public:
//	Teacher()
//	{
//		cout << "T1 type = " << typeid(T1).name() << endl;
//		cout << "T2 type = " << typeid(T2).name() << endl;
//	}
//
//public:
//	T1 obj;
//};
//
//
//void test()
//{
//	Student s1;
//
//	Teacher<int, char> t1;
//}
//
//int main()
//{
//	test();
//
//	return 0;
//}