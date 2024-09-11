#include <iostream>
using namespace std;

class Animal
{
public:
	int m_A;
};

class Sheep :virtual public Animal
{

};

class Camel :virtual public Animal
{

};

class SheepCamel :public Sheep, public Camel
{
public:
	int m_C;
};

void test()
{
	SheepCamel sc;
	sc.m_A = 1000;
}

int main()
{
	return 0;
}