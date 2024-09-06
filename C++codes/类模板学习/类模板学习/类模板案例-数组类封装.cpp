#include <iostream>
#include "my_array.hpp"

class Person
{
public:
	Person() = default;
	Person(std::string _name, int _age)
	{
		name = _name;
		age = _age;
	}

public:
	std::string name;
	int age;
};

void print_array(MyArray<int> arr)
{
	for (int i = 0; i < arr.get_size(); i++)
		std::cout << arr[i] << std::endl;
}

void print_array_person(MyArray<Person> arr)
{
	for (int i = 0; i < arr.get_size(); i++)
		std::cout << arr[i].name << arr[i].age << std::endl;
}

void test()
{
	//MyArray<int> arr_1(5);
	//MyArray<int> arr_2(arr_1);
	//MyArray<int> arr_3(10);
	//arr_3 = arr_2;

	MyArray<int> arr_1(5);
	for (int i = 0; i < 5; i++)
		arr_1.push_back(i);
	print_array(arr_1);

	std::cout << arr_1.get_capacity() << std::endl;
	std::cout << arr_1.get_size() << std::endl;

	MyArray<int> arr_2(arr_1);
	arr_2.pop_back();

	std::cout << arr_2.get_capacity() << std::endl;
	std::cout << arr_2.get_size() << std::endl;

	MyArray<Person> arr_person(10);
	Person p1("Li Hua", 20);
	Person p2("Zhang san", 18);
	Person p3("Sun Wukong", 999);

	arr_person.push_back(p1);
	arr_person.push_back(p2);
	arr_person.push_back(p3);

	print_array_person(arr_person);
}

int main()
{
	test();

	return 0;
}