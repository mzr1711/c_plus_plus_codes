//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//class Person
//{
//public:
//	Person() = default;
//	Person(std::string _name, int _age)
//	{
//		name = _name;
//		age = _age;
//	}
//
//public:
//	std::string name;
//	int age;
//};
//
//void print_person(Person p)
//{
//	std::cout << p.name << " " << p.age << std::endl;
//}
//
//void test()
//{
//	std::vector<Person> vector_person;
//
//	Person p1("Zhang San", 18);
//	Person p2("Zhang Si", 18);
//	Person p3("Zhang Wu", 18);
//	Person p4("Zhang Liu", 180);
//	Person p5("Zhang Qi", 120);
//
//	vector_person.push_back(p1);
//	vector_person.push_back(p2);
//	vector_person.push_back(p3);
//	vector_person.push_back(p4);
//	vector_person.push_back(p5);
//
//	//for (std::vector<Person>::iterator it = vector_person.begin(); it != vector_person.end(); it++)
//	//	std::cout << (*it).name << " " << (*it).age << std::endl;
//
//	for_each(vector_person.begin(), vector_person.end(), print_person);
//}
//
//void test2()
//{
//	std::vector<Person*> vector_person;
//
//	Person p1("Zhang San", 18);
//	Person p2("Zhang Si", 18);
//	Person p3("Zhang Wu", 18);
//	Person p4("Zhang Liu", 180);
//	Person p5("Zhang Qi", 120);
//
//	vector_person.push_back(&p1);
//	vector_person.push_back(&p2);
//	vector_person.push_back(&p3);
//	vector_person.push_back(&p4);
//	vector_person.push_back(&p5);
//
//	for (std::vector<Person*>::iterator it = vector_person.begin(); it != vector_person.end(); it++)
//		std::cout << (*it)->name << " " << (*it)->age << std::endl;
//}
//
//int main()
//{
//	test();
//
//	return 0;
//}