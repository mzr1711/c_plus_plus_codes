//#include <iostream>
//
//
//template<class T1, class T2>
//class Person;
//
//template<class T1, class T2>
//void print_person_2(Person<T1, T2> p)
//{
//	std::cout << "name = " << p.name << std::endl;
//}
//
//template<class T1, class T2>
//class Person
//{
//	friend void print_person(Person<T1, T2> p)
//	{
//		std::cout << "友元内调用 name = " << p.name << " age = " << p.age << std::endl;	
//	}
//
//	friend void print_person_2<>(Person<T1, T2> p);
//
//public:
//	Person(T1 _name, T2 _age);
//
//public:
//	T1 name;
//	T2 age;
//};
//
//template<class T1, class T2>
//Person<T1, T2>::Person(T1 _name, T2 _age)
//{
//	name = _name;
//	age = _age;
//}
//
//
//
//void test()
//{
//	Person<std::string, int> p1("Tom", 20);
//	print_person(p1);
//}
//
//int main()
//{
//	test();
//
//	return 0;
//}