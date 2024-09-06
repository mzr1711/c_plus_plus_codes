#include <iostream>
using namespace std;

class Person
{
public:
	Person(int age)
	{
		this->age = age;
	}

	Person& person_test(Person& p)
	{
		this->age += p.age;
		return *this;
	}

	int age;
};

int main()
{
	Person p1(10);
	Person p2(20);
	p2.person_test(p1).person_test(p1).person_test(p2);
	cout << p2.age << endl;

	return 0;
}