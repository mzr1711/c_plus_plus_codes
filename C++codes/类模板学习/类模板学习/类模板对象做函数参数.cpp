//#include <iostream>
//
//using namespace std;
//
//template<class NameType, class AgeType>
//class Person
//{
//public:
//	Person(NameType _name, AgeType _age)
//	{
//		name = _name;
//		age = _age;
//	}
//
//	void show_infomation()
//	{
//		cout << "name = " << name << " age = " << age << endl;
//	}
//
//public:
//	NameType name;
//	AgeType age;
//};
//
//// 1.传入指定参数类型
//void print_person_1(Person<string, int>& person)
//{
//	cout << "1. ";
//	person.show_infomation();
//}
//
//// 2.
//template<class T1, class T2>
//void print_person_2(Person<T1, T2>& person)
//{
//	cout << "2. ";
//	person.show_infomation();
//	cout << "T1 type = " << typeid(T1).name() << endl;
//	cout << "T2 type = " << typeid(T2).name() << endl;
//}
//
//template<typename T>
//void print_person_3(T& person)
//{
//	cout << "3. ";
//	person.show_infomation();
//	cout << "T type = " << typeid(T).name() << endl;
//}
//
//void test()
//{
//	Person<string, int> p1("mike", 20);
//
//	p1.show_infomation();
//
//	print_person_1(p1);
//
//	print_person_2(p1);
//
//	print_person_3(p1); 
//}
//
//int main()
//{
//	test();
//
//	return 0;
//}