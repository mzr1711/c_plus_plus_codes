#include <iostream>
using namespace std;

class MyPrint
{
public:
	void operator()(string str)
	{
		cout << str << endl;
	}
};

class MyAdd
{
public:
	int operator()(int a, int b)
	{
		return a + b;
	}
};

void test()
{
	MyPrint my_print;
	my_print("hello world!");
}

void test2()
{
	MyAdd my_add;
	cout << my_add(1, 2) << endl;
	cout << MyAdd()(100, 200) << endl;
}

int main()
{
	test();
	test2();
	return 0;
}