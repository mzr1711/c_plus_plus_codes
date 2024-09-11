#include <iostream>
using namespace std;


class Person
{
public:
	string name;
	int age;
};

template<typename T>
bool my_compare(T& a, T& b)
{
	return a == b;
}

template<> bool my_compare(Person& p1, Person& p2)
{
	if (p1.name == p2.name && p1.age == p2.age)
		return true;
	return false;
}

void test()
{
	int a = 10;
	int b = 10;

	bool ret = my_compare(a, b);

	if (ret)
		cout << "a == b" << endl;
	else
		cout << "a != b" << endl;

	Person p1 = { "mike", 20 };
	Person p2 = { "mike", 20 };
	
	//Person p2 = { "lious", 19 };

	ret = my_compare(p1, p2);

	if (ret)
		cout << "p1 == p2" << endl;
	else
		cout << "p1 != p2" << endl;
}

int main()
{
	test();

	return 0;
}